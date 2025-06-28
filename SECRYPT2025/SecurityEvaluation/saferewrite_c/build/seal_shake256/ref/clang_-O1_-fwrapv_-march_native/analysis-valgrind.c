#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void shake256(uint8_t *);

uint8_t static_out[16];

int main(int argc,char **argv)
{
  uint8_t *alloc_out = malloc(16);

  shake256(alloc_out);

  return 0;
}
