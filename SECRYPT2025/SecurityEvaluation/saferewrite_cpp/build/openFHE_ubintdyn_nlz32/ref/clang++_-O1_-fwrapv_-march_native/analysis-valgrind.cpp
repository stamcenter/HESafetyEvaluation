#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint32_t verify(uint32_t);

uint32_t static_x[1];
uint32_t static_z[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_x = (uint32_t *) malloc(4);
  uint32_t *alloc_z = (uint32_t *) malloc(4);

  alloc_z[0] = verify(*alloc_x);

  return 0;
}
