#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint64_t getCyclicOrder(uint32_t,uint32_t,uint32_t);

uint32_t static_a[1];
uint32_t static_b[1];
uint32_t static_c[1];
uint64_t static_d[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_a = (uint32_t *) malloc(4);
  uint32_t *alloc_b = (uint32_t *) malloc(4);
  uint32_t *alloc_c = (uint32_t *) malloc(4);
  uint64_t *alloc_d = (uint64_t *) malloc(8);

  alloc_d[0] = getCyclicOrder(*alloc_a,*alloc_b,*alloc_c);

  return 0;
}
