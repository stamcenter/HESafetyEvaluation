#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint64_t RevInc(uint64_t,uint64_t);

uint64_t static_k[1];
uint64_t static_a[1];
uint64_t static_z[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_k = (uint64_t *) malloc(8);
  uint64_t *alloc_a = (uint64_t *) malloc(8);
  uint64_t *alloc_z = (uint64_t *) malloc(8);

  alloc_z[0] = RevInc(*alloc_a,*alloc_k);

  return 0;
}
