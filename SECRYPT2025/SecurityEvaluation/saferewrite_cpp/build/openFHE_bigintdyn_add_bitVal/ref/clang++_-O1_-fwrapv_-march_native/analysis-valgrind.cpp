#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const void addbitVal(uint8_t *,uint8_t);

uint8_t static_a[1];
uint8_t static_b[1];

int main(int argc,char **argv)
{
  uint8_t *alloc_a = (uint8_t *) malloc(1);
  uint8_t *alloc_b = (uint8_t *) malloc(1);

  addbitVal(alloc_a,*alloc_b);

  return 0;
}
