/*
 * Crypto-quality random number functions
 *
 * Author: Harlan Stenn, 2014
 *
 * This file is Copyright (c) 2014 by Network Time Foundation.
 * BSD terms apply: see the file COPYRIGHT in the distribution root for details.
 */

#include "config.h"
#include <sys/types.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#include <stdio.h>

#include <l_stdlib.h>
#include <ntp_random.h>
#include "safecast.h"

#ifdef USE_OPENSSL_CRYPTO_RAND
#include <openssl/err.h>
#include <openssl/rand.h>

int crypto_rand_init = 0;
#else

# ifndef HAVE_ARC4RANDOM_BUF
static int arc4random_stir(void);
static void arc4random_buf(void *buf, size_t nbytes);

int evutil_secure_rng_init(void);
void evutil_secure_rng_get_bytes(void *buf, size_t nbytes);

static int
arc4random_stir(void)
{
	return(evutil_secure_rng_init());
}
static void
arc4random_buf(void *buf, size_t nbytes)
{
	evutil_secure_rng_get_bytes(buf, nbytes);
	return;
}
# endif
#endif

int crypto_rand_ok = 0;

/*
 * As of late 2014, here's how we plan to provide cryptographic-quality
 * random numbers:
 * 
 * - If we are building with OpenSSL, use RAND_poll() and RAND_bytes().
 * - Otherwise, use arc4random().
 * 
 * Use of arc4random() can be forced using configure --disable-openssl-random
 *
 * We can count on arc4random existing, thru the OS or thru libevent.
 * The quality of arc4random depends on the implementor.
 * 
 * RAND_poll() doesn't show up until XXX.  If it's not present, we
 * need to either provide our own or use arc4random().
 */

/*
 * ntp_crypto_srandom:
 *
 * Initialize the random number generator, if needed by the underlying
 * crypto random number generation mechanism.
 */

void
ntp_crypto_srandom(
	void
	)
{
#ifdef USE_OPENSSL_CRYPTO_RAND
	if (!crypto_rand_init) {
		if (RAND_poll())
			crypto_rand_ok = 1;
		crypto_rand_init = 1;
	}
#else
	/*
	 * Explicitly init arc4random to make sure it does seed OK. This
	 * is the only way we can tell if it can successfully get
	 * entropy from the system.
	 */
	if (!arc4random_stir())
		crypto_rand_ok = 1;
#endif
}


/*
 * ntp_crypto_random_buf:
 *
 * Returns 0 on success, -1 on error.
 */
int
ntp_crypto_random_buf(
	void *buf,
	size_t nbytes
	)
{
	if (!crypto_rand_ok)
		return (-1);

#ifdef USE_OPENSSL_CRYPTO_RAND
	if (1 != RAND_bytes(buf, size2int_chk(nbytes))) {
		unsigned long err;
		char *err_str;

		err = ERR_get_error();
		err_str = ERR_error_string(err, NULL);
		/* XXX: Log the error */
		(void)&err_str;

		return -1;
	}
#else
	arc4random_buf(buf, nbytes);
#endif
	return 0;
}
