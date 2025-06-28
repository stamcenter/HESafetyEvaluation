#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint32_t verify(uint64_t,uint32_t);

uint64_t static_factor[1];
uint32_t static_bitsize[1];
uint32_t static_z[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_factor = (uint64_t *) malloc(8);
  uint32_t *alloc_bitsize = (uint32_t *) malloc(4);
  uint32_t *alloc_z = (uint32_t *) malloc(4);

  alloc_z[0] = verify(*alloc_factor,*alloc_bitsize);

  return 0;
}
