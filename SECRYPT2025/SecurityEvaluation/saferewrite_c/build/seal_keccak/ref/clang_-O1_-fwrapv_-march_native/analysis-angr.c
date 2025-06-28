#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint32_t keccak(uint64_t *,uint32_t *,uint8_t *,uint8_t *);

uint32_t static_r[32];
uint8_t static_m[256];
uint8_t static_p[8];
uint64_t static_s[25];
uint32_t static_a[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_r = malloc(128);
  uint8_t *alloc_m = malloc(256);
  uint8_t *alloc_p = malloc(8);
  uint64_t *alloc_s = malloc(200);
  uint32_t *alloc_a = malloc(4);

  for (long long i = 0;i < 32;++i)
    alloc_r[i] = static_r[i];
  for (long long i = 0;i < 256;++i)
    alloc_m[i] = static_m[i];
  for (long long i = 0;i < 8;++i)
    alloc_p[i] = static_p[i];

  alloc_a[0] = keccak(alloc_s,alloc_r,alloc_m,alloc_p);

  for (long long i = 0;i < 25;++i)
    static_s[i] = alloc_s[i];
  for (long long i = 0;i < 256;++i)
    static_m[i] = alloc_m[i];
  for (long long i = 0;i < 1;++i)
    static_a[i] = alloc_a[i];

  return 0;
}
