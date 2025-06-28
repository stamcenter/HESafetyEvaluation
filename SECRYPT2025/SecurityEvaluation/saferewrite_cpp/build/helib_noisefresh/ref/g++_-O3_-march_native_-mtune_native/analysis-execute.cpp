#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const void boundFreshNoise(uint64_t,uint64_t);

uint64_t static_m[1];
uint64_t static_phim[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_m = (uint64_t *) malloc(8);
  uint64_t *alloc_phim = (uint64_t *) malloc(8);

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_m[i] = x;
  }
  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_phim[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_m[i] = static_m[i];
  for (long long i = 0;i < 1;++i)
    alloc_phim[i] = static_phim[i];

  boundFreshNoise(*alloc_m,*alloc_phim);



  return 0;
}
