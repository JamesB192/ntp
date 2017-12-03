#include <stdio.h>
#include <openssl/cmac.h>

void printBytes(unsigned char *buf, size_t len) {
  for(int i=0; i<len; i++) {
    printf("%02x ", buf[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  // https://tools.ietf.org/html/rfc4493

  // K, M and T from 
  // http://csrc.nist.gov/publications/nistpubs/800-38B/Updated_CMAC_Examples.pdf
  // D.1 AES-128

  // now from https://csrc.nist.gov/CSRC/media/Projects/Cryptographic-Standards-and-Guidelines/documents/examples/AES_CMAC.pdf

  // K: 2b7e1516 28aed2a6 abf71588 09cf4f3c (Key)
  unsigned char key[] = { 0x2b,0x7e,0x15,0x16, 
                          0x28,0xae,0xd2,0xa6,
                          0xab,0xf7,0x15,0x88,
                          0x09,0xcf,0x4f,0x3c};

  // M: 6bc1bee2 2e409f96 e93d7e11 7393172a Mlen: 128 (PT)
  unsigned char message[] = { 0x6b,0xc1,0xbe,0xe2, 
                              0x2e,0x40,0x9f,0x96, 
                              0xe9,0x3d,0x7e,0x11, 
                              0x73,0x93,0x17,0x2a };

  unsigned char mact[16] = {0}; 
  size_t mactlen;

  CMAC_CTX *ctx = CMAC_CTX_new();
  CMAC_Init(ctx, key, 16, EVP_aes_128_cbc(), NULL);
  printf("message length = %lu bytes (%lu bits)\n",sizeof(message), sizeof(message)*8);

  CMAC_Update(ctx, message, sizeof(message));
  CMAC_Final(ctx, mact, &mactlen);

  printBytes(mact, mactlen);
  /* expected result T = 070a16b4 6b4d4144 f79bdd9d d04a287c (outBloc) */

// K: 2B7E1516 28AED2A6 ABF71588 09CF4F3C
// Mlen: 0
// M: <nothing>
// T: BB1D6929 E9593728 7FA37D12 9B756746
//
// K: 2B7E1516 28AED2A6 ABF71588 09CF4F3C
// Mlen: 16
// M: 6BC1BEE2 2E409F96 E93D7E11 7393172A
// T: 070A16B4 6B4D4144 F79BDD9D D04A287C
//
// K: 2B7E1516 28AED2A6 ABF71588 09CF4F3C
// Mlen: 20
// M: 6BC1BEE2 2E409F96 E93D7E11 7393172A AE2D8A57
// T: 7D85449E A6EA19C8 23A7BF78 837DFADE
//
// K: 2B7E1516 28AED2A6 ABF71588 09CF4F3C
// Mlen: 64
// M: 
//    6BC1BEE2 2E409F96 E93D7E11 7393172A
//    AE2D8A57 1E03AC9C 9EB76FAC 45AF8E51
//    30C81C46 A35CE411 E5FBC119 1A0A52EF
//    F69F2445 DF4F9B17 AD2B417B E66C3710
// T: 51F0BEBF 7E3B9D92 FC497417 79363CFE
  CMAC_CTX_free(ctx);
  return 0;
}
