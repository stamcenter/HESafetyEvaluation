#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define SHA3_256_RATE 136

void sha3_256(uint8_t h[32], const uint8_t *in)
{
  unsigned int i;
  //uint64_t s[25];
  uint8_t t[SHA3_256_RATE];

  //keccak_absorb(s, SHA3_256_RATE, in, inlen, 0x06);
  //keccak_squeezeblocks(t, 1, s, SHA3_256_RATE);

  for(i=0;i<32;i++)
    h[i] = t[i];
}
