#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "aes_wrap.h"

#if 0

		*****	We want RFC 4493, not 4434.   *****

RFC 4434               AES-XCBC-PRF-128 Algorithm          February 2006

   The key for AES-XCBC-PRF-128 is created as follows:

   o  If the key is exactly 128 bits long, use it as-is.

   o  If the key has fewer than 128 bits, lengthen it to exactly 128
      bits by padding it on the right with zero bits.

   o  If the key is 129 bits or longer, shorten it to exactly 128 bits
      by performing the steps in AES-XCBC-PRF-128 (that is, the
      algorithm described in this document).  In that re-application of
      this algorithm, the key is 128 zero bits; the message is the
      too-long current key.

2.1.  Test Vectors

   Test Case AES-XCBC-PRF-128 with 20-byte input
   Key        : 000102030405060708090a0b0c0d0e0f
   Key Length : 16
   Message    : 000102030405060708090a0b0c0d0e0f10111213
   PRF Output : 47f51b4564966215b8985c63055ed308

   Test Case AES-XCBC-PRF-128 with 20-byte input
   Key        : 00010203040506070809
   Key Length : 10
   Message    : 000102030405060708090a0b0c0d0e0f10111213
   PRF Output : 0fa087af7d866e7653434e602fdde835

   Test Case AES-XCBC-PRF-128 with 20-byte input
   Key        : 000102030405060708090a0b0c0d0e0fedcb
   Key Length : 18
   Message    : 000102030405060708090a0b0c0d0e0f10111213
   PRF Output : 8cd3c93ae598a9803006ffb67c40e9e4
#endif

struct testv {
	char * key;
	int keylen;
	char * msg;
	int msglen;
	char * result;
	int reslen;
};

struct testv tv[] = {
	{ 
	  (char[]) { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },
	  16,
	  (char[]) { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13 },
	  20,
	  (char[]) { 0x47, 0xf5, 0x1b, 0x45, 0x64, 0x96, 0x62, 0x15, 0xb8, 0x98, 0x5c, 0x63, 0x05, 0x5e, 0xd3, 0x08 },
	  16
	},

	{
	  (char[]) { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09 },
	  10,
	  (char[]) { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13 },
	  20,
	  (char[]) { 0x0f, 0xa0, 0x87, 0xaf, 0x7d, 0x86, 0x6e, 0x76, 0x53, 0x43, 0x4e, 0x60, 0x2f, 0xdd, 0xe8, 0x35 },
	  16
	},

	{
	  (char[]) { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xed, 0xcb },
	  18,
	  (char[]) { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13 },
	  20,
	  (char[]) { 0x8c, 0xd3, 0xc9, 0x3a, 0xe5, 0x98, 0xa9, 0x80, 0x30, 0x06, 0xff, 0xb6, 0x7c, 0x40, 0xe9, 0xe4 },
	  16
	}
};

int
main()
{
	int i;
	int rc;
	char resp[16];

	for (i = 0; i < sizeof tv / sizeof tv[0]; ++i) {
		rc = omac1_aes_128_vector(
			tv[i].key,
			1,
			tv[i].msg,
			tv[i].msglen,
			&resp);
		printf("Case %d: rc %d, cmp %d\n", i, rc, memcmp(tv[i].result, &resp, 16));
	}
	exit(0);
}

#if 0

/**
 * omac1_aes_128_vector - One-Key CBC MAC (OMAC1) hash with AES-128
 * @key: 128-bit key for the hash operation
 * @num_elem: Number of elements in the data vector
 * @addr: Pointers to the data areas
 * @len: Lengths of the data blocks
 * @mac: Buffer for MAC (128 bits, i.e., 16 bytes)
 * Returns: 0 on success, -1 on failure
 *
 * This is a mode for using block cipher (AES in this case) for authentication.
 * OMAC1 was standardized with the name CMAC by NIST in a Special Publication
 * (SP) 800-38B.
 */
int omac1_aes_128_vector(const u8 *key, size_t num_elem,
			 const u8 *addr[], const size_t *len, u8 *mac)
#endif
