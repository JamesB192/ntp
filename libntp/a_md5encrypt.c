/*
 *	digest support for NTP, MD5 and with OpenSSL more
 */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "ntp_fp.h"
#include "ntp_string.h"
#include "ntp_stdlib.h"
#include "ntp.h"
#include "ntp_md5.h"	/* provides OpenSSL digest API */
#include "isc/string.h"

#ifdef OPENSSL
# include "openssl/cmac.h"
# define  CMAC			"AES128CMAC"
# define  AES_128_KEY_SIZE	16
#endif

/*
 * MD5authencrypt - generate message digest
 *
 * Returns length of MAC including key ID and digest.
 */
size_t
MD5authencrypt(
	int		type,	/* hash algorithm */
	const u_char *	key,	/* key pointer */
	u_int32 *	pkt,	/* packet pointer */
	size_t		length	/* packet length */
	)
{
	u_char	digest[EVP_MAX_MD_SIZE];
	u_int	len = 0;

	/*
	 * Compute digest of key concatenated with packet. Note: the
	 * key type and digest type have been verified when the key
	 * was creaded.
	 */
	INIT_SSL();
#ifdef OPENSSL
	/* Check if CMAC key type specific code required */
	if (type == NID_cmac) {
		CMAC_CTX *	ctx;
		size_t		slen = 0;
		
		if (debug) {
			fprintf(stderr, "%s:%d:%s():%s:nid\n",
				__FILE__, __LINE__, __func__, CMAC);
		}
		
		if (!(ctx = CMAC_CTX_new())) {
			fprintf(stderr,  "MAC encrypt: CMAC %s CTX new failed.\n", CMAC);
			msyslog(LOG_ERR, "MAC encrypt: CMAC %s CTX new failed.",   CMAC);
		}
		else if (!CMAC_Init(ctx, key, AES_128_KEY_SIZE,
				    EVP_aes_128_cbc(), NULL)) {
			fprintf(stderr,  "MAC encrypt: CMAC %s Init failed.\n",    CMAC);
			msyslog(LOG_ERR, "MAC encrypt: CMAC %s Init failed.",      CMAC);
		}
		else if (!CMAC_Update(ctx, pkt, length)) {
			fprintf(stderr,  "MAC encrypt: CMAC %s Update failed.\n",  CMAC);
			msyslog(LOG_ERR, "MAC encrypt: CMAC %s Update failed.",    CMAC);
		}
		else if (!CMAC_Final(ctx, digest, &slen)) {
			fprintf(stderr,  "MAC encrypt: CMAC %s Final failed.\n",   CMAC);
			msyslog(LOG_ERR, "MAC encrypt: CMAC %s Final failed.",     CMAC);
			slen = 0;
		}
		len = (u_int)slen;
		
		CMAC_CTX_cleanup(ctx);
	} else	/* generic MAC handling */
#endif
	{
		EVP_MD_CTX *	ctx;
		
		if (!(ctx = EVP_MD_CTX_new())) {
			fprintf(stderr,  "MAC encrypt: MAC %s Digest CTX new failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC encrypt: MAC %s Digest CTX new failed.",
				OBJ_nid2sn(type));
		}
#ifdef OPENSSL	/* OpenSSL 1 supports return codes 0 fail, 1 okay */
		else if (!EVP_DigestInit(ctx, EVP_get_digestbynid(type))) {
			fprintf(stderr,  "MAC encrypt: MAC %s Digest Init failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC encrypt: MAC %s Digest Init failed.",
				OBJ_nid2sn(type));
		}
		else if (!EVP_DigestUpdate(ctx, key, (u_int)cache_secretsize)) {
			fprintf(stderr,  "MAC encrypt: MAC %s Digest Update key failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC encrypt: MAC %s Digest Update key failed.",
				OBJ_nid2sn(type));
		}
		else if (!EVP_DigestUpdate(ctx, (u_char *)pkt, (u_int)length)) {
			fprintf(stderr,  "MAC encrypt: MAC %s Digest Update data failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC encrypt: MAC %s Digest Update data failed.",
				OBJ_nid2sn(type));
		}
		else if (!EVP_DigestFinal(ctx, digest, &len)) {
			fprintf(stderr,  "MAC encrypt: MAC %s Digest Final failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC encrypt: MAC %s Digest Final failed.",
				OBJ_nid2sn(type));
			len = 0;
		}
#else /* !OPENSSL */
		if (!(ctx && EVP_DigestInit(ctx, EVP_get_digestbynid(type)))) {
			msyslog(LOG_ERR,
				"MAC encrypt: digest init failed");
			EVP_MD_CTX_free(ctx);
			return (0);
		}
		EVP_DigestUpdate(ctx, key, cache_secretsize);
		EVP_DigestUpdate(ctx, (u_char *)pkt, length);
		EVP_DigestFinal(ctx, digest, &len);
#endif
		EVP_MD_CTX_free(ctx);
	}
	/* If the MAC is longer than the MAX then truncate it. */
	if (len > MAX_MDG_LEN)
		len = MAX_MDG_LEN;
	memmove((u_char *)pkt + length + KEY_MAC_LEN, digest, len);
	return (len + KEY_MAC_LEN);
}


/*
 * MD5authdecrypt - verify MD5 message authenticator
 *
 * Returns one if digest valid, zero if invalid.
 */
int
MD5authdecrypt(
	int		type,	/* hash algorithm */
	const u_char *	key,	/* key pointer */
	u_int32	*	pkt,	/* packet pointer */
	size_t		length,	/* packet length */
	size_t		size	/* MAC size */
	)
{
	u_char	digest[EVP_MAX_MD_SIZE];
	u_int	len = 0;

	/*
	 * Compute digest of key concatenated with packet. Note: the
	 * key type and digest type have been verified when the key
	 * was created.
	 */
	INIT_SSL();
#ifdef OPENSSL
	/* Check if CMAC key type specific code required */
	if (type == NID_cmac) {
		CMAC_CTX *	ctx;
		size_t		slen = 0;

		if (debug) {
			fprintf(stderr, "%s:%d:%s():%s:nid\n",
				__FILE__, __LINE__, __func__, CMAC);
		}
		
		if (!(ctx = CMAC_CTX_new())) {
			fprintf(stderr,  "MAC decrypt: CMAC %s CTX new failed.\n", CMAC);
			msyslog(LOG_ERR, "MAC decrypt: CMAC %s CTX new failed.",   CMAC);
		}
		else if (!CMAC_Init(ctx, key, AES_128_KEY_SIZE,
				    EVP_aes_128_cbc(), NULL)) {
			fprintf(stderr,  "MAC decrypt: CMAC %s Init failed.\n",    CMAC);
			msyslog(LOG_ERR, "MAC decrypt: CMAC %s Init failed.",      CMAC);
		}
		else if (!CMAC_Update(ctx, pkt, length)) {
			fprintf(stderr,  "MAC decrypt: CMAC %s Update failed.\n",  CMAC);
			msyslog(LOG_ERR, "MAC decrypt: CMAC %s Update failed.",    CMAC);
		}
		else if (!CMAC_Final(ctx, digest, &slen)) {
			fprintf(stderr,  "MAC decrypt: CMAC %s Final failed.\n",   CMAC);
			msyslog(LOG_ERR, "MAC decrypt: CMAC %s Final failed.",     CMAC);
			slen = 0;
		}
		len = (u_int)slen;
		
		CMAC_CTX_cleanup(ctx);
	} else	/* generic MAC handling */
#endif
	{
		EVP_MD_CTX *	ctx;
		
		if (!(ctx = EVP_MD_CTX_new())) {
			fprintf(stderr,  "MAC decrypt: MAC %s Digest CTX new failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC decrypt: MAC %s Digest CTX new failed.",
				OBJ_nid2sn(type));
		}
#ifdef OPENSSL	/* OpenSSL 1 supports return codes 0 fail, 1 okay */
		else if (!EVP_DigestInit(ctx, EVP_get_digestbynid(type))) {
			fprintf(stderr,  "MAC decrypt: MAC %s Digest Init failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC decrypt: MAC %s Digest Init failed.",
				OBJ_nid2sn(type));
		}
		else if (!EVP_DigestUpdate(ctx, key, (u_int)cache_secretsize)) {
			fprintf(stderr,  "MAC decrypt: MAC %s Digest Update key failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC decrypt: MAC %s Digest Update key failed.",
				OBJ_nid2sn(type));
		}
		else if (!EVP_DigestUpdate(ctx, (u_char *)pkt, (u_int)length)) {
			fprintf(stderr,  "MAC decrypt: MAC %s Digest Update data failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC decrypt: MAC %s Digest Update data failed.",
				OBJ_nid2sn(type));
		}
		else if (!EVP_DigestFinal(ctx, digest, &len)) {
			fprintf(stderr,  "MAC decrypt: MAC %s Digest Final failed.\n",
				OBJ_nid2sn(type));
			msyslog(LOG_ERR, "MAC decrypt: MAC %s Digest Final failed.",
				OBJ_nid2sn(type));
			len = 0;
		}
#else /* !OPENSSL */
		if (!(ctx && EVP_DigestInit(ctx, EVP_get_digestbynid(type)))) {
			msyslog(LOG_ERR,
				"MAC decrypt: digest init failed");
			EVP_MD_CTX_free(ctx);
			return (0);
		}
		EVP_DigestUpdate(ctx, key, cache_secretsize);
		EVP_DigestUpdate(ctx, (u_char *)pkt, (u_int)length);
		EVP_DigestFinal(ctx, digest, &len);
#endif
		EVP_MD_CTX_free(ctx);
	}
	/* If the MAC is longer than the MAX then truncate it. */
	if (len > MAX_MDG_LEN)
		len = MAX_MDG_LEN;
	if (size != (size_t)len + KEY_MAC_LEN) {
		msyslog(LOG_ERR,
		    "MAC decrypt: MAC length error");
		return (0);
	}
	return !isc_tsmemcmp(digest,
		 (u_char *)pkt + length + KEY_MAC_LEN, len);
}

/*
 * Calculate the reference id from the address. If it is an IPv4
 * address, use it as is. If it is an IPv6 address, do a md5 on
 * it and use the bottom 4 bytes.
 * The result is in network byte order.
 */
u_int32
addr2refid(sockaddr_u *addr)
{
	u_char		digest[EVP_MAX_MD_SIZE];
	u_int32		addr_refid;
	EVP_MD_CTX	*ctx;
	u_int		len;

	if (IS_IPV4(addr))
		return (NSRCADR(addr));

	INIT_SSL();

	ctx = EVP_MD_CTX_new();
	EVP_MD_CTX_init(ctx);
#ifdef EVP_MD_CTX_FLAG_NON_FIPS_ALLOW
	/* MD5 is not used as a crypto hash here. */
	EVP_MD_CTX_set_flags(ctx, EVP_MD_CTX_FLAG_NON_FIPS_ALLOW);
#endif
	if (!EVP_DigestInit_ex(ctx, EVP_md5(), NULL)) {
		msyslog(LOG_ERR,
		    "MD5 init failed");
		EVP_MD_CTX_free(ctx);	/* pedantic... but safe */
		exit(1);
	}

	EVP_DigestUpdate(ctx, (u_char *)PSOCK_ADDR6(addr),
	    sizeof(struct in6_addr));
	EVP_DigestFinal(ctx, digest, &len);
	EVP_MD_CTX_free(ctx);
	memcpy(&addr_refid, digest, sizeof(addr_refid));
	return (addr_refid);
}
