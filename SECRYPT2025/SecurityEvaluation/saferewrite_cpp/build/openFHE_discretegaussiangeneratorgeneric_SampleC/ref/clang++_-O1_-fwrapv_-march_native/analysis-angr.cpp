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

  for (long long i = 0;i < 1;++i)
    alloc_center[i] = static_center[i];

  alloc_c[0] = SampleC(*alloc_center);

  for (long long i = 0;i < 1;++i)
    static_c[i] = alloc_c[i];

  return 0;
}
