/*
 * ntp_restrict.c - determine host restrictions
 */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <sys/types.h>

#include "ntpd.h"
#include "ntp_if.h"
#include "ntp_lists.h"
#include "ntp_stdlib.h"
#include "ntp_assert.h"

/*
 * This code keeps a simple address-and-mask list of addressses we want
 * to place restrictions on (or remove them from). The restrictions are
 * implemented as a set of flags which tell you what matching addresses
 * can't do.  The list is sorted retrieve the restrictions most specific
*  to the address.
 *
 * This was originally intended to restrict you from sync'ing to your
 * own broadcasts when you are doing that, by restricting yourself from
 * your own interfaces. It was also thought it would sometimes be useful
 * to keep a misbehaving host or two from abusing your primary clock. It
 * has been expanded, however, to suit the needs of those with more
 * restrictive access policies.
 */
#define MASK_IPV6_ADDR(dst, src, msk)					\
	do {								\
		int x;							\
									\
		for (x = 0; x < (int)COUNTOF((dst)->s6_addr); x++) {	\
			(dst)->s6_addr[x] =   (src)->s6_addr[x]		\
					    & (msk)->s6_addr[x];	\
		}							\
	} while (FALSE)

/*
 * We allocate INC_RESLIST{4|6} entries to the free list whenever empty.
 * Auto-tune these to be just less than 1KB (leaving at least 32 bytes
 * for allocator overhead).
 */
#define	INC_RESLIST4	((1024 - 32) / V4_SIZEOF_RESTRICT_U)
#define	INC_RESLIST6	((1024 - 32) / V6_SIZEOF_RESTRICT_U)

/*
 * The restriction list
 */
restrict_u *restrictlist4;
restrict_u *restrictlist6;
static int restrictcount;	/* count in the restrict lists */

/*
 * The free list and associated counters.  Also some uninteresting
 * stat counters.
 */
static restrict_u *resfree4;	/* available entries (free list) */
static restrict_u *resfree6;

static u_long res_calls;
static u_long res_found;
static u_long res_not_found;

/*
 * Count number of restriction entries referring to RES_LIMITED, to
 * control implicit activation/deactivation of the MRU monlist.
 */
static	u_long res_limited_refcnt;

/*
 * Our default entries.
 *
 * We can make this cleaner with c99 support: see init_restrict().
 */
static	restrict_u	restrict_def4;
static	restrict_u	restrict_def6;

/*
 * "restrict source ..." enabled knob and restriction bits.
 */
static	int		restrict_source_enabled;
static	u_int32		restrict_source_rflags;
static	u_short		restrict_source_mflags;
static	short		restrict_source_ippeerlimit;

/*
 * private functions
 */
static	restrict_u *	alloc_res4(void);
static	restrict_u *	alloc_res6(void);
static	void		free_res(restrict_u *, int);
static	inline void	inc_res_limited(void);
static	inline void	dec_res_limited(void);
static	restrict_u *	match_restrict4_addr(u_int32, u_short);
static	restrict_u *	match_restrict6_addr(const struct in6_addr *,
					     u_short);
static	restrict_u *	match_restrict_entry(const restrict_u *, int);
static	int		res_sorts_before4(restrict_u *, restrict_u *);
static	int		res_sorts_before6(restrict_u *, restrict_u *);
	void		dump_restricts(void);

/*
 * dump_restrict - spit out a restrict_u
 */
static void
dump_restrict(
	restrict_u *	res,
	int		is_ipv6
	)
{
	char as[INET6_ADDRSTRLEN];
	char ms[INET6_ADDRSTRLEN];

	if (is_ipv6) {
		inet_ntop(AF_INET6, &res->u.v6.addr, as, sizeof as);
		inet_ntop(AF_INET6, &res->u.v6.mask, ms, sizeof ms);
	} else {
		struct in_addr	sia = { htonl(res->u.v4.addr) };
		struct in_addr	sim = { htonl(res->u.v4.mask) };

		inet_ntop(AF_INET, &sia, as, sizeof as);
		inet_ntop(AF_INET, &sim, ms, sizeof ms);
	}
	mprintf("restrict node at %p: %s/%s count %d, rflags %08x, mflags %04x, ippeerlimit %d, expire %lu, next %p\n",
		res, as, ms, res->count, res->rflags, res->mflags,
		res->ippeerlimit, res->expire, res->link);
	return;
}


/*
 * dump_restricts - spit out the 'restrict' lines
 */
void
dump_restricts(void)
{
	restrict_u *	res;
	restrict_u *	next;

	mprintf("dump_restrict: restrict_def4: %p\n", &restrict_def4);
	/* Spit out 'restrict {,-4,-6} default ...' lines, if needed */
	for (res = &restrict_def4; res != NULL; res = next) {
		dump_restrict(res, 0);
		next = res->link;
	}

	mprintf("dump_restrict: restrict_def6: %p\n", &restrict_def6);
	for (res = &restrict_def6; res != NULL; res = next) {
		dump_restrict(res, 1);
		next = res->link;
	}

	/* Spit out the IPv4 list */
	mprintf("dump_restrict: restrictlist4: %p\n", &restrictlist4);
	for (res = restrictlist4; res != NULL; res = next) {
		dump_restrict(res, 0);
		next = res->link;
	}

	/* Spit out the IPv6 list */
	mprintf("dump_restrict: restrictlist6: %p\n", &restrictlist6);
	for (res = restrictlist6; res != NULL; res = next) {
		dump_restrict(res, 1);
		next = res->link;
	}

	return;
}

/*
 * init_restrict - initialize the restriction data structures
 */
void
init_restrict(void)
{
	/*
	 * The restriction lists end with a default entry with address
	 * and mask 0, which will match any entry.  The lists are kept
	 * sorted by descending address followed by descending mask:
	 *
	 *   address	  mask
	 * 192.168.0.0	255.255.255.0	kod limited noquery nopeer
	 * 192.168.0.0	255.255.0.0	kod limited
	 * 0.0.0.0	0.0.0.0		kod limited noquery
	 *
	 * The first entry which matches an address is used.  With the
	 * example restrictions above, 192.168.0.0/24 matches the first
	 * entry, the rest of 192.168.0.0/16 matches the second, and
	 * everything else matches the third (default).
	 *
	 * Note this achieves the same result a little more efficiently
	 * than the documented behavior, which is to keep the lists
	 * sorted by ascending address followed by ascending mask, with
	 * the _last_ matching entry used.
	 *
	 * An additional wrinkle is we may have multiple entries with
	 * the same address and mask but differing match flags (mflags).
	 * At present there is only one, RESM_NTPONLY.  Entries with
	 * RESM_NTPONLY are sorted earlier so they take precedence over
	 * any otherwise similar entry without.  Again, this is the same
	 * behavior as but reversed implementation compared to the docs.
	 * 
	 */

	restrict_def4.ippeerlimit = -1;		/* Cleaner if we have C99 */
	restrict_def6.ippeerlimit = -1;		/* Cleaner if we have C99 */

	LINK_SLIST(restrictlist4, &restrict_def4, link);
	LINK_SLIST(restrictlist6, &restrict_def6, link);
	restrictcount = 2;
}


static restrict_u *
alloc_res4(void)
{
	const size_t	cb = V4_SIZEOF_RESTRICT_U;
	const size_t	count = INC_RESLIST4;
	restrict_u*	rl;
	restrict_u*	res;
	size_t		i;

	UNLINK_HEAD_SLIST(res, resfree4, link);
	if (res != NULL) {
		return res;
	}
	rl = eallocarray(count, cb);
	/* link all but the first onto free list */
	res = (void *)((char *)rl + (count - 1) * cb);
	for (i = count - 1; i > 0; i--) {
		LINK_SLIST(resfree4, res, link);
		res = (void *)((char *)res - cb);
	}
	DEBUG_INSIST(rl == res);
	/* allocate the first */
	return res;
}


static restrict_u *
alloc_res6(void)
{
	const size_t	cb = V6_SIZEOF_RESTRICT_U;
	const size_t	count = INC_RESLIST6;
	restrict_u *	rl;
	restrict_u *	res;
	size_t		i;

	UNLINK_HEAD_SLIST(res, resfree6, link);
	if (res != NULL) {
		return res;
	}
	rl = eallocarray(count, cb);
	/* link all but the first onto free list */
	res = (void *)((char *)rl + (count - 1) * cb);
	for (i = count - 1; i > 0; i--) {
		LINK_SLIST(resfree6, res, link);
		res = (void *)((char *)res - cb);
	}
	DEBUG_INSIST(rl == res);
	/* allocate the first */
	return res;
}


static void
free_res(
	restrict_u *	res,
	int		v6
	)
{
	restrict_u **	rlisthead_ptr;
	restrict_u **	flisthead_ptr;
	restrict_u *	unlinked;
	size_t		sz;

	restrictcount--;
	if (RES_LIMITED & res->rflags) {
		dec_res_limited();
	}
	if (v6) {
		rlisthead_ptr = &restrictlist6;
		flisthead_ptr = &resfree6;
		sz = V6_SIZEOF_RESTRICT_U;
	} else {
		rlisthead_ptr = &restrictlist4;
		flisthead_ptr = &resfree4;
		sz = V4_SIZEOF_RESTRICT_U;
	}
	UNLINK_SLIST(unlinked, *rlisthead_ptr, res, link, restrict_u);
	INSIST(unlinked == res);
	zero_mem(res, sz);
	LINK_SLIST(*flisthead_ptr, res, link);
}


static inline void
inc_res_limited(void)
{
	if (0 == res_limited_refcnt) {
		mon_start(MON_RES);
	}
	res_limited_refcnt++;
}


static inline void
dec_res_limited(void)
{
	res_limited_refcnt--;
	if (0 == res_limited_refcnt) {
		mon_stop(MON_RES);
	}
}


static restrict_u *
match_restrict4_addr(
	u_int32	addr,
	u_short	port
	)
{
	const int	v6 = FALSE;
	restrict_u *	res;
	restrict_u *	next;

	for (res = restrictlist4; res != NULL; res = next) {
		next = res->link;
		if (res->expire && res->expire <= current_time) {
			free_res(res, v6);	/* zeroes the contents */
		}
		if (   res->u.v4.addr == (addr & res->u.v4.mask)
		    && (   !(RESM_NTPONLY & res->mflags)
			|| NTP_PORT == port)) {

			break;
		}
	}
	return res;
}


static restrict_u *
match_restrict6_addr(
	const struct in6_addr *	addr,
	u_short			port
	)
{
	const int	v6 = TRUE;
	restrict_u *	res;
	restrict_u *	next;
	struct in6_addr	masked;

	for (res = restrictlist6; res != NULL; res = next) {
		next = res->link;
		if (res->expire && res->expire <= current_time) {
			free_res(res, v6);
		}
		MASK_IPV6_ADDR(&masked, addr, &res->u.v6.mask);
		if (ADDR6_EQ(&masked, &res->u.v6.addr)
		    && (   !(RESM_NTPONLY & res->mflags)
			|| NTP_PORT == (int)port)) {

			break;
		}
	}
	return res;
}


/*
 * match_restrict_entry - find an exact match on a restrict list.
 *
 * Exact match is addr, mask, and mflags all equal.
 * In order to use more common code for IPv4 and IPv6, this routine
 * requires the caller to populate a restrict_u with mflags and either
 * the v4 or v6 address and mask as appropriate.  Other fields in the
 * input restrict_u are ignored.
 */
static restrict_u *
match_restrict_entry(
	const restrict_u *	pmatch,
	int			v6
	)
{
	restrict_u *res;
	restrict_u *rlist;
	size_t cb;

	if (v6) {
		rlist = restrictlist6;
		cb = sizeof(pmatch->u.v6);
	} else {
		rlist = restrictlist4;
		cb = sizeof(pmatch->u.v4);
	}

	for (res = rlist; res != NULL; res = res->link)
		if (res->mflags == pmatch->mflags &&
		    !memcmp(&res->u, &pmatch->u, cb))
			break;
	return res;
}


/*
 * res_sorts_before4 - compare two restrict4 entries
 *
 * Returns nonzero if r1 sorts before r2.  We sort by descending
 * address, then descending mask, then descending mflags, so sorting
 * before means having a higher value.
 */
static int
res_sorts_before4(
	restrict_u *r1,
	restrict_u *r2
	)
{
	int r1_before_r2;

	if (r1->u.v4.addr > r2->u.v4.addr)
		r1_before_r2 = 1;
	else if (r1->u.v4.addr < r2->u.v4.addr)
		r1_before_r2 = 0;
	else if (r1->u.v4.mask > r2->u.v4.mask)
		r1_before_r2 = 1;
	else if (r1->u.v4.mask < r2->u.v4.mask)
		r1_before_r2 = 0;
	else if (r1->mflags > r2->mflags)
		r1_before_r2 = 1;
	else
		r1_before_r2 = 0;

	return r1_before_r2;
}


/*
 * res_sorts_before6 - compare two restrict6 entries
 *
 * Returns nonzero if r1 sorts before r2.  We sort by descending
 * address, then descending mask, then descending mflags, so sorting
 * before means having a higher value.
 */
static int
res_sorts_before6(
	restrict_u *r1,
	restrict_u *r2
	)
{
	int r1_before_r2;
	int cmp;

	cmp = ADDR6_CMP(&r1->u.v6.addr, &r2->u.v6.addr);
	if (cmp > 0)		/* r1->addr > r2->addr */
		r1_before_r2 = 1;
	else if (cmp < 0)	/* r2->addr > r1->addr */
		r1_before_r2 = 0;
	else {
		cmp = ADDR6_CMP(&r1->u.v6.mask, &r2->u.v6.mask);
		if (cmp > 0)		/* r1->mask > r2->mask*/
			r1_before_r2 = 1;
		else if (cmp < 0)	/* r2->mask > r1->mask */
			r1_before_r2 = 0;
		else if (r1->mflags > r2->mflags)
			r1_before_r2 = 1;
		else
			r1_before_r2 = 0;
	}

	return r1_before_r2;
}


/*
 * restrictions - return restrictions for this host in *r4a
 */
void
restrictions(
	sockaddr_u *srcadr,
	r4addr *r4a
	)
{
	restrict_u *match;
	struct in6_addr *pin6;

	DEBUG_REQUIRE(NULL != r4a);

	res_calls++;

	if (IS_IPV4(srcadr)) {
		/*
		 * Ignore any packets with a multicast source address
		 * (this should be done early in the receive process,
		 * not later!)
		 */
		if (IN_CLASSD(SRCADR(srcadr))) {
			goto multicast;
		}

		match = match_restrict4_addr(SRCADR(srcadr),
					     SRCPORT(srcadr));
		DEBUG_INSIST(match != NULL);
		match->count++;
		/*
		 * res_not_found counts only use of the final default
		 * entry, not any "restrict default ntpport ...", which
		 * would be just before the final default.
		 */
		if (&restrict_def4 == match)
			res_not_found++;
		else
			res_found++;
		r4a->rflags = match->rflags;
		r4a->ippeerlimit = match->ippeerlimit;
	} else {
		DEBUG_REQUIRE(IS_IPV6(srcadr));

		pin6 = PSOCK_ADDR6(srcadr);

		/*
		 * Ignore any packets with a multicast source address
		 * (this should be done early in the receive process,
		 * not later!)
		 */
		if (IN6_IS_ADDR_MULTICAST(pin6)) {
			goto multicast;
		}
		match = match_restrict6_addr(pin6, SRCPORT(srcadr));
		DEBUG_INSIST(match != NULL);
		match->count++;
		if (&restrict_def6 == match)
			res_not_found++;
		else
			res_found++;
		r4a->rflags = match->rflags;
		r4a->ippeerlimit = match->ippeerlimit;
	}

	return;

    multicast:
	r4a->rflags = RES_IGNORE;
	r4a->ippeerlimit = 0;
}


#ifdef DEBUG
/* display string for restrict_op */
const char *
resop_str(restrict_op op)
{
	switch (op) {
	    case RESTRICT_FLAGS:	return "RESTRICT_FLAGS";
	    case RESTRICT_UNFLAG:	return "RESTRICT_UNFLAGS";
	    case RESTRICT_REMOVE:	return "RESTRICT_REMOVE";
	    case RESTRICT_REMOVEIF:	return "RESTRICT_REMOVEIF";
	}
	DEBUG_INVARIANT(!"bad restrict_op in resop_str");
	return "";	/* silence not all paths return value warning */
}
#endif	/* DEBUG */


/*
 * hack_restrict - add/subtract/manipulate entries on the restrict list
 */
void
hack_restrict(
	restrict_op	op,
	sockaddr_u *	resaddr,
	sockaddr_u *	resmask,
	short		ippeerlimit,
	u_short		mflags,
	u_short		rflags,
	u_long		expire
	)
{
	int		v6;
	int		bump_res_limited = FALSE;
	restrict_u	match;
	restrict_u *	res;
	restrict_u **	plisthead;

	DPRINTF(1, ("hack_restrict: op %s addr %s mask %s ippeerlimit %d "
		    "mflags %s rflags %s\n", resop_str(op), stoa(resaddr),
		    stoa(resmask), ippeerlimit, mflags_str(mflags),
		    rflags_str(rflags)));

	if (NULL == resaddr) {
		DEBUG_REQUIRE(NULL == resmask);
		DEBUG_REQUIRE(RESTRICT_FLAGS == op);
		restrict_source_rflags = rflags;
		restrict_source_mflags = mflags;
		restrict_source_ippeerlimit = ippeerlimit;
		restrict_source_enabled = TRUE;
		return;
	}

	ZERO(match);

	if (IS_IPV4(resaddr)) {
		v6 = FALSE;
		/*
		 * Get address and mask in host byte order for easy
		 * comparison as u_int32
		 */
		match.u.v4.addr = SRCADR(resaddr);
		match.u.v4.mask = SRCADR(resmask);
		match.u.v4.addr &= match.u.v4.mask;
	} else {
		DEBUG_INVARIANT(IS_IPV6(resaddr));
		v6 = TRUE;
		/*
		 * Get address and mask in network byte order for easy
		 * comparison as byte sequences (e.g. memcmp())
		 */
		match.u.v6.mask = SOCK_ADDR6(resmask);
		MASK_IPV6_ADDR(&match.u.v6.addr, PSOCK_ADDR6(resaddr),
			       &match.u.v6.mask);
	}

	match.mflags = mflags;
	res = match_restrict_entry(&match, v6);

	switch (op) {

	case RESTRICT_FLAGS:
		/*
		 * Here we add bits to the rflags. If we already have
		 * this restriction modify it.
		 */
		if (NULL != res) {
			if ((RES_LIMITED & rflags)
				&& !(RES_LIMITED & res->rflags)) {

				bump_res_limited = TRUE;
			}
			res->rflags |= rflags;
		} else {
			match.rflags = rflags;
			match.expire = expire;
			match.ippeerlimit = ippeerlimit;
			if (v6) {
				res = alloc_res6();
				memcpy(res, &match, V6_SIZEOF_RESTRICT_U);
				plisthead = &restrictlist6;
			} else {
				res = alloc_res4();
				memcpy(res, &match, V4_SIZEOF_RESTRICT_U);
				plisthead = &restrictlist4;
			}
			LINK_SORT_SLIST(
				*plisthead, res,
				(v6)
				  ? res_sorts_before6(res, L_S_S_CUR())
				  : res_sorts_before4(res, L_S_S_CUR()),
				link, restrict_u);
			restrictcount++;
			if (RES_LIMITED & rflags) {
				bump_res_limited = TRUE;
			}
		}
		if (bump_res_limited) {
			inc_res_limited();
		}
		break;

	case RESTRICT_UNFLAG:
		/*
		 * Remove some bits from the rflags. If we didn't
		 * find this one, just return.
		 */
		if (res != NULL) {
			if (   (RES_LIMITED & res->rflags)
			    && (RES_LIMITED & rflags))
				dec_res_limited();
			res->rflags &= ~rflags;
		}
		break;

	case RESTRICT_REMOVE:
	case RESTRICT_REMOVEIF:
		/*
		 * Remove an entry from the table entirely if we
		 * found one. Don't remove the default entry and
		 * don't remove an interface entry unless asked.
		 */
		if (   res != NULL
		    && (RESTRICT_REMOVEIF == op
			|| !(RESM_INTERFACE & res->mflags))
		    && res != &restrict_def4
		    && res != &restrict_def6) {

			free_res(res, v6);
		}
		break;

	default:	/* unknown op */
		INSIST(0);
		break;
	}

}


/*
 * restrict_source - maintains dynamic "restrict source ..." entries as
 *		     peers come and go.
 */
void
restrict_source(
	sockaddr_u *	addr,
	int		farewell,	/* 0 to add, 1 to remove */
	u_long		expire		/* 0 is infinite, valid until */
	)
{
	sockaddr_u	onesmask;
	restrict_u *	res;
	int		found_specific;

	if (!restrict_source_enabled || SOCK_UNSPEC(addr) ||
	    IS_MCAST(addr) || ISREFCLOCKADR(addr))
		return;

	REQUIRE(AF_INET == AF(addr) || AF_INET6 == AF(addr));

	SET_HOSTMASK(&onesmask, AF(addr));
	if (farewell) {
		hack_restrict(RESTRICT_REMOVE, addr, &onesmask,
			      -2, 0, 0, 0);
		DPRINTF(1, ("restrict_source: %s removed", stoa(addr)));
		return;
	}

	/*
	 * If there is a specific entry for this address, hands
	 * off, as it is condidered more specific than "restrict
	 * server ...".
	 * However, if the specific entry found is a fleeting one
	 * added by pool_xmit() before soliciting, replace it
	 * immediately regardless of the expire value to make way
	 * for the more persistent entry.
	 */
	if (IS_IPV4(addr)) {
		res = match_restrict4_addr(SRCADR(addr), SRCPORT(addr));
		INSIST(res != NULL);
		found_specific = (SRCADR(&onesmask) == res->u.v4.mask);
	} else {
		res = match_restrict6_addr(&SOCK_ADDR6(addr),
					   SRCPORT(addr));
		INSIST(res != NULL);
		found_specific = ADDR6_EQ(&res->u.v6.mask,
					  &SOCK_ADDR6(&onesmask));
	}
	if (!expire && found_specific && res->expire) {
		found_specific = 0;
		free_res(res, IS_IPV6(addr));
	}
	if (found_specific)
		return;

	hack_restrict(RESTRICT_FLAGS, addr, &onesmask,
		      restrict_source_ippeerlimit, 
		      restrict_source_mflags, restrict_source_rflags, expire);
	DPRINTF(1, ("restrict_source: %s host restriction added\n", 
		    stoa(addr)));
}


#ifdef DEBUG
/* Convert restriction RES_ flag bits into a display string */
const char *
rflags_str(
	u_short rflags
	)
{
	const size_t	sz = LIB_BUFLENGTH;
	char *		rfs;

	LIB_GETBUF(rfs);
	rfs[0] = '\0';

	if (rflags & RES_FLAKE) {
		CLEAR_BIT_IF_DEBUG(RES_FLAKE, rflags);
		append_flagstr(rfs, sz, "flake");
	}

	if (rflags & RES_IGNORE) {
		CLEAR_BIT_IF_DEBUG(RES_IGNORE, rflags);
		append_flagstr(rfs, sz, "ignore");
	}

	if (rflags & RES_KOD) {
		CLEAR_BIT_IF_DEBUG(RES_KOD, rflags);
		append_flagstr(rfs, sz, "kod");
	}

	if (rflags & RES_MSSNTP) {
		CLEAR_BIT_IF_DEBUG(RES_MSSNTP, rflags);
		append_flagstr(rfs, sz, "mssntp");
	}

	if (rflags & RES_LIMITED) {
		CLEAR_BIT_IF_DEBUG(RES_LIMITED, rflags);
		append_flagstr(rfs, sz, "limited");
	}

	if (rflags & RES_LPTRAP) {
		CLEAR_BIT_IF_DEBUG(RES_LPTRAP, rflags);
		append_flagstr(rfs, sz, "lptrap");
	}

	if (rflags & RES_NOMODIFY) {
		CLEAR_BIT_IF_DEBUG(RES_NOMODIFY, rflags);
		append_flagstr(rfs, sz, "nomodify");
	}

	if (rflags & RES_NOMRULIST) {
		CLEAR_BIT_IF_DEBUG(RES_NOMRULIST, rflags);
		append_flagstr(rfs, sz, "nomrulist");
	}

	if (rflags & RES_NOEPEER) {
		CLEAR_BIT_IF_DEBUG(RES_NOEPEER, rflags);
		append_flagstr(rfs, sz, "noepeer");
	}

	if (rflags & RES_NOPEER) {
		CLEAR_BIT_IF_DEBUG(RES_NOPEER, rflags);
		append_flagstr(rfs, sz, "nopeer");
	}

	if (rflags & RES_NOQUERY) {
		CLEAR_BIT_IF_DEBUG(RES_NOQUERY, rflags);
		append_flagstr(rfs, sz, "noquery");
	}

	if (rflags & RES_DONTSERVE) {
		CLEAR_BIT_IF_DEBUG(RES_DONTSERVE, rflags);
		append_flagstr(rfs, sz, "dontserve");
	}

	if (rflags & RES_NOTRAP) {
		CLEAR_BIT_IF_DEBUG(RES_NOTRAP, rflags);
		append_flagstr(rfs, sz, "notrap");
	}

	if (rflags & RES_DONTTRUST) {
		CLEAR_BIT_IF_DEBUG(RES_DONTTRUST, rflags);
		append_flagstr(rfs, sz, "notrust");
	}

	if (rflags & RES_SRVRSPFUZ) {
		CLEAR_BIT_IF_DEBUG(RES_SRVRSPFUZ, rflags);
		append_flagstr(rfs, sz, "srvrspfuz");
	}

	if (rflags & RES_VERSION) {
		CLEAR_BIT_IF_DEBUG(RES_VERSION, rflags);
		append_flagstr(rfs, sz, "version");
	}

	DEBUG_INVARIANT(!rflags);

	if ('\0' == rfs[0]) {
		append_flagstr(rfs, sz, "(none)");
	}

	return rfs;
}


/* Convert restriction match RESM_ flag bits into a display string */
const char *
mflags_str(
	u_short mflags
	)
{
	const size_t	sz = LIB_BUFLENGTH;
	char *		mfs;

	LIB_GETBUF(mfs);
	mfs[0] = '\0';

	if (mflags & RESM_NTPONLY) {
		CLEAR_BIT_IF_DEBUG(RESM_NTPONLY, mflags);
		append_flagstr(mfs, sz, "ntponly");
	}

	if (mflags & RESM_SOURCE) {
		CLEAR_BIT_IF_DEBUG(RESM_SOURCE, mflags);
		append_flagstr(mfs, sz, "source");
	}

	if (mflags & RESM_INTERFACE) {
		CLEAR_BIT_IF_DEBUG(RESM_INTERFACE, mflags);
		append_flagstr(mfs, sz, "interface");
	}

	DEBUG_INVARIANT(!mflags);

	return mfs;
}
#endif	/* DEBUG */
