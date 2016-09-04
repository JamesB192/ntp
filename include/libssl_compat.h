/*
 * libssl_compat.h -- OpenSSL v1.1 compatibility shims
 *
 * ---------------------------------------------------------------------
 *
 * Written by Juergen Perlinger <perlinger@ntp.org> for the NTP project
 *
 * Based on an idea by Kurt Roeckx <kurt@roeckx.be>
 *
 * ---------------------------------------------------------------------
 * This is a clean room implementation of shim functions that have
 * counterparts in the OpenSSL v1.1 API but not in earlier versions.
 *
 * If the OpenSSL version used for compilation needs the shims (that is,
 * does not provide the new functions) the names of these functions are
 * redirected to our shims.
 *
 * The other way round, functions that need random number generator
 * callbacks have also changed in OpenSSL v1.1, but in this case it is
 * easier to wrap the new behaviour into a shim simulating the old API.
 *
 * At the time of this writing the old-style API is still available; it
 * just creates annoying depreciation warnings. OTOH, this means the
 * implementation in OpenSSL can vanish at any time, so it's better to
 * provide the necessary wrappers.
 * ---------------------------------------------------------------------
 */

#ifndef NTP_LIBSSL_COMPAT_H
#define NTP_LIBSSL_COMPAT_H

#include "openssl/evp.h"
#include "openssl/dsa.h"
#include "openssl/rsa.h"

extern BIGNUM * ntpMP_new_from_ulong(unsigned long);
extern BIGNUM * ntpMP_new_from_long(long);

/* ----------------------------------------------------------------- */
#if OPENSSL_VERSION_NUMBER < 0x10100000L
/* ----------------------------------------------------------------- */

/* shim the new-style API on an old-style OpenSSL */

extern EVP_MD_CTX *sslshim_EVP_MD_CTX_new(void);
extern void        sslshim_EVP_MD_CTX_free(EVP_MD_CTX *ctx);

extern int   sslshim_EVP_PKEY_base_id(const EVP_PKEY * pkey);
extern RSA * sslshim_EVP_PKEY_get0_RSA(EVP_PKEY * pkey);
extern DSA * sslshim_EVP_PKEY_get0_DSA(EVP_PKEY * pkey);

extern void sslshim_RSA_get0_key(const RSA *prsa, const BIGNUM **pn,
				 const BIGNUM **pe, const BIGNUM **pd);
extern int  sslshim_RSA_set0_key(RSA *prsa, BIGNUM *n,
				 BIGNUM *e, BIGNUM *d);
extern void sslshim_RSA_get0_factors(const RSA *prsa, const BIGNUM **pp,
				     const BIGNUM **pq);
extern int  sslshim_RSA_set0_factors(RSA *prsar, BIGNUM *p, BIGNUM *q);
extern int  sslshim_RSA_set0_crt_params(RSA *prsa, BIGNUM *dmp1,
					BIGNUM *dmq1, BIGNUM *iqmp);

extern void sslshim_DSA_SIG_get0(const DSA_SIG *psig, const BIGNUM **pr,
				 const BIGNUM **ps);
extern int  sslshim_DSA_SIG_set0(DSA_SIG *psig, BIGNUM *r, BIGNUM *s);
extern void sslshim_DSA_get0_pqg(const DSA *pdsa, const BIGNUM **pp,
				 const BIGNUM **pq, const BIGNUM **pg);
extern int  sslshim_DSA_set0_pqg(DSA *pdsa, BIGNUM *p, BIGNUM *q, BIGNUM *g);
extern void sslshim_DSA_get0_key(const DSA *pdsa, const BIGNUM **ppub_key,
				 const BIGNUM **ppriv_key);
extern int  sslshim_DSA_set0_key(DSA *pdsa, BIGNUM *pub_key,
				 BIGNUM *priv_key);

#define EVP_MD_CTX_new		sslshim_EVP_MD_CTX_new
#define EVP_MD_CTX_free		sslshim_EVP_MD_CTX_free

#define EVP_PKEY_base_id	sslshim_EVP_PKEY_base_id
#define EVP_PKEY_get0_RSA	sslshim_EVP_PKEY_get0_RSA
#define EVP_PKEY_get0_DSA	sslshim_EVP_PKEY_get0_DSA

#define RSA_get0_key		sslshim_RSA_get0_key
#define RSA_set0_key		sslshim_RSA_set0_key
#define RSA_get0_factors	sslshim_RSA_get0_factors
#define RSA_set0_factors	sslshim_RSA_set0_factors
#define RSA_set0_crt_params	sslshim_RSA_set0_crt_params

#define DSA_SIG_get0		sslshim_DSA_SIG_get0
#define DSA_SIG_set0		sslshim_DSA_SIG_set0
#define DSA_get0_pqg		sslshim_DSA_get0_pqg
#define DSA_set0_pqg		sslshim_DSA_set0_pqg
#define DSA_get0_key		sslshim_DSA_get0_key
#define DSA_set0_key		sslshim_DSA_set0_key

/* ----------------------------------------------------------------- */
#else /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
/* ----------------------------------------------------------------- */

/* shim the new API to provide old functions */

extern BIGNUM * sslshim_BN_generate_prime(
	BIGNUM *ret, int num, int safe, BIGNUM *add, BIGNUM *rem,
	void (*callback)(int, int, void *), void *cb_arg);

extern int sslshim_BN_is_prime(
	const BIGNUM *a, int checks, void (*callback)(int, int, void *),
	BN_CTX *ctx, void *cb_arg);

extern RSA * sslshim_RSA_generate_key(
	int num, unsigned long e, void (*callback)(int, int, void *),
	void *cb_arg);

extern DSA * sslshim_DSA_generate_parameters(
	int bits, unsigned char *seed, int seed_len, int *counter_ret,
	unsigned long *h_ret, void (*callback)(int, int, void *),
	void *cb_arg);


#define BN_generate_prime	sslshim_BN_generate_prime
#define BN_is_prime		sslshim_BN_is_prime

#define RSA_generate_key	sslshim_RSA_generate_key
#define DSA_generate_parameters	sslshim_DSA_generate_parameters

/* ----------------------------------------------------------------- */
#endif /* OPENSSL_VERSION_NUMBER checks */
/* ----------------------------------------------------------------- */

#endif /* NTP_LIBSSL_COMPAT_H */
