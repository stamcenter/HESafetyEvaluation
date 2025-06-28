#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint32_t store32(uint32_t *,uint8_t);

uint32_t static_w[32];
uint8_t static_dst[1];
uint32_t static_a[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_w = malloc(128);
  uint8_t *alloc_dst = malloc(1);
  uint32_t *alloc_a = malloc(4);

  for (long long i = 0;i < 32;++i)
    alloc_w[i] = static_w[i];
  for (long long i = 0;i < 1;++i)
    alloc_dst[i] = static_dst[i];

  alloc_a[0] = store32(alloc_w,*alloc_dst);

  for (long long i = 0;i < 1;++i)
    static_dst[i] = alloc_dst[i];
  for (long long i = 0;i < 1;++i)
    static_a[i] = alloc_a[i];

  return 0;
}
