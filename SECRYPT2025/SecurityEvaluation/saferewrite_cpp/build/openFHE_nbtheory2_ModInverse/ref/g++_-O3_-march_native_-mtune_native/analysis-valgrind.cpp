#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint32_t ModInverse(uint32_t,uint32_t);

uint32_t static_a[1];
uint32_t static_b[1];
uint32_t static_x[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_a = (uint32_t *) malloc(4);
  uint32_t *alloc_b = (uint32_t *) malloc(4);
  uint32_t *alloc_x = (uint32_t *) malloc(4);

  alloc_x[0] = ModInverse(*alloc_a,*alloc_b);

  return 0;
}
