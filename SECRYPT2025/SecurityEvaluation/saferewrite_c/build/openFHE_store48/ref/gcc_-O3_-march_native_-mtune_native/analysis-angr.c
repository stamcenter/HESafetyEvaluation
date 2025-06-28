#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint32_t store48(uint32_t *,uint8_t *);

uint32_t static_w[32];
uint8_t static_d[256];
uint32_t static_a[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_w = malloc(128);
  uint8_t *alloc_d = malloc(256);
  uint32_t *alloc_a = malloc(4);

  for (long long i = 0;i < 32;++i)
    alloc_w[i] = static_w[i];

  alloc_a[0] = store48(alloc_w,alloc_d);

  for (long long i = 0;i < 256;++i)
    static_d[i] = alloc_d[i];
  for (long long i = 0;i < 1;++i)
    static_a[i] = alloc_a[i];

  return 0;
}
