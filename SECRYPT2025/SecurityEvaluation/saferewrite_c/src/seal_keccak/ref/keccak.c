#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int keccak(uint64_t s[25],
                         uint32_t r,
                          const uint8_t *m,
                          uint8_t p)
{
  size_t mlen = 8;
  size_t i;
  uint8_t t[200] = {0};

  /* Zero state */
  for(i=0;i<25;i++)
    s[i] = 0;

  while(mlen >= r) {
    for(i=0;i<r/8;i++)
     // s[i] ^= load64(m + 8*i);

    //KeccakF1600_StatePermute(s);
    mlen -= r;
    m += r;
  }

  for(i=0;i<mlen;i++)
    t[i] = m[i];
  t[i] = p;
  t[r-1] |= 128;
  for(i=0;i<r/8;i++)
    //s[i] ^= load64(t + 8*i);
    s[i] = t[i] + 8*i;
  return 0;
}

