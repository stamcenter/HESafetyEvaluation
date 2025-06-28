#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const void powdouble(uint64_t);

uint64_t static_n[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_n = (uint64_t *) malloc(8);

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_n[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_n[i] = static_n[i];

  powdouble(*alloc_n);



  return 0;
}
