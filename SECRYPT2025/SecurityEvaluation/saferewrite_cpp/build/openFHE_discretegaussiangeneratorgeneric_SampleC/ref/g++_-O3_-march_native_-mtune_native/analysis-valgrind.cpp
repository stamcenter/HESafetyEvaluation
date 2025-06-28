#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint32_t SampleC(uint64_t);

uint64_t static_center[1];
uint32_t static_c[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_center = (uint64_t *) malloc(8);
  uint32_t *alloc_c = (uint32_t *) malloc(4);

  alloc_c[0] = SampleC(*alloc_center);

  return 0;
}
