#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint64_t load64(uint64_t *);

uint64_t static_x[64];
uint64_t static_r[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_x = malloc(512);
  uint64_t *alloc_r = malloc(8);

  alloc_r[0] = load64(alloc_x);

  return 0;
}
