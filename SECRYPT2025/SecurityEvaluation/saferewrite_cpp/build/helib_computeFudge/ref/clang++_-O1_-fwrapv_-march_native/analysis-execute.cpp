#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const void compute_fudge(uint64_t,uint64_t);

uint64_t static_peprime[1];
uint64_t static_pe[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_peprime = (uint64_t *) malloc(8);
  uint64_t *alloc_pe = (uint64_t *) malloc(8);

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_peprime[i] = x;
  }
  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_pe[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_peprime[i] = static_peprime[i];
  for (long long i = 0;i < 1;++i)
    alloc_pe[i] = static_pe[i];

  compute_fudge(*alloc_peprime,*alloc_pe);



  return 0;
}
