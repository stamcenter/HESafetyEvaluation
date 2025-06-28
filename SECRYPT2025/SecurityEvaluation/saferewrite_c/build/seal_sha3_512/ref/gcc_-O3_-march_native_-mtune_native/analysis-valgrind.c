#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void sha3_512(uint8_t *,uint8_t *);

uint8_t static_in[64];
uint8_t static_h[8];

int main(int argc,char **argv)
{
  uint8_t *alloc_in = malloc(64);
  uint8_t *alloc_h = malloc(8);

  sha3_512(alloc_in,alloc_h);

  return 0;
}
