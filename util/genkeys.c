/*
 * Program to generate cryptographic keys for NTP clients and servers
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include "ntp_machine.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

#ifdef OPENSSL
#include "openssl/bn.h"
#include <openssl/dh.h>
#include "openssl/evp.h"
#include "openssl/err.h"
#include "openssl/rand.h"
#include "openssl/pem.h"
#include "openssl/x509v3.h"
#include <openssl/objects.h>
#include "openssl/asn1_mac.h"
#endif /* OPENSSL */

/*
 * Cryptodefines
 */
#define	MODULUSLEN	512	/* length of RSA/DSA modulus */
#define	PRIMELEN	512	/* length of DH prime */
#define	MD5KEYS		16	/* number of MD5 keys generated */
#define	PATH_MAX	255	/* max file name length */
#define	JAN_1970	ULONG_CONST(2208988800) /* NTP seconds */
#define YEAR		((long)60*60*24*365) /* one year in seconds */
#define IFFLEN		PRIMELEN / 8 /* IFF exponent length (bytes) */

#define PEM_STRING_IFFPARAMS "IFF PARAMETERS" /* PEM type */

#define PEM_write_IFFparams(fp, x) \
	PEM_ASN1_write((int (*)())i2d_IFFparams, \
	    PEM_STRING_IFFPARAMS, fp, (char *)x, NULL, NULL, 0, NULL, \
	    NULL)

#define PEM_read_IFFparams(fp, x, cb, u) (DH *)PEM_ASN1_read( \
           (char *(*)())d2i_IFFparams, PEM_STRING_IFFPARAMS, fp, \
	   (char **)x, cb, u)

/*
 * Prototypes
 */
FILE	*fheader P((u_char *));	/* construct file header */
#ifdef OPENSSL
int	x509	 P((u_char *, EVP_PKEY *, EVP_MD *)); /* generate req/cert */
void	cb	 P((int, int, void *));	/* callback routine */
u_long	asn2ntp	 P((ASN1_TIME *)); /* ASN.1 time to NTP seconds */
int	i2d_IFFparams P((DH *, u_char **)); /* PEM write */
DH	*d2i_IFFparams P((DH **, u_char **, long)); /* PEM read */
#endif /* OPENSSL */

/*
 * Program variables
 */
struct timeval tv;		/* initialization vector */
u_long	ntptime;		/* NTP epoch */
u_char	hostname[PATH_MAX];	/* host name */
#ifdef OPENSSL
char	*expa_hex;		/* IFF public value (hex) */
long	d0, d1, d2, d3;		/* callback counters */
#endif /* OPENSSL */

char ftemp[200];


/*
 * Main program
 *
 * This program generates files "ntpkey_<type>_<hostname>.<filestamp>",
 * where <type> is the file type, <hostname> is the generating host and
 * <filestamp> is the NTP seconds in decimal format. The NTP programs
 * expect generic names such as "ntpkey_key_whimsy.udel.edu" with the
 * connection being maintained by soft links.
 *
 * Files are prefixed with a header giving the name and date of creation
 * followed by a type-specific descriptive label and PEM-encoded data
 * string compatible with programs of the OpenSSL distribution.
 */
int
main(
	int argc,
	char *argv[]
	)
{
#ifdef OPENSSL
	EVP_PKEY *pkey;		/* public/private keys */
	EVP_MD_CTX ctx;		/* signature context */
	RSA	*rsa;		/* RSA keys */
	DSA	*dsa_params;	/* DSA parameters */
	DH	*dh_params;	/* Diffie-Hellman parameters */
	u_char	bin[PRIMELEN / 8]; /* bignum binary */
	u_char	seed[20];	/* seed for DSA parameters */
	u_char	*sig;		/* DSA signature */
	char	pathbuf[PATH_MAX];
#endif /* OPENSSL */
	u_char	md5key[16];
	FILE	*str;
	u_int	temp;
	u_char	rbyte;
	int	i, j;

DH  *dh2;

#ifdef OPENSSL
	if (SSLeay() != OPENSSL_VERSION_NUMBER) {
		printf("OpenSSL version mismatch. Built against %lx, you have %lx\n",
			OPENSSL_VERSION_NUMBER, SSLeay());
		exit(1);
	} else {
		printf("OpenSSL version %lx\n", SSLeay());
	}
#endif

	/*
	 * Initialize host name and timestamp.
	 */
	gethostname(hostname, sizeof(hostname));
	gettimeofday(&tv, 0);
	ntptime = tv.tv_sec + JAN_1970;

	/*
	 * Generate semi-random MD5 keys.
	 */
	printf("Generating MD5 keys...\n");
	str = fheader("MD5key");
	srandom((u_int)tv.tv_usec);
	for (i = 1; i <= MD5KEYS; i++) {
		for (j = 0; j < 16; j++) {
			while (1) {
				temp = random() & 0xff;
				if (temp == '#')
					continue;
				if (temp > 0x20 && temp < 0x7f)
					break;
			}
			md5key[j] = (u_char)temp;
		}
		md5key[16] = '\0';
		fprintf(str, "%2d MD5 %16s	# MD5 key\n", i,
		    md5key);
	}
	fclose(str);

#ifdef OPENSSL
	/*
	 * Seed random number generator and grow weeds.
	 */
	if (RAND_file_name(pathbuf, PATH_MAX) == NULL) {
		printf("RAND_file_name %s\n",
		    ERR_error_string(ERR_get_error(), NULL));
		exit (-1);
	}
	temp = RAND_load_file(pathbuf, -1);
	if (temp == 0) {
		printf("RAND_load_file <%s>: \n\t%s\n",
		    pathbuf,
		    ERR_error_string(ERR_get_error(), NULL));
		exit (-1);
	}
	printf("Random seed file %s bytes %u\n", pathbuf, temp);
	temp = random();
	RAND_add(&temp, sizeof(temp), 4.0);
	RAND_write_file(pathbuf);   
	ERR_load_crypto_strings();
	OpenSSL_add_all_algorithms();

	/*
	 * Generate Diffie-Hellman parameters.
	 */
	printf("Generating DH parameters (%d bits)...\n", PRIMELEN);
	dh_params = DH_generate_parameters(PRIMELEN, 2, cb,
	    "DH_params");
	if (dh_params == NULL) {
		printf("DH generate parameters fails\n%s\n",
		    ERR_error_string(ERR_get_error(), NULL));
		return (-1);
		}
	str = fheader("DHpar");
	PEM_write_DHparams(str, dh_params);
	fclose(str);
	DHparams_print_fp(stdout, dh_params);

	/*
	 * Generate IFF private and public values. These are just the
	 * Diffie-Hellman private and public values, but used in an
	 * interesting way.
	 */
	printf("Generating IFF values (%d bits)...\n", PRIMELEN);
	DH_generate_key(dh_params);
	str = fheader("IFF");
	temp = PRIMELEN / 8;
	sprintf(pathbuf, "%d", temp);
	PEM_write_IFFparams(str, dh_params);

#if 0
	BN_bn2bin(dh_params->priv_key, bin);
	PEM_write(str, "IFF_Private", pathbuf, bin, temp);
	BN_bn2bin(dh_params->pub_key, bin);
	PEM_write(str, "IFF_Public", pathbuf, bin, temp);
#endif
	fclose(str);
	expa_hex = BN_bn2hex(dh_params->pub_key);

	str = fopen(ftemp, "r");

printf("xxx %s %d\n", ftemp, str);

	PEM_read_IFFparams(str, &dh2, NULL, 0);
	DHparams_print_fp(stdout, dh2);

	/*
	 * Generate random RSA keys.
	 */
	printf("Generating RSA keys (%d bits)...\n", MODULUSLEN);
	rsa = RSA_generate_key(MODULUSLEN, 3, cb, "RSA_keys");
	printf("\n");
	if (rsa == NULL) {
		printf("RSA generate keys fails\n%s\n",
		    ERR_error_string(ERR_get_error(), NULL));
		exit (-1);
	}

	/*
	 * For signature encryption it is not necessary that the RSA
	 * parameters be strictly groomed and once in a while the
	 * modulus turns out to be non-prime. Just for grins, we check
	 * the primality. If this fails, disregard or run the program
	 * again.
	 */
	if (!RSA_check_key(rsa)) {
		printf("Invalid RSA key\n%s\n",
		    ERR_error_string(ERR_get_error(), NULL));
	}
	pkey = EVP_PKEY_new();
	EVP_PKEY_assign_RSA(pkey, rsa);
	str = fheader("RSAkey");
	PEM_write_RSAPrivateKey(str, rsa, NULL, NULL, 0, NULL, NULL);
	fclose(str);
	RSA_print_fp(stdout, pkey->pkey.rsa, 0);

	/*
	 * Generate X509v3 certificates. The digest algorithms that
	 * work with RSA are MD2, MD5, SHA, SHA1, MDC2 and RIPEMD160.
	 */
#ifdef HAVE_EVP_MD2
	x509("RSA_MD2", pkey, EVP_md2());
#endif
	x509("RSA_MD5", pkey, EVP_md5());
	x509("RSA_SHA", pkey, EVP_sha());
	x509("RSA_SHA1", pkey, EVP_sha1());
#ifdef HAVE_EVP_MDC2
	x509("RSA_MDC2", pkey, EVP_mdc2());
#endif
	x509("RSA_RIPEMD160", pkey, EVP_ripemd160());
	free(pkey);

	/*
	 * Generate DSA parameters.
	 */
	printf("Generating DSA parameters (%d bits)...\n", MODULUSLEN);
	dsa_params = DSA_generate_parameters(MODULUSLEN, seed,
	    sizeof(seed), NULL, NULL, cb, "DSA_params");
	printf("\n");
	if (dsa_params == NULL) {
		printf("DSA generate parameters fails\n%s\n",
		    ERR_error_string(ERR_get_error(), NULL));
		 exit (-1);
	}
	str = fheader("DSApar");
	PEM_write_DSAparams(str, dsa_params);
	fclose(str);

	/*
	 * Generate DSA keys. Note, the digest algorithms that work with
	 * DSS (DSA) are DSS and DSS1.
	 */
	printf("Generating DSA keys (%d bits)...\n", MODULUSLEN);
	if (!DSA_generate_key(dsa_params)) {
		printf("DSA generate keys fails\n%s\n",
		    ERR_error_string(ERR_get_error(), NULL));
		exit (-1);
	}
	pkey = EVP_PKEY_new();
	EVP_PKEY_assign_DSA(pkey, dsa_params);
	str = fheader("DSAkey");
	PEM_write_DSAPrivateKey(str, dsa_params, NULL, NULL, 0, NULL,
	    NULL);
	fclose(str);
	DSA_print_fp(stdout, pkey->pkey.dsa, 0);

	/*
	 * Generate X509v3 certificates. The digest algorithms that
	 * work with DSS (DSA) are DSS and DSS1.
	 */
	x509("DSA_SHA", pkey, EVP_dss());
	x509("DSA_SHA1", pkey, EVP_dss1());

#if 0
	/*
	 * Generate keys as DSA signatures.
	 */
	printf("Generating keys as DSA signatures...\n");
	str = fheader("SIGkey");
	temp = EVP_PKEY_size(pkey);
	sig = malloc(temp);
	EVP_SignInit(&ctx, EVP_dss());
	EVP_SignUpdate(&ctx, hostname, sizeof(hostname));
	EVP_SignFinal(&ctx, sig, &temp, pkey);
	PEM_write(str, "SIG_KEY", "header", sig, temp);
	EVP_VerifyInit(&ctx, EVP_dss());
	EVP_VerifyUpdate(&ctx, hostname, sizeof(hostname));
	temp = EVP_VerifyFinal(&ctx, sig, temp, pkey);
	fclose(str);
	free(pkey);
#endif
	OPENSSL_free(expa_hex);
	DH_free(dh_params);
#endif /* OPENSSL */
	return (0);
}


#ifdef OPENSSL
/*
 * Generate X509v3 self-signed certificate.
 *
 * The certificate certificate is saved as a file in the format
 * described in the main program. The certificate consists of the ASN.1
 * encoding of the version number, serial number, validity interval,
 * issuer name, subject name and public key. For a self-signed
 * certificate, the issuer name is the same as the subject name and
 * these items are signed using the subject private key. The validity
 * interval extends from the current time to the same time one year
 * hence. For NTP purposes, it is convenient to use the NTP seconds of
 * the current time as the serial number.
 *
 * The certificate extension containes a random string used in the IFF
 * scheme. The NID is currently borrowed from another application.
 * Should be fixed.
 */
int
x509	(
	u_char	*id,		/* host name */
	EVP_PKEY *pkey,		/* generic key algorithm */
	EVP_MD *md		/* generic digest algorithm */
	)
{
	X509	*cert;		/* X509 certificate */
	X509_NAME *subj;	/* distinguished (common) name */
	FILE	*str;		/* file handle */
	ASN1_INTEGER *serial;	/* serial number */
	X509V3_CTX ctx;		/* X509v3 context */
	X509_EXTENSION *ext;	/* X509v3 extension */
	u_char	pathbuf[PATH_MAX];

	/*
	 * Generate X509 self-signed certificate.
	 *
	 * Set the certificate serial to the NTP seconds for grins. Set
	 * the version to 3 if attributes are included and to 0
	 * otherwise. Set the subject name and issuer name to the
	 * subject name in the request. Set the initial validity to the
	 * current time and the final validity
	 * one year hence. 
	 */
	cert = X509_new();
	X509_set_version(cert, 2L);
	serial = ASN1_INTEGER_new();
	ASN1_INTEGER_set(serial, ntptime);
	X509_set_serialNumber(cert, serial);
	X509_gmtime_adj(X509_get_notBefore(cert), 0L);
	X509_gmtime_adj(X509_get_notAfter(cert), YEAR);
	subj = X509_get_subject_name(cert);
	X509_NAME_add_entry_by_txt(subj, "commonName", MBSTRING_ASC,
	    hostname, strlen(hostname), -1, 0);
	subj = X509_get_issuer_name(cert);
	X509_NAME_add_entry_by_txt(subj, "commonName", MBSTRING_ASC,
	    hostname, strlen(hostname), -1, 0);
	if (!X509_set_pubkey(cert, pkey)) {
		printf("Assign key fails\n%s\n",
		ERR_error_string(ERR_get_error(), NULL));
		return (-1);
	}

	/*
	 * Add X509v3 extensions.
	 */
	ext = X509V3_EXT_conf_nid(NULL, &ctx,
	    NID_subject_key_identifier, expa_hex);
	if (!ext) {
		printf("Extension field fails\n%s\n",
		ERR_error_string(ERR_get_error(), NULL));
		return (-1);
	}
	X509_add_ext(cert, ext, -1);
	X509_EXTENSION_free(ext);

	/*
	 * Sign and verify.
	 */
	X509_sign(cert, pkey, md);
	if (!X509_verify(cert, pkey)) {
		printf("Verify certificate fails\n%s\n",
		    ERR_error_string(ERR_get_error(), NULL));
		return (-1);
	}

	/*
	 * Write certificate for offline processing.
	 */
	sprintf(pathbuf, "%scert", id);
	str = fheader(pathbuf);
	PEM_write_X509(str, cert);
	X509_print_fp(stdout, cert);

	/*
	 * Give back the goodies.
	 */
	ASN1_INTEGER_free(serial);
	X509_free(cert);
	fclose(str);
	return (0);
}


/*
 * asn2ntp - convert ASN1_TIME time structure to NTP time
 */
u_long
asn2ntp	(
	ASN1_TIME *asn1time	/* pointer to ASN1_TIME structure */
	)
{
	char	*v;		/* pointer to ASN1_TIME string */
	struct	tm tm;		/* time decode structure time */

	/*
	 * Extract time string YYMMDDHHMMSSZ from ASN1 time structure.
	 * Note that the YY, MM, DD fields start with one, the HH, MM,
	 * SS fiels start with zero and the Z character should be 'Z'
	 * for UTC. Also note that years less than 50 map to years
	 * greater than 100. Dontcha love ASN.1?
	 */
	if (asn1time->length > 13)
		return (-1);
	v = (char *)asn1time->data;
	tm.tm_year = (v[0] - '0') * 10 + v[1] - '0';
	if (tm.tm_year < 50)
		tm.tm_year += 100;
	tm.tm_mon = (v[2] - '0') * 10 + v[3] - '0' - 1;
	tm.tm_mday = (v[4] - '0') * 10 + v[5] - '0';
	tm.tm_hour = (v[6] - '0') * 10 + v[7] - '0';
	tm.tm_min = (v[8] - '0') * 10 + v[9] - '0';
	tm.tm_sec = (v[10] - '0') * 10 + v[11] - '0';
	tm.tm_wday = 0;
	tm.tm_yday = 0;
	tm.tm_isdst = 0;
	return (mktime(&tm) + JAN_1970);
}


/*
 * Callback routine
 */
void
cb	(
	int	n1,		/* arg 1 */
	int	n2,		/* arg 2 */
	void	*chr		/* arg 3 */
	)
{
	switch (n1) {
	case 0:
		d0++;
		printf("%s %d %d %lu\r", chr, n1, n2, d0);
		break;
	case 1:
		d1++;
		printf("%s\t\t%d %d %lu\r", chr, n1, n2, d1);
		break;
	case 2:
		d2++;
		printf("%s\t\t\t\t%d %d %lu\r", chr, n1, n2, d2);
		break;
	case 3:
		d3++;
		printf("%s\t\t\t\t\t\t%d %d %lu\r", chr, n1, n2,
		    d3);
		break;
	}
}
#endif /* OPENSSL */


/*
 * Generate file header
 */
FILE *
fheader	(
	u_char	*id		/* ident string */
	)
{
	FILE	*str;		/* file handle */
	char	filename[PATH_MAX]; /* file name */

	sprintf(filename, "ntpkey_%s_%s.%lu", id, hostname, ntptime);
	str = fopen(filename, "w");

strcpy(ftemp, filename);

	fprintf(str, "# %s\n# %s", filename, ctime(&tv.tv_sec));
	return(str);
}


/*
 * i2d_IFFparams() - encode IFF parameters in ASN1
 *
 * This routine is modelled after the i2d_DHparams() routine in the
 * OpenSSL library, but modified to encode the private and public
 * values, as well as the prime and generator. In the IFF scheme, all of
 * these values are secret, but must be installed in all servers and
 * clients in the group.
 */
int i2d_IFFparams(
	DH	*a,		/* Diffie-Hellman parameters */
	u_char	**pp		/* ASN1 encoded string */
	)
{
	BIGNUM	*num[4];
	ASN1_INTEGER bs;
	u_int j, i, tot = 0, len, max = 0;
	int	t;
	u_char	*p;

	/*
	 * First, do some error checking and compute the total length.
	 */
	if (a == NULL)
		return (0);
	num[0] = a->p;
	num[1] = a->g;
	num[2] = a->priv_key;
	num[3] = a->pub_key;
	for (i = 0; i < 4; i++)	{
		if (num[i] == NULL)
			continue;
		j = BN_num_bits(num[i]);
		len = ((j == 0) ? 0 : ((j / 8) + 1));
		if (len > max)
			max = len;
		len = ASN1_object_size(0, len, (num[i]->neg) ?
		    V_ASN1_NEG_INTEGER : V_ASN1_INTEGER);
		tot += len;
	}

	t = ASN1_object_size(1, tot, V_ASN1_SEQUENCE);
	if (pp == NULL)
		return (t);

	/*
	 * Allocate the ASN1 string.
	 */
	p = *pp;
	ASN1_put_object(&p, 1, tot, V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL);
	bs.type = V_ASN1_INTEGER;
	bs.data = (u_char *)OPENSSL_malloc(max + 4);
	if (bs.data == NULL) {
		ASN1err(ASN1_F_I2D_DHPARAMS, ERR_R_MALLOC_FAILURE);
		return (0);
	}

	/*
	 * Encode the date as ASN1 integers. The order is prime,
	 * generator, private value, public value.
	 */
	for (i=0; i < 4; i++) {
		if (num[i] == NULL)
			continue;
		bs.length = BN_bn2bin(num[i], bs.data);
		i2d_ASN1_INTEGER(&bs, &p);
	}
	OPENSSL_free(bs.data);
	*pp = p;
	return (t);
}


/*
 * PEM_read_IFFparams - read IFF parameters encoded in ASN1 and PEM.
 *
 * This routine is modelled after the d2i_DHparams() routine in the
 * OpenSSL library, but modified to decode the private and public
 * values, as well as the prime and generator. In the IFF scheme, all of
 * these values are secret, but must be installed in all servers and
 * clients in the group.
 */
DH *d2i_IFFparams(
	DH	**a,		/* Diffie-Hellman parameters */
	u_char	**pp,		/* ASN1 encoded string */
	long	length		/* length of ASN1 encoded string */
	)
{
	int i = ERR_R_NESTED_ASN1_ERROR;
	ASN1_INTEGER *bs = NULL;
	long	v = 0;
	M_ASN1_D2I_vars(a, DH *, DH_new);

	/*
	 * Decode prime and generator.
	 */
	M_ASN1_D2I_Init();
	M_ASN1_D2I_start_sequence();
	M_ASN1_D2I_get(bs, d2i_ASN1_INTEGER);
	if ((ret->p = BN_bin2bn(bs->data, bs->length, ret->p)) == NULL)
		goto err_bn;
	M_ASN1_D2I_get(bs, d2i_ASN1_INTEGER);
	if ((ret->g = BN_bin2bn(bs->data, bs->length, ret->g)) == NULL)
		goto err_bn;

	/*
	 * Decode private and public values.
	 */
	M_ASN1_D2I_get(bs, d2i_ASN1_INTEGER);
	if ((ret->p = BN_bin2bn(bs->data, bs->length, ret->priv_key)) ==
	    NULL)
		goto err_bn;
	M_ASN1_D2I_get(bs, d2i_ASN1_INTEGER);
	if ((ret->g = BN_bin2bn(bs->data, bs->length, ret->pub_key)) ==
	    NULL)
		goto err_bn;

	if (!M_ASN1_D2I_end_sequence()) {
		M_ASN1_D2I_get(bs, d2i_ASN1_INTEGER);
		for (i = 0; i < bs->length; i++)
			v = (v << 8) | (bs->data[i]);
		ret->length = (int)v;
	}

	/*
	 * Opaque endgame.
	 */
	M_ASN1_BIT_STRING_free(bs);
	M_ASN1_D2I_Finish_2(a);

	/*
	 * Error stubs.
	 */
err_bn:
	i = ERR_R_BN_LIB;
err:
	ASN1err(ASN1_F_D2I_DHPARAMS, i);
	if ((ret != NULL) && ((a == NULL) || (*a != ret)))
		DH_free(ret);
	if (bs != NULL)
		M_ASN1_BIT_STRING_free(bs);
	return(NULL);
}
