#include "config.h"
#include "unity.h"

#ifdef OPENSSL
# include "openssl/err.h"
# include "openssl/rand.h"
# include "openssl/evp.h"
#endif
#include "ntp.h"
#include "ntp_stdlib.h"

u_long current_time = 4;


/*
 * Example packet with MD5 hash calculated manually.
 */
const int keytype = KEY_TYPE_MD5;
const u_char *key = (const u_char*)"abcdefgh";
const u_short keyLength = 8;
const u_char *packet = (const u_char*)"ijklmnopqrstuvwx";
#define packetLength 16
#define keyIdLength  4
#define digestLength 16
#define totalLength (packetLength + keyIdLength + digestLength)
union {
	u_char		u8 [totalLength];
	uint32_t	u32[1];
} expectedPacket = {
	"ijklmnopqrstuvwx\0\0\0\0\x0c\x0e\x84\xcf\x0b\xb7\xa8\x68\x8e\x52\x38\xdb\xbc\x1c\x39\x53"
};
union {
	u_char		u8 [totalLength];
	uint32_t	u32[1];
} invalidPacket = {
	"ijklmnopqrstuvwx\0\0\0\0\x0c\x0e\x84\xcf\x0b\xb7\xa8\x68\x8e\x52\x38\xdb\xbc\x1c\x39\x54"
};

static const keyid_t keyId = 42;

void test_Encrypt(void);
void test_DecryptValid(void);
void test_DecryptInvalid(void);
void test_IPv4AddressToRefId(void);
void test_IPv6AddressToRefId(void);


void
test_Encrypt(void) {
	u_int32 *packetPtr;
	int length;

	packetPtr = emalloc_zero(totalLength * sizeof(*packetPtr));
	memcpy(packetPtr, packet, packetLength);

	length = MD5authencrypt(keytype, key, keyLength, packetPtr, packetLength);

	TEST_ASSERT_TRUE(MD5authdecrypt(keytype, key, keyLength, packetPtr, packetLength, length, keyId));

	TEST_ASSERT_EQUAL(20, length);
	TEST_ASSERT_EQUAL_MEMORY(expectedPacket.u8, packetPtr, totalLength);

	free(packetPtr);
}

void
test_DecryptValid(void) {
	TEST_ASSERT_TRUE(MD5authdecrypt(keytype, key, keyLength, expectedPacket.u32, packetLength, 20, keyId));
}

void
test_DecryptInvalid(void) {
	TEST_ASSERT_FALSE(MD5authdecrypt(keytype, key, keyLength, invalidPacket.u32, packetLength, 20, keyId));
}

void
test_IPv4AddressToRefId(void) {
	sockaddr_u	addr;
	u_int32		addr4n;

	AF(&addr) = AF_INET;
	SET_PORT(&addr, htons(80));
	addr4n = inet_addr("192.0.2.1");
	NSRCADR(&addr) = addr4n;

	TEST_ASSERT_EQUAL_UINT32(addr4n, addr2refid(&addr));
}

void
test_IPv6AddressToRefId(void) {
	const int expected = 0x75cffd52;
	const struct in6_addr address = { { {
		0x20, 0x01, 0x0d, 0xb8,
		0x85, 0xa3, 0x08, 0xd3,
		0x13, 0x19, 0x8a, 0x2e,
		0x03, 0x70, 0x73, 0x34
	} } };
	sockaddr_u addr;

	AF(&addr) = AF_INET6;
	SOCK_ADDR6(&addr) = address;

	TEST_ASSERT_EQUAL(expected, addr2refid(&addr));
}
