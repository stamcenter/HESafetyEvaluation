#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint64_t exponentiate_uint_safe(uint64_t,uint64_t);

uint64_t static_operand[1];
uint64_t static_exponent[1];
uint64_t static_z[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_operand = (uint64_t *) malloc(8);
  uint64_t *alloc_exponent = (uint64_t *) malloc(8);
  uint64_t *alloc_z = (uint64_t *) malloc(8);

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_operand[i] = x;
  }
  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_exponent[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_operand[i] = static_operand[i];
  for (long long i = 0;i < 1;++i)
    alloc_exponent[i] = static_exponent[i];

  alloc_z[0] = exponentiate_uint_safe(*alloc_operand,*alloc_exponent);

  for (long long i = 0;i < 1;++i)
    static_z[i] = alloc_z[i];

  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_z[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
