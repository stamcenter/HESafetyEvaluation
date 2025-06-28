#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void sha3_512(uint8_t *,uint8_t *);

uint8_t static_in[64];
uint8_t static_h[8];

int main(int argc,char **argv)
{
  uint8_t *alloc_in = malloc(64);
  uint8_t *alloc_h = malloc(8);

  for (long long i = 0;i < 64;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_in[i] = x;
  }

  for (long long i = 0;i < 64;++i)
    alloc_in[i] = static_in[i];

  sha3_512(alloc_in,alloc_h);

  for (long long i = 0;i < 8;++i)
    static_h[i] = alloc_h[i];

  for (long long i = 0;i < 8;++i) {
    unsigned long long x = static_h[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
