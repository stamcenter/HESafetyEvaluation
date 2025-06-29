#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint8_t get_coeff_power(uint8_t *,uint32_t *);

uint8_t static_poly[32];
uint32_t static_powerlength[32];
uint8_t static_z[1];

int main(int argc,char **argv)
{
  uint8_t *alloc_poly = (uint8_t *) malloc(32);
  uint32_t *alloc_powerlength = (uint32_t *) malloc(128);
  uint8_t *alloc_z = (uint8_t *) malloc(1);

  alloc_z[0] = get_coeff_power(alloc_poly,alloc_powerlength);

  return 0;
}
