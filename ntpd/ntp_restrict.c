/*
 * ntp_restrict.c - find out what restrictions this host is running under
 */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <sys/types.h>

#include "ntpd.h"
#include "ntp_if.h"
#include "ntp_stdlib.h"

/*
 * This code keeps a simple address-and-mask list of hosts we want
 * to place restrictions on (or remove them from).  The restrictions
 * are implemented as a set of flags which tell you what the host
 * can't do.  There is a subroutine entry to return the flags.  The
 * list is kept sorted to reduce the average number of comparisons
 * and make sure you get the set of restrictions most specific to
 * the address.
 *
 * The algorithm is that, when looking up a host, it is first assumed
 * that the default set of restrictions will apply.  It then searches
 * down through the list.  Whenever it finds a match it adopts the match's
 * flags instead.  When you hit the point where the sorted address is
 * greater than the target, you return with the last set of flags you
 * found.  Because of the ordering of the list, the most specific match
 * will provide the final set of flags.
 *
 * This was originally intended to restrict you from sync'ing to your
 * own broadcasts when you are doing that, by restricting yourself
 * from your own interfaces.  It was also thought it would sometimes
 * be useful to keep a misbehaving host or two from abusing your primary
 * clock.  It has been expanded, however, to suit the needs of those
 * with more restrictive access policies.
 */

/*
  * We will use two lists, one for IPv4 addresses and one for IPv6
  * addresses. This is not protocol-independant but for now I can't
  * find way to respect this. We'll check this later... JFB 07/2001
 */

/*
 * Memory allocation parameters.  We allocate INITRESLIST entries
 * initially, and add INCRESLIST entries to the free list whenever
 * we run out.
 */
#define	INITRESLIST	10
#define	INCRESLIST	5

/*
 * The restriction list
 */
struct restrictlist *restrictlist;
struct restrictlist6 *restrictlist6;
static	int restrictcount;	/* count of entries in the restriction list */
static	int restrictcount6;	/* count of entries in the restriction list 2*/

/*
 * The free list and associated counters.  Also some uninteresting
 * stat counters.
 */
static	struct restrictlist *resfree;
static	struct restrictlist6 *resfree6;
static	int numresfree;		/* number of structures on free list */
static	int numresfree6;	/* number of structures on free list 2 */

static	u_long res_calls;
static	u_long res_found;
static	u_long res_not_found;
/* static	u_long res_timereset; */

/*
 * Parameters of the RES_LIMITED restriction option.
 * client_limit is the number of hosts allowed per source net
 * client_limit_period is the number of seconds after which an entry
 * is no longer considered for client limit determination
 */
u_long client_limit;
u_long client_limit_period;
/*
 * count number of restriction entries referring to RES_LIMITED
 * controls activation/deactivation of monitoring
 * (with respect to RES_LIMITED control)
 */
static	u_long res_limited_refcnt;
static	u_long res_limited_refcnt6;

/*
 * Our initial allocation of lists entries.
 */
static	struct restrictlist resinit[INITRESLIST];
static	struct restrictlist6 resinit6[INITRESLIST];

/*
 * init_restrict - initialize the restriction data structures
 */
void
init_restrict(void)
{
	register int i;
	char bp[80];

	/*
	 * Zero the list and put all but one on the free list
	 */
	resfree = 0;
	memset((char *)resinit, 0, sizeof resinit);
	resfree6 = 0;
	memset((char *)resinit6, 0, sizeof resinit6);

	for (i = 1; i < INITRESLIST; i++) {
		resinit[i].next = resfree;
                resinit6[i].next = resfree6;
		resfree = &resinit[i];
                resfree6 = &resinit6[i];
	}

	numresfree = INITRESLIST-1;
        numresfree6 = INITRESLIST-1;

	/*
	 * Put the remaining item at the head of the
	 * list as our default entry.  Everything in here
	 * should be zero for now.
	 */
	resinit[0].addr = htonl(INADDR_ANY);
	resinit[0].mask = 0;
       memset(&resinit6[0].addr6, 0, sizeof(resinit6[0].addr6));
	restrictlist = &resinit[0];
	restrictlist6 = &resinit6[0];
	restrictcount = 1;
        restrictcount = 2;

	/*
	 * fix up stat counters
	 */
	res_calls = 0;
	res_found = 0;
	res_not_found = 0;
	/* res_timereset = 0; */

	/*
	 * set default values for RES_LIMIT functionality
	 */
	client_limit = 3;
	client_limit_period = 3600;
	res_limited_refcnt = 0;
	res_limited_refcnt6 = 0;

	sprintf(bp, "client_limit=%ld", client_limit);
	set_sys_var(bp, strlen(bp)+1, RO);
	sprintf(bp, "client_limit_period=%ld", client_limit_period);
	set_sys_var(bp, strlen(bp)+1, RO);
}


/*
 * restrictions - return restrictions for this host
 */
int
restrictions(
	struct sockaddr_storage *srcadr
	)
{
	struct restrictlist *rl;
	struct restrictlist *match = NULL;
	struct restrictlist6 *rl6;
	struct restrictlist6 *match6 = NULL;
	int flags = 0;
	u_int32 hostaddr;
      	struct in6_addr hostaddr6;
       struct in6_addr hostservaddr6;

	 int isntpport;
        struct sockaddr_storage *netsrcaddr;
        struct sockaddr_storage *mdnet;

	res_calls++;

        netsrcaddr = netof(srcadr);

       /* IPv4 source address */
       if(srcadr->ss_family == AF_INET) {
	/*
	 * We need the host address in host order.  Also need to know
	 * whether this is from the ntp port or not.
	 */
        	hostaddr = SRCADR((struct sockaddr_in*)srcadr);
        	isntpport = (SRCPORT((struct sockaddr_in*)srcadr) == NTP_PORT);

	/*
	 * Ignore any packets with a multicast source address
	 * (this should be done early in the receive process, later!)
	 */
	        if (IN_CLASSD(ntohl(((struct sockaddr_in*)srcadr)->sin_addr.s_addr)))
	    return (int)RES_IGNORE;

	/*
	 * Set match to first entry, which is default entry.  Work our
	 * way down from there.
	 */
	match = restrictlist;

	for (rl = match->next; rl != 0 && rl->addr <= hostaddr; rl = rl->next)
	    if ((hostaddr & rl->mask) == rl->addr) {
		    if ((rl->mflags & RESM_NTPONLY) && !isntpport)
			continue;
		    match = rl;
	    }

	match->count++;
	if (match == restrictlist)
	    res_not_found++;
	else
	    res_found++;
		flags = match->flags;

        }

        /* IPv6 source address */
       if(srcadr->ss_family == AF_INET6) {
                /*
	        * We need the host address in host order.  Also need to know
	        * whether this is from the ntp port or not.
	        */
               hostaddr6 = ((struct sockaddr_in6*)srcadr)->sin6_addr;
        	 isntpport = ((((struct sockaddr_in6*)srcadr)->sin6_port) == NTP_PORT);

	        /*
	        * Ignore any packets with a multicast source address
	        * (this should be done early in the receive process, later!)
	        */
	        if (IN6_IS_ADDR_MULTICAST(&((struct sockaddr_in6*)srcadr)->sin6_addr))
	        return (int)RES_IGNORE;

	        /*
	        * Set match to first entry, which is default entry.  Work our
	        * way down from there.
	        */
	        match6 = restrictlist6;
	        for (rl6 = match6->next; rl6 != 0 && memcmp(&(rl6->addr6), &hostaddr6, sizeof(hostaddr6)); rl6 = rl6->next) {
                    /*
                     * We get the host server address by applying manually a mask to the address.
                     * See RFC xxxx for explaination on the Aggregatable Global Unicast Address Format.
                     */
		      hostservaddr6 = hostaddr6;
	      	     memset(&hostservaddr6 + 12*sizeof(u_char), 0, 4*sizeof(u_char));
                   if (memcmp(&hostservaddr6, &(rl6->addr6), sizeof(hostservaddr6))) 
        		    if ((rl6->mflags & RESM_NTPONLY) && !isntpport)
                                continue;
		      match6 = rl6;
	        }
		      	match6->count++;
			if (match6 == restrictlist6)
			    res_not_found++;
			else
			    res_found++;
		flags = match6->flags;
      }
	
	/*
	 * The following implements limiting the number of clients
	 * accepted from a given network. The notion of "same network"
	 * is determined by the mask and addr fields of the restrict
	 * list entry. The monitor mechanism has to be enabled for
	 * collecting info on current clients.
	 *
	 * The policy is as follows:
	 *	- take the list of clients recorded
	 *        from the given "network" seen within the last
	 *        client_limit_period seconds
	 *      - if there are at most client_limit entries: 
	 *        --> access allowed
	 *      - otherwise sort by time first seen
	 *      - current client among the first client_limit seen
	 *        hosts?
	 *        if yes: access allowed
	 *        else:   eccess denied
	 */
	if (flags & RES_LIMITED) {
		int lcnt;
		struct mon_data *md, *this_client;

#ifdef DEBUG
		if (debug > 2)
		    printf("limited clients check: %ld clients, period %ld seconds, net is %s\n",
			   client_limit, client_limit_period,
			   stoa(netsrcaddr));
#endif /*DEBUG*/
		if (mon_enabled == MON_OFF) {
#ifdef DEBUG
			if (debug > 4)
			    printf("no limit - monitoring is off\n");
#endif
			return (int)(match->flags & ~RES_LIMITED);
		}

		/*
		 * How nice, MRU list provides our current client as the
		 * first entry in the list.
		 * Monitoring was verified to be active above, thus we
		 * know an entry for our client must exist, or some 
		 * brain dead set the memory limit for mon entries to ZERO!!!
		 */
		this_client = mon_mru_list.mru_next;

		for (md = mon_fifo_list.fifo_next,lcnt = 0;
		     md != &mon_fifo_list;
		     md = md->fifo_next) {
			    mdnet = netof(&(md->rmtadr));
			if ((current_time - md->lasttime)
			    > client_limit_period) {
#ifdef DEBUG
				if (debug > 5)
				    printf("checking: %s: ignore: too old: %ld\n",
					   stoa(&(md->rmtadr)),
					   current_time - md->lasttime);
#endif
				continue;
			}
			if (md->mode == MODE_BROADCAST ||
			    md->mode == MODE_CONTROL ||
			    md->mode == MODE_PRIVATE) {
#ifdef DEBUG
				if (debug > 5)
				    printf("checking: %s: ignore mode %d\n",
					   stoa(&(md->rmtadr)),
					   md->mode);
#endif
				continue;
			}
			if (!SOCKCMP(mdnet, &netsrcaddr)) {
#ifdef DEBUG
				if (debug > 5) {
					printf("checking: %s: different net %s\n",
				   stoa(&(md->rmtadr)),
	  			 stoa(mdnet));
				}
#endif
				continue;
			}
			lcnt++;
			if (lcnt >  (int) client_limit ||
			       SOCKCMP(&(md->rmtadr), srcadr)) {
#ifdef DEBUG
				if (debug > 5)
				    printf("considering %s: found host\n",
					   stoa(&(md->rmtadr)));
#endif
				break;
			}
#ifdef DEBUG
			else {
				if (debug > 5)
				    printf("considering %s: same net\n",
					   stoa(&(md->rmtadr)));
			}
#endif
		} /* for */
#ifdef DEBUG
		if (debug > 4)
		    printf("this one is rank %d in list, limit is %lu: %s\n",
			   lcnt, client_limit,
			   (lcnt <= (int) client_limit) ? "ALLOW" : "REJECT");
#endif
		if (lcnt <= (int) client_limit) {
			this_client->lastdrop = 0;
		       if(srcadr->ss_family == AF_INET) 
			return (int)(match->flags & ~RES_LIMITED);
			else
				return (int)(match6->flags & ~RES_LIMITED);
				
		} else {
			this_client->lastdrop = current_time;
		}
	}
	return flags;
}


/*
 * hack_restrict - add/subtract/manipulate entries on the restrict list
 */
void
hack_restrict(
	int op,
	struct sockaddr_storage *resaddr,
	struct sockaddr_storage *resmask,
	int mflags,
	int flags
	)
{
	register u_int32 addr = 0;
	register u_int32 mask = 0;
       uint8_t addr6[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	register struct restrictlist *rl = NULL;
	register struct restrictlist *rlprev = NULL;
       register struct restrictlist6 *rl6 = NULL;
	register struct restrictlist6 *rlprev6 = NULL;
	int i;

	/*
	 * Get address and mask in host byte order
	 */
        if(resaddr->ss_family == AF_INET) {
	addr = SRCADR(resaddr);
	mask = SRCADR(resmask);
	addr &= mask;		/* make sure low bits are zero */
         }
         else if(resaddr->ss_family == AF_INET6) {
                memcpy(&addr6, (&((struct sockaddr_in6*)resaddr)->sin6_addr), sizeof(addr6));
	        memset(&addr6 + 8*sizeof(uint8_t), 0, 8*sizeof(uint8_t)); /* make sure low bits are zero */
         }

	/*
	 * If this is the default address, point at first on list.  Else
	 * go searching for it.
	 */
        if(resaddr->ss_family == AF_INET)
        {
                if (addr == 0) {
		rlprev = 0;
		rl = restrictlist;
	} else {
		rlprev = restrictlist;
		rl = rlprev->next;
		while (rl != 0) {
			if (rl->addr > addr) {
				rl = 0;
				break;
			} else if (rl->addr == addr) {
				if (rl->mask == mask) {
					if ((mflags & RESM_NTPONLY)
					    == (rl->mflags & RESM_NTPONLY))
					    break;	/* exact match */
					if (!(mflags & RESM_NTPONLY)) {
						/*
						 * No flag fits before flag
						 */
						rl = 0;
						break;
					}
					/* continue on */
				} else if (rl->mask > mask) {
					rl = 0;
					break;
				}
			}
			rlprev = rl;
			rl = rl->next;
		}
	}
        }

        if(resaddr->ss_family == AF_INET6)
        {
                if (IN6_IS_ADDR_UNSPECIFIED((struct in6_addr*)&addr6)) {
        		rlprev6 = 0;
		       rl6 = restrictlist6;
	        } else {
        		rlprev6 = restrictlist6;
	        	rl6 = rlprev6->next;
        		while (rl6 != 0) {
			        if (memcmp(&(rl6->addr6), &addr6, sizeof(addr6)) > 0) {
        				rl6 = 0;
	        			break;
		        	} else if (memcmp(&(rl6->addr6), &addr6, sizeof(addr6)) == 0) {
			        	        if ((mflags & RESM_NTPONLY)
                				    == (rl6->mflags & RESM_NTPONLY))
		        			    break;	/* exact match */
					        if (!(mflags & RESM_NTPONLY)) {
        						/*
	        					 * No flag fits before flag
		        				 */
			        			rl6 = 0;
				        		break;
					        }
					        /* continue on */
				        }
			        rlprev6 = rl6;
			        rl6 = rl6->next;
		        }
	        }
        }

	/*
	 * In case the above wasn't clear :-), either rl now points
	 * at the entry this call refers to, or rl is zero and rlprev
	 * points to the entry prior to where this one should go in
	 * the sort.
	 */

	/*
	 * Switch based on operation
	 */
        if(resaddr->ss_family == AF_INET)
        {
	switch (op) {
	    case RESTRICT_FLAGS:
		/*
		 * Here we add bits to the flags.  If this is a new
		 * restriction add it.
		 */
		if (rl == 0) {
			if (numresfree == 0) {
				rl = (struct restrictlist *) emalloc(
					INCRESLIST*sizeof(struct restrictlist));
				memset((char *)rl, 0,
				       INCRESLIST*sizeof(struct restrictlist));

				for (i = 0; i < INCRESLIST; i++) {
					rl->next = resfree;
					resfree = rl;
					rl++;
				}
				numresfree = INCRESLIST;
			}

			rl = resfree;
			resfree = rl->next;
			numresfree--;

			rl->addr = addr;
			rl->mask = mask;
			rl->mflags = (u_short)mflags;

			rl->next = rlprev->next;
			rlprev->next = rl;
			restrictcount++;
		}
		if ((rl->flags ^ (u_short)flags) & RES_LIMITED) {
			res_limited_refcnt++;
			mon_start(MON_RES); /* ensure data gets collected */
		}
		rl->flags |= (u_short)flags;
		break;
	
	    case RESTRICT_UNFLAG:
		/*
		 * Remove some bits from the flags.  If we didn't
		 * find this one, just return.
		 */
		if (rl != 0) {
			if ((rl->flags ^ (u_short)flags) & RES_LIMITED) {
				res_limited_refcnt--;
				if (res_limited_refcnt == 0)
				    mon_stop(MON_RES);
			}
			rl->flags &= (u_short)~flags;
		}
		break;
	
	    case RESTRICT_REMOVE:
		/*
		 * Remove an entry from the table entirely if we found one.
		 * Don't remove the default entry and don't remove an
		 * interface entry.
		 */
		if (rl != 0
		    && rl->addr != htonl(INADDR_ANY)
		    && !(rl->mflags & RESM_INTERFACE)) {
			rlprev->next = rl->next;
			restrictcount--;
			if (rl->flags & RES_LIMITED) {
				res_limited_refcnt--;
				if (res_limited_refcnt == 0)
				    mon_stop(MON_RES);
			}
			memset((char *)rl, 0, sizeof(struct restrictlist));

			rl->next = resfree;
			resfree = rl;
			numresfree++;
		}
		break;

	    default:
		/* Oh, well */
		break;
	}
       }

       else if(resaddr->ss_family == AF_INET6)
        {
                switch (op) {
                case RESTRICT_FLAGS:
		/*
		 * Here we add bits to the flags.  If this is a new
		 * restriction add it.
		 */
                        if (rl6 == 0) {
			        if (numresfree6 == 0) {
        				rl6 = (struct restrictlist6 *) emalloc(
	        				INCRESLIST*sizeof(struct restrictlist6));
		        		memset((char *)rl6, 0,
			        	       INCRESLIST*sizeof(struct restrictlist6));

        				for (i = 0; i < INCRESLIST; i++) {
	        				rl6->next = resfree6;
		        			resfree6 = rl6;
			        		rl6++;
				        }
				        numresfree6 = INCRESLIST;
			        }

			        rl6 = resfree6;
			        resfree6 = rl6->next;
			        numresfree6--;

        			memcpy(&(rl6->addr6), &addr6, sizeof(addr6));
	        		rl6->mflags = (u_short)mflags;

        			rl6->next = rlprev6->next;
	        		rlprev6->next = rl6;
		        	restrictcount6++;
		        }
		        if ((rl6->flags ^ (u_short)flags) & RES_LIMITED) {
        			res_limited_refcnt6++;
			        mon_start(MON_RES); /* ensure data gets collected */
		        }
		        rl6->flags |= (u_short)flags;
		        break;

	        case RESTRICT_UNFLAG:
        		/*
		        * Remove some bits from the flags.  If we didn't
		        * find this one, just return.
		        */
		        if (rl6 != 0) {
        			if ((rl6->flags ^ (u_short)flags) & RES_LIMITED) {
				        res_limited_refcnt6--;
				        if (res_limited_refcnt6 == 0)
				        mon_stop(MON_RES);
			        }
			        rl6->flags &= (u_short)~flags;
		        }
		        break;

	        case RESTRICT_REMOVE:
        		/*
	        	 * Remove an entry from the table entirely if we found one.
		         * Don't remove the default entry and don't remove an
		         * interface entry.
		         */
		        if (rl6 != 0
		        && !IN6_IS_ADDR_UNSPECIFIED((struct in6_addr*)&rl6->addr6)
		        && !(rl6->mflags & RESM_INTERFACE)) {
        			rlprev6->next = rl6->next;
			        restrictcount6--;
			        if (rl6->flags & RES_LIMITED) {
        				res_limited_refcnt6--;
				        if (res_limited_refcnt6 == 0)
				        mon_stop(MON_RES);
			        }
			        memset((char *)rl6, 0, sizeof(struct restrictlist6));

			        rl6->next = resfree6;
			        resfree6 = rl6;
			        numresfree6++;
		        }
		        break;

	        default:
        		/* Oh, well */
		        break;
                }
       }


	/* done! */
}
