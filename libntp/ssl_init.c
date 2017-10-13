/*
 * ssl_init.c	Common OpenSSL initialization code for the various
 *		programs which use it.
 *
 * Moved from ntpd/ntp_crypto.c crypto_setup()
 */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <ctype.h>
#include <ntp.h>
#include <ntp_debug.h>
#include <lib_strbuf.h>

#ifdef OPENSSL
#include "openssl/crypto.h"
#include "openssl/err.h"
#include "openssl/evp.h"
#include "openssl/opensslv.h"
#include "libssl_compat.h"

int ssl_init_done;

#if OPENSSL_VERSION_NUMBER < 0x10100000L

static void
atexit_ssl_cleanup(void)
{
	if (!ssl_init_done)
		return;

	ssl_init_done = FALSE;
	EVP_cleanup();
	ERR_free_strings();
}

void
ssl_init(void)
{
	init_lib();

	if ( ! ssl_init_done) {
	    ERR_load_crypto_strings();
	    OpenSSL_add_all_algorithms();
	    atexit(&atexit_ssl_cleanup);
	    ssl_init_done = TRUE;
	}
}

#else /* OPENSSL_VERSION_NUMBER >= 0x10100000L */

void
ssl_init(void)
{
	init_lib();
	ssl_init_done = TRUE;
}

#endif /* OPENSSL_VERSION_NUMBER */


void
ssl_check_version(void)
{
	u_long	v;

	v = OpenSSL_version_num();
	if ((v ^ OPENSSL_VERSION_NUMBER) & ~0xff0L) {
		msyslog(LOG_WARNING,
		    "OpenSSL version mismatch. Built against %lx, you have %lx",
		    (u_long)OPENSSL_VERSION_NUMBER, v);
		fprintf(stderr,
		    "OpenSSL version mismatch. Built against %lx, you have %lx\n",
		    (u_long)OPENSSL_VERSION_NUMBER, v);
	}

	INIT_SSL();
}

#endif	/* OPENSSL */


/*
 * keytype_from_text	returns OpenSSL NID for digest by name, and
 *			optionally the associated digest length.
 *
 * Used by ntpd authreadkeys(), ntpq and ntpdc keytype()
 */
int
keytype_from_text(
	const char *	text,
	size_t *	pdigest_len
	)
{
	int		key_type;
	u_int		digest_len;

	/*----------------------------------------------------------- */
#ifdef OPENSSL	/* --*-- OpenSSL code --*-- */
	/*----------------------------------------------------------- */

	char *		upcased;
	char *		pch;
	EVP_MD const *	md;

	/*
	 * OpenSSL digest short names are capitalized, so uppercase the
	 * digest name before passing to OBJ_sn2nid().  If it is not
	 * recognized but begins with 'M' or 'm' use NID_md5 to be
	 * consistent with past behavior.
	 */
	INIT_SSL();

	/* get name in uppercase */
	LIB_GETBUF(upcased);
	strlcpy(upcased, text, LIB_BUFLENGTH);
	for (pch = upcased; '\0' != *pch; ++pch)
		*pch = (char)toupper((unsigned char)*pch);

	md = EVP_get_digestbyname(upcased);
	if (NULL == md && !strcmp(upcased, "M"))
		md = EVP_get_digestbyname("MD5");
	if (NULL == md)
		return 0;

	key_type   = EVP_MD_type(md);
	digest_len = EVP_MD_size(md);

	/*----------------------------------------------------------- */
#else	/* --*-- NON-SSL CODE --*-- */
	/*----------------------------------------------------------- */

	if ('m' == tolower((unsigned char)text[0]))
		key_type = NID_md5;
	else
		return 0;

	digest_len = 16;

	/*----------------------------------------------------------- */
#endif	/* --*-- NON-SSL CODE --*-- */
	/*----------------------------------------------------------- */

	if (pdigest_len)
		*pdigest_len = digest_len;
	return key_type;
}


/*
 * keytype_name		returns OpenSSL short name for digest by NID.
 *
 * Used by ntpq and ntpdc keytype()
 */
const char *
keytype_name(
	int nid
	)
{
	static const char unknown_type[] = "(unknown key type)";
	const char *name;

#ifdef OPENSSL
	INIT_SSL();
	name = OBJ_nid2sn(nid);
	if (NULL == name)
		name = unknown_type;
#else	/* !OPENSSL follows */
	if (NID_md5 == nid)
		name = "MD5";
	else
		name = unknown_type;
#endif
	return name;
}


/*
 * Use getpassphrase() if configure.ac detected it, as Suns that
 * have it truncate the password in getpass() to 8 characters.
 */
#ifdef HAVE_GETPASSPHRASE
# define	getpass(str)	getpassphrase(str)
#endif

/*
 * getpass_keytype() -- shared between ntpq and ntpdc, only vaguely
 *			related to the rest of ssl_init.c.
 */
char *
getpass_keytype(
	int	keytype
	)
{
	char	pass_prompt[64 + 11 + 1]; /* 11 for " Password: " */

	snprintf(pass_prompt, sizeof(pass_prompt),
		 "%.64s Password: ", keytype_name(keytype));

	return getpass(pass_prompt);
}
