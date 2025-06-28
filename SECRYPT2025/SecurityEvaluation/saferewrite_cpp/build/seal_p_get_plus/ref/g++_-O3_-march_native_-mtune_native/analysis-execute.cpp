#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint8_t get_plus(uint8_t *);

uint8_t static_poly[32];
uint8_t static_z[1];

int main(int argc,char **argv)
{
  uint8_t *alloc_poly = (uint8_t *) malloc(32);
  uint8_t *alloc_z = (uint8_t *) malloc(1);

  for (long long i = 0;i < 32;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_poly[i] = x;
  }

  for (long long i = 0;i < 32;++i)
    alloc_poly[i] = static_poly[i];

  alloc_z[0] = get_plus(alloc_poly);

  for (long long i = 0;i < 1;++i)
    static_z[i] = alloc_z[i];

  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_z[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
