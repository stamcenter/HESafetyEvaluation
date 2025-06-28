#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint32_t evalpoly(uint64_t,uint64_t);

uint64_t static_i[1];
uint64_t static_m[1];
uint32_t static_z[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_i = (uint64_t *) malloc(8);
  uint64_t *alloc_m = (uint64_t *) malloc(8);
  uint32_t *alloc_z = (uint32_t *) malloc(4);

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_i[i] = x;
  }
  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_m[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_i[i] = static_i[i];
  for (long long i = 0;i < 1;++i)
    alloc_m[i] = static_m[i];

  alloc_z[0] = evalpoly(*alloc_i,*alloc_m);

  for (long long i = 0;i < 1;++i)
    static_z[i] = alloc_z[i];

  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_z[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
