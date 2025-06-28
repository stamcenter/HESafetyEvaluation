#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint32_t allrotate();

uint32_t static_r[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_r = (uint32_t *) malloc(4);

  alloc_r[0] = allrotate();

  return 0;
}
