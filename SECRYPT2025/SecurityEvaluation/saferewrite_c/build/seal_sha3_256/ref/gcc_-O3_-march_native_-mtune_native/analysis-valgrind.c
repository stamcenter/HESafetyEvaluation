#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void sha3_256(uint8_t *,uint8_t *);

uint8_t static_in[32];
uint8_t static_h[32];

int main(int argc,char **argv)
{
  uint8_t *alloc_in = malloc(32);
  uint8_t *alloc_h = malloc(32);

  sha3_256(alloc_h,alloc_in);

  return 0;
}
