#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void accurate_sine(uint64_t *,uint64_t *);

uint64_t static_i[1];
uint64_t static_n[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_i = malloc(8);
  uint64_t *alloc_n = malloc(8);

  accurate_sine(alloc_i,alloc_n);

  return 0;
}
