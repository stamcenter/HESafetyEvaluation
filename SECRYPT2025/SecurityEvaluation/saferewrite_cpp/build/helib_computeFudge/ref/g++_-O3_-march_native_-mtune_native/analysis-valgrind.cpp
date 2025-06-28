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

  compute_fudge(*alloc_peprime,*alloc_pe);

  return 0;
}
