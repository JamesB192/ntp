/*
 * HMS: we need to test:
 * - OpenSSL versions, if we are building with them
 * - our versions
 *
 * We may need to test with(out) OPENSSL separately.
 */

#include <config.h>
#include "crypto.h"
#include <ctype.h>
#include "isc/string.h"
#include "ntp_md5.h"

/* HMS: We may not have OpenSSL, but we have our own AES-128-CMAC */
#define  CMAC		"AES128CMAC"
#ifdef OPENSSL
# include "openssl/cmac.h"
#endif

struct key *key_ptr;
size_t key_cnt = 0;

int
make_mac(
	const void *pkt_data,
	int pkt_size,
	int mac_size,
	const struct key *cmp_key,
	void * digest
	)
{
	u_int		len  = 0;
	size_t		slen = 0;
	int		key_type;
	
	if (cmp_key->key_len > 64)
		return 0;
	if (pkt_size % 4 != 0)
		return 0;

	INIT_SSL();
	key_type = keytype_from_text(cmp_key->typen, NULL);

#ifdef OPENSSL
	/* Check if CMAC key type specific code required */
	if (key_type == NID_cmac) {
		CMAC_CTX *      ctx;
		
		if (debug) {
			fprintf(stderr, "%s:%d:%s():%s:nid\n",
				__FILE__, __LINE__, __func__, CMAC);
		}
		
		if (!(ctx = CMAC_CTX_new())) {
			fprintf(stderr,  "make_mac: CMAC %s CTX new failed.\n", CMAC);
			msyslog(LOG_ERR, "make_mac: CMAC %s CTX new failed.",   CMAC);
		}
		else if (!CMAC_Init(ctx, cmp_key->key_seq,
				    (size_t)cmp_key->key_len, EVP_aes_128_cbc(), NULL)) {
			fprintf(stderr,  "make_mac: CMAC %s Init failed.\n",    CMAC);
			msyslog(LOG_ERR, "make_mac: CMAC %s Init failed.",      CMAC);
		}
		else if (!CMAC_Update(ctx, pkt_data, (size_t)pkt_size)) {
			fprintf(stderr,  "make_mac: CMAC %s Update failed.\n",  CMAC);
			msyslog(LOG_ERR, "make_mac: CMAC %s Update failed.",    CMAC);
		}
		else if (!CMAC_Final(ctx, digest, &slen)) {
			fprintf(stderr,  "make_mac: CMAC %s Final failed.\n",   CMAC);
			msyslog(LOG_ERR, "make_mac: CMAC %s Final failed.",     CMAC);
			slen = 0;
		}
		len = (u_int)slen;
		
		CMAC_CTX_cleanup(ctx);
		/* Test our AES-128-CMAC implementation */
		
	} else	/* MD5 MAC handling */
#endif
	{
		EVP_MD_CTX *	ctx;
		
		if (!(ctx = EVP_MD_CTX_new())) {
			fprintf(stderr,  "make_mac: MAC %s Digest CTX new failed.\n",
				cmp_key->typen);
			msyslog(LOG_ERR, "make_mac: MAC %s Digest CTX new failed.",
				cmp_key->typen);
		}
#ifdef OPENSSL	/* OpenSSL 1 supports return codes 0 fail, 1 okay */
		else if (!EVP_DigestInit(ctx, EVP_get_digestbynid(key_type))) {
			fprintf(stderr,  "make_mac: MAC %s Digest Init failed.\n",
				cmp_key->typen);
			msyslog(LOG_ERR, "make_mac: MAC %s Digest Init failed.",
				cmp_key->typen);
		}
		else if (!EVP_DigestUpdate(ctx, (const u_char *)cmp_key->key_seq,
					   (u_int)cmp_key->key_len)) {
			fprintf(stderr,  "make_mac: MAC %s Digest Update key failed.\n",
				cmp_key->typen);
			msyslog(LOG_ERR, "make_mac: MAC %s Digest Update key failed.",
				cmp_key->typen);
		}
		else if (!EVP_DigestUpdate(ctx, pkt_data, (u_int)pkt_size)) {
			fprintf(stderr,  "make_mac: MAC %s Digest Update data failed.\n",
				cmp_key->typen);
			msyslog(LOG_ERR, "make_mac: MAC %s Digest Update data failed.",
				cmp_key->typen);
		}
		else if (!EVP_DigestFinal(ctx, digest, &len)) {
			fprintf(stderr,  "make_mac: MAC %s Digest Final failed.\n",
				cmp_key->typen);
			msyslog(LOG_ERR, "make_mac: MAC %s Digest Final failed.",
				cmp_key->typen);
			len = 0;
		}
#else /* !OPENSSL */
		EVP_DigestInit(ctx, EVP_get_digestbynid(key_type));
		EVP_DigestUpdate(ctx, (const u_char *)cmp_key->key_seq,
				 (u_int)cmp_key->key_len);
		EVP_DigestUpdate(ctx, pkt_data, (u_int)pkt_size);
		EVP_DigestFinal(ctx, digest, &len);
#endif
		
		EVP_MD_CTX_free(ctx);
	}
	
	return (int)len;
}


/* Generates a md5 digest of the key specified in keyid concatenated with the
 * ntp packet (exluding the MAC) and compares this digest to the digest in
 * the packet's MAC. If they're equal this function returns 1 (packet is
 * authentic) or else 0 (not authentic).
 */
int
auth_md5(
	const void *pkt_data,
	int pkt_size,
	int mac_size,
	const struct key *cmp_key
	)
{
	int  hash_len;
	int  authentic;
	char digest[MAX_MDG_LEN];
	const u_char *pkt_ptr;
	if (mac_size > (int)sizeof(digest))
		return 0;
	pkt_ptr = pkt_data;
	hash_len = make_mac(pkt_ptr, pkt_size, sizeof(digest), cmp_key,
			    digest);
	if (!hash_len) {
		authentic = FALSE;
	} else {
		/* isc_tsmemcmp will be better when its easy to link
		 * with.  sntp is a 1-shot program, so snooping for
		 * timing attacks is Harder.
		 */
		authentic = !memcmp(digest, (const char*)pkt_data + pkt_size + 4,
				    hash_len);
	}
	return authentic;
}

static int
hex_val(
	unsigned char x
	)
{
	int val;

	if ('0' <= x && x <= '9')
		val = x - '0';
	else if ('a' <= x && x <= 'f')
		val = x - 'a' + 0xa;
	else if ('A' <= x && x <= 'F')
		val = x - 'A' + 0xA;
	else
		val = -1;

	return val;
}

/* Load keys from the specified keyfile into the key structures.
 * Returns -1 if the reading failed, otherwise it returns the
 * number of keys it read
 */
int
auth_init(
	const char *keyfile,
	struct key **keys
	)
{
	FILE *keyf = fopen(keyfile, "r");
	struct key *prev = NULL;
	int scan_cnt, line_cnt = 0;
	char kbuf[200];
	char keystring[129];

	INIT_SSL();
	
	if (keyf == NULL) {
		if (debug)
			printf("sntp auth_init: Couldn't open key file %s for reading!\n", keyfile);
		return -1;
	}
	if (feof(keyf)) {
		if (debug)
			printf("sntp auth_init: Key file %s is empty!\n", keyfile);
		fclose(keyf);
		return -1;
	}
	key_cnt = 0;
	while (!feof(keyf)) {
		char * octothorpe;
		struct key *act;
		int goodline = 0;

		if (NULL == fgets(kbuf, sizeof(kbuf), keyf))
			continue;

		kbuf[sizeof(kbuf) - 1] = '\0';
		octothorpe = strchr(kbuf, '#');
		if (octothorpe)
			*octothorpe = '\0';
		act = emalloc(sizeof(*act));
		/* keep width 15 = sizeof struct key.typen - 1 synced */
		scan_cnt = sscanf(kbuf, "%d %15s %128s",
					&act->key_id, act->typen, keystring);
		if (scan_cnt == 3) {
			int len = strlen(keystring);
			goodline = 1;	/* assume best for now */
			if (len <= 20) {
				act->key_len = len;
				memcpy(act->key_seq, keystring, len + 1);
			} else if ((len & 1) != 0) {
				goodline = 0; /* it's bad */
			} else {
				int j;
				act->key_len = len >> 1;
				for (j = 0; j < len; j+=2) {
					int val;
					val = (hex_val(keystring[j]) << 4) |
					       hex_val(keystring[j+1]);
					if (val < 0) {
						goodline = 0; /* it's bad */
						break;
					}
					act->key_seq[j>>1] = (char)val;
				}
			}
			act->typei = keytype_from_text(act->typen, NULL);
			if (0 == act->typei)
				goodline = 0; /* it's bad */
		}
		if (goodline) {
			act->next = NULL;
			if (NULL == prev)
				*keys = act;
			else
				prev->next = act;
			prev = act;
			key_cnt++;
		} else {
			msyslog(LOG_DEBUG, "auth_init: scanf %d items, skipping line %d.",
				scan_cnt, line_cnt);
			free(act);
		}
		line_cnt++;
	}
	fclose(keyf);

	key_ptr = *keys;
	return key_cnt;
}

/* Looks for the key with keyid key_id and sets the d_key pointer to the
 * address of the key. If no matching key is found the pointer is not touched.
 */
void
get_key(
	int key_id,
	struct key **d_key
	)
{
	struct key *itr_key;

	if (key_cnt == 0)
		return;
	for (itr_key = key_ptr; itr_key; itr_key = itr_key->next) {
		if (itr_key->key_id == key_id) {
			*d_key = itr_key;
			break;
		}
	}
	return;
}
