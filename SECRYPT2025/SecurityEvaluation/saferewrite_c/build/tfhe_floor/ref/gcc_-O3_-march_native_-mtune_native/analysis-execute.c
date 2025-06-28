#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint32_t floor_log2(uint64_t *);

uint64_t static_n[1];
uint32_t static_z[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_n = malloc(8);
  uint32_t *alloc_z = malloc(4);

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_n[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_n[i] = static_n[i];

  alloc_z[0] = floor_log2(alloc_n);

  for (long long i = 0;i < 1;++i)
    static_z[i] = alloc_z[i];

  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_z[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
