#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define SHAKE256_RATE 136
typedef struct
{
  uint64_t s[25];
} keccak_state;

void shake256_squeezeblocks(uint8_t *out, size_t nblocks, keccak_state *state)
{
  //keccak_squeezeblocks(out, nblocks, state->s, SHAKE256_RATE);
  
}

void shake256(uint8_t *out)
{
   size_t outlen = 64;
  unsigned int i;
  size_t nblocks = outlen/SHAKE256_RATE;
  uint8_t t[SHAKE256_RATE];
  keccak_state state;

  //shake256_absorb(&state, in, inlen);
  //shake256_squeezeblocks(out, nblocks, &state);

  out += nblocks*SHAKE256_RATE;
  outlen -= nblocks*SHAKE256_RATE;

  if(outlen) {
    shake256_squeezeblocks(t, 1, &state);
    for(i=0;i<outlen;i++)
      out[i] = t[i];
  }
}
