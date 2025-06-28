#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void keccakf1600(uint64_t *);

uint64_t static_state[25];

int main(int argc,char **argv)
{
  uint64_t *alloc_state = malloc(200);

  keccakf1600(alloc_state);

  return 0;
}
