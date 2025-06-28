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

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_k[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_k[i] = static_k[i];

  alloc_z[0] = RevInc(*alloc_a,*alloc_k);

  for (long long i = 0;i < 1;++i)
    static_a[i] = alloc_a[i];
  for (long long i = 0;i < 1;++i)
    static_z[i] = alloc_z[i];

  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_a[i];
    printf("%llu\n",x);
  }
  fflush(stdout);
  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_z[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
