#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void store64(uint8_t *,uint64_t *);

uint8_t static_x[1];
uint64_t static_u[1];

int main(int argc,char **argv)
{
  uint8_t *alloc_x = malloc(1);
  uint64_t *alloc_u = malloc(8);

  store64(alloc_x,alloc_u);

  return 0;
}
