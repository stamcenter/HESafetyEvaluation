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

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_a[i] = x;
  }
  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_b[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_a[i] = static_a[i];
  for (long long i = 0;i < 1;++i)
    alloc_b[i] = static_b[i];

  alloc_x[0] = ModInverse(*alloc_a,*alloc_b);

  for (long long i = 0;i < 1;++i)
    static_x[i] = alloc_x[i];

  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_x[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
