#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const void Cipher(uint8_t *,uint8_t *,uint8_t *);

uint8_t static_in[1522];
uint8_t static_out[1522];
uint8_t static_roundkey[1522];

int main(int argc,char **argv)
{
  uint8_t *alloc_in = (uint8_t *) malloc(1522);
  uint8_t *alloc_out = (uint8_t *) malloc(1522);
  uint8_t *alloc_roundkey = (uint8_t *) malloc(1522);

  for (long long i = 0;i < 1522;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_in[i] = x;
  }

  for (long long i = 0;i < 1522;++i)
    alloc_in[i] = static_in[i];

  Cipher(alloc_out,alloc_in,alloc_roundkey);

  for (long long i = 0;i < 1522;++i)
    static_out[i] = alloc_out[i];
  for (long long i = 0;i < 1522;++i)
    static_roundkey[i] = alloc_roundkey[i];

  for (long long i = 0;i < 1522;++i) {
    unsigned long long x = static_out[i];
    printf("%llu\n",x);
  }
  fflush(stdout);
  for (long long i = 0;i < 1522;++i) {
    unsigned long long x = static_roundkey[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
