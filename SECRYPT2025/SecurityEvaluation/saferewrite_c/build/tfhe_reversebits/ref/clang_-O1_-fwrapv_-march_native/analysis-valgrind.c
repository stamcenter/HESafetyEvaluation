#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint64_t reverse_bits(uint64_t,uint32_t);

uint64_t static_x[1];
uint32_t static_n[1];
uint64_t static_z[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_x = malloc(8);
  uint32_t *alloc_n = malloc(4);
  uint64_t *alloc_z = malloc(8);

  alloc_z[0] = reverse_bits(*alloc_x,*alloc_n);

  return 0;
}
