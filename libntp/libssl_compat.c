/*
 * libssl_compat.c -- OpenSSL v1.1 compatibility functions
 *
 * ---------------------------------------------------------------------
 * Written by Juergen Perlinger <perlinger@ntp.org> for the NTP project
 *
 * Based on an idea by Kurt Roeckx <kurt@roeckx.be>
 *
 * ---------------------------------------------------------------------
 * This is a clean room implementation of shim functions that have
 * counterparts in the OpenSSL v1.1 API but not in earlier versions. So
 * while OpenSSL broke binary compatibility with v1.1, this shim module
 * should provide the necessary source code compatibility with older
 * versions of OpenSSL.
 *
 * The other way round, functions that need random number generator
 * callbacks have also changed in OpenSSL v1.1, but in this case it is
 * easier to wrap new behaviour into a shim simulating the old API.
 *
 * ---------------------------------------------------------------------
 */
#include "config.h"

#include <string.h>
#include <openssl/bn.h>
#include <openssl/evp.h>

#include "ntp_types.h"
#include "libssl_compat.h"

/* --------------------------------------------------------------------
 * allocate & set a new BIGNUM object. Some examples and hints made me
 * wary of using BN_set_word here, so I went through a big-endian byte
 * buffer, which should be pretty portable, too.
 */
BIGNUM*
ntpMP_new_from_ulong(
	unsigned long	v
	)
{
	unsigned char	buf[sizeof(v)];
	int		idx;
	
	for (idx = sizeof(v); idx; v >>= 8)
		buf[--idx] = (unsigned char)(v & 0x0FF);
	return BN_bin2bn(buf, sizeof(v), NULL);
}

BIGNUM*
ntpMP_new_from_long(
	long	v
	)
{
	unsigned long	um = 0UL - (v < 0);
	unsigned long	uv = (unsigned long)v;
	BIGNUM *	bn = ntpMP_new_from_ulong((uv + um) ^ um);
	if (bn)
		BN_set_negative(bn, (um & 1));
	return bn;
}

/* ----------------------------------------------------------------- */
#if OPENSSL_VERSION_NUMBER < 0x10100000L
/* ----------------------------------------------------------------- */

/* --------------------------------------------------------------------
 * replace a BIGNUM owned by the caller with another one if it's not
 * NULL, taking over the ownership of the new value. This clears & frees
 * the old value -- the clear might be overkill, but it's better to err
 * on the side of paranoia here.
 */
static void
replace_bn_nn(
	BIGNUM **	ps,
	BIGNUM *	n
	)
{
	if (n) {
		BN_clear_free(*ps);
		*ps = n;
	}
}

/* --------------------------------------------------------------------
 * allocation and deallocation of message digests
 */
EVP_MD_CTX*
sslshim_EVP_MD_CTX_new(void)
{
	return calloc(1, sizeof(EVP_MD_CTX));
}

void
sslshim_EVP_MD_CTX_free(
	EVP_MD_CTX *	pctx
	)
{
	free(pctx);
}

/* --------------------------------------------------------------------
 * get EVP keys and key type
 */
int
sslshim_EVP_PKEY_base_id(
	const EVP_PKEY *pkey
	)
{
	return (pkey) ? pkey->type : EVP_PKEY_NONE;
}

RSA*
sslshim_EVP_PKEY_get0_RSA(
	EVP_PKEY *	pkey
	)
{
	return (pkey) ? pkey->pkey.rsa : NULL;
}

DSA*
sslshim_EVP_PKEY_get0_DSA(
	EVP_PKEY *	pkey
	)
{
	return (pkey) ? pkey->pkey.dsa : NULL;
}

/* --------------------------------------------------------------------
 * set/get RSA params
 */
void
sslshim_RSA_get0_key(
	const RSA *	prsa,
	const BIGNUM **	pn,
	const BIGNUM **	pe,
	const BIGNUM **	pd
	)
{
	const BIGNUM *n = NULL;
	const BIGNUM *e = NULL;
	const BIGNUM *d = NULL;
	if (prsa) {
		n = prsa->n;
		e = prsa->e;
		d = prsa->d;
	}
	if (pn)
		*pn = n;
	if (pe)
		*pe = e;
	if (pd)
		*pd = d;
}

int
sslshim_RSA_set0_key(
	RSA *		prsa,
	BIGNUM *	n,
	BIGNUM *	e,
	BIGNUM *	d
	)
{
	if (!(prsa && (prsa->n || n) && (prsa->e || e)))
		return 0;

	replace_bn_nn(&prsa->n, n);
	replace_bn_nn(&prsa->e, e);
	replace_bn_nn(&prsa->d, d);
	
	return 1;
}

void
sslshim_RSA_get0_factors(
	const RSA *	prsa,
	const BIGNUM **	pp,
	const BIGNUM **	pq
	)
{
	const BIGNUM *p = NULL;
	const BIGNUM *q = NULL;
	if (prsa) {
		p = prsa->p;
		q = prsa->q;
	}
	if (pp)
		*pp = p;
	if (pq)
		*pq = q;
}

int
sslshim_RSA_set0_factors(
	RSA    *	prsa,
	BIGNUM *	p,
	BIGNUM *	q
	)
{
	if (!(prsa && (prsa->p || p) && (prsa->q || q)))
		return 0;

	replace_bn_nn(&prsa->p, p);
	replace_bn_nn(&prsa->q, q);

	return 1;
}

int
sslshim_RSA_set0_crt_params(
	RSA    *	prsa,
	BIGNUM *	dmp1,
	BIGNUM *	dmq1,
	BIGNUM *	iqmp
	)
{
	if (!(prsa && (prsa->dmp1 || dmp1) &&
	      (prsa->dmq1 || dmq1) && (prsa->iqmp || iqmp)))
		return 0;

	replace_bn_nn(&prsa->dmp1, dmp1);
	replace_bn_nn(&prsa->dmq1, dmq1);
	replace_bn_nn(&prsa->iqmp, iqmp);
	
	return 1;
}

/* --------------------------------------------------------------------
 * set/get DSA signature parameters
 */
void
sslshim_DSA_SIG_get0(
	const DSA_SIG *	psig,
	const BIGNUM **	pr,
	const BIGNUM **	ps
	)
{
	BIGNUM * r = NULL;
	BIGNUM * s = NULL;
	if (psig) {
		r = psig->r;
		s = psig->s;
	}
	if (pr != NULL)
		*pr = r;
	if (ps != NULL)
		*ps = s;
}

int
sslshim_DSA_SIG_set0(
	DSA_SIG *	psig,
	BIGNUM *	r,
	BIGNUM *	s
	)
{
	if (!(psig && r && s))
		return 0;
	
	BN_clear_free(psig->r);
	psig->r = r;
	BN_clear_free(psig->s);
	psig->s = s;
	
	return 1;
}

/* --------------------------------------------------------------------
 * get/set DSA parameters
 */
void
sslshim_DSA_get0_pqg(
	const DSA *	pdsa,
	const BIGNUM **	pp,
	const BIGNUM **	pq,
	const BIGNUM **	pg
	)
{
	BIGNUM * p = NULL;
	BIGNUM * q = NULL;
	BIGNUM * g = NULL;
	if (pdsa) {
		p = pdsa->p;
		q = pdsa->q;
		g = pdsa->g;
	}
	if (pp != NULL)
		*pp = p;
	if (pq != NULL)
		*pq = q;
	if (pg != NULL)
		*pg = g;
}

int
sslshim_DSA_set0_pqg(
	DSA *		pdsa,
	BIGNUM *	p,
	BIGNUM *	q,
	BIGNUM *	g
	)
{
	if (!(pdsa && (pdsa->p || p) && (pdsa->q || q) && (pdsa->g || g)))
		return 0;

	replace_bn_nn(&pdsa->p, p);
	replace_bn_nn(&pdsa->q, q);
	replace_bn_nn(&pdsa->g, g);

	return 1;
}

void
sslshim_DSA_get0_key(
	const DSA *	pdsa,
	const BIGNUM **	ppub_key,
	const BIGNUM **	ppriv_key
	)
{
	const BIGNUM * ppub  = NULL;
	const BIGNUM * ppriv = NULL;
	if (pdsa) {
		ppub  = pdsa->pub_key;
		ppriv = pdsa->priv_key;
	}
	if (ppub_key != NULL)
		*ppub_key = ppub;
	if (ppriv_key != NULL)
		*ppriv_key = ppriv;
}

int
sslshim_DSA_set0_key(
	DSA *		pdsa,
	BIGNUM *	pub_key,
	BIGNUM *	priv_key
	)
{
	if (!(pdsa && (pdsa->pub_key || pub_key)))
		return 0;

	replace_bn_nn(&pdsa->pub_key, pub_key);
	replace_bn_nn(&pdsa->priv_key, priv_key);

	return 1;
}

/* ----------------------------------------------------------------- */
#else
/* ----------------------------------------------------------------- */

/* backward compat shims -- it's easier this way because of the
 * callbacks. Once the new API is used exclusively, these shims can go.
 */
static BN_GENCB *
new_gencb(
	void	(*callback)(int, int, void *),
	void *	cb_arg
	)
{
	BN_GENCB * gcb = BN_GENCB_new();
	if (gcb)
		BN_GENCB_set_old(gcb, callback, cb_arg);
	return gcb;
}

BIGNUM*
sslshim_BN_generate_prime(
	BIGNUM *	ret,
	int		bits,
	int		safe,
	BIGNUM *	add,
	BIGNUM *	rem,
	void		(*callback)(int, int, void *),
	void *		cb_arg
	)
{
	BN_GENCB *	gcb = new_gencb(callback, cb_arg);
	int		ok  = 0;

	if (gcb) {
		ok = BN_generate_prime_ex(
			ret, bits, safe, add, rem, gcb);
		BN_GENCB_free(gcb);
	}
	return ok ? ret : NULL; 
}

int
sslshim_BN_is_prime(
	const BIGNUM *	a,
	int		checks,
	void		(*callback)(int, int, void *),
	BN_CTX *	ctx,
	void *		cb_arg
	)
{
	BN_GENCB *	gcb = new_gencb(callback, cb_arg);
	int		ok  = 0;

	if (gcb) {
		ok = BN_is_prime_ex(a, checks, ctx, gcb);
		BN_GENCB_free(gcb);
	}
	return ok;
}

RSA*
sslshim_RSA_generate_key(
	int		bits,
	unsigned long	e,
	void 		(*callback)(int, int, void *),
	void *		cb_arg
	)
{
	RSA *		rsa = RSA_new();
	BIGNUM *	be  = ntpMP_new_from_ulong(e);
	BN_GENCB *	gcb = new_gencb(callback, cb_arg);

	if (!(rsa && gcb && be && RSA_generate_key_ex(rsa, bits, be, gcb))) {
		RSA_free(rsa);
		rsa = NULL;
	}
	BN_GENCB_free(gcb);
	BN_free(be);
	return rsa;
}

DSA*
sslshim_DSA_generate_parameters(
	int		bits,
	unsigned char *	seed,
	int		slen,
	int *		cntret,
	unsigned long *	hret,
	void		(*callback)(int, int, void *),
	void *		cb_arg
	)
{
	DSA *		dsa = DSA_new();
	BN_GENCB *	gcb = new_gencb(callback, cb_arg);
	if (!(dsa && gcb && DSA_generate_parameters_ex(
		      dsa, bits, seed, slen, cntret, hret, gcb)))
	{
		DSA_free(dsa);
		dsa = NULL;
	}
	BN_GENCB_free(gcb);
	return dsa;
}
/* ----------------------------------------------------------------- */
#endif
/* ----------------------------------------------------------------- */
