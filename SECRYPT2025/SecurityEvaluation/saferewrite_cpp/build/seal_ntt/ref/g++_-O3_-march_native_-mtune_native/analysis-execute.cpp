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

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_factor[i] = x;
  }
  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_bitsize[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_factor[i] = static_factor[i];
  for (long long i = 0;i < 1;++i)
    alloc_bitsize[i] = static_bitsize[i];

  alloc_z[0] = verify(*alloc_factor,*alloc_bitsize);

  for (long long i = 0;i < 1;++i)
    static_z[i] = alloc_z[i];

  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_z[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
