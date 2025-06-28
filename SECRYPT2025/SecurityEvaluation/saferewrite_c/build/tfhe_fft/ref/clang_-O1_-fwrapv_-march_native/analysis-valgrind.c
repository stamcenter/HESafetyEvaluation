#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern void fft_destroy(uint8_t *);

uint8_t static_tables[112];

int main(int argc,char **argv)
{
  uint8_t *alloc_tables = malloc(112);

  fft_destroy(alloc_tables);

  return 0;
}
