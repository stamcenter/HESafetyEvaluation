#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint64_t load64(uint64_t *);

uint64_t static_x[1];
uint64_t static_r[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_x = malloc(8);
  uint64_t *alloc_r = malloc(8);

  for (long long i = 0;i < 1;++i)
    alloc_x[i] = static_x[i];

  alloc_r[0] = load64(alloc_x);

  for (long long i = 0;i < 1;++i)
    static_r[i] = alloc_r[i];

  return 0;
}
