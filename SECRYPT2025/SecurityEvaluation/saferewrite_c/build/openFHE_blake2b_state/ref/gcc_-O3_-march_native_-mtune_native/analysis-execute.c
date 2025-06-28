#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint32_t black2b_state();

uint32_t static_d[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_d = malloc(4);



  alloc_d[0] = black2b_state();

  for (long long i = 0;i < 1;++i)
    static_d[i] = alloc_d[i];

  for (long long i = 0;i < 1;++i) {
    unsigned long long x = static_d[i];
    printf("%llu\n",x);
  }
  fflush(stdout);

  return 0;
}
