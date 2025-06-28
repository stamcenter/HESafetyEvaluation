#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void shake256(uint8_t *);

uint8_t static_out[16];

int main(int argc,char **argv)
{
  uint8_t *alloc_out = malloc(16);



  shake256(alloc_out);

  for (long long i = 0;i < 16;++i)
    static_out[i] = alloc_out[i];

  for (long long i = 0;i < 16;++i) {
    unsigned long long x = static_out[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
