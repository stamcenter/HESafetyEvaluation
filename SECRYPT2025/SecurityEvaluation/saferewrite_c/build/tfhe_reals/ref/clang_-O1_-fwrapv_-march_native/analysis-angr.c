#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void random_reals(uint32_t *);

uint32_t static_n[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_n = malloc(4);

  for (long long i = 0;i < 1;++i)
    alloc_n[i] = static_n[i];

  random_reals(alloc_n);


  return 0;
}
