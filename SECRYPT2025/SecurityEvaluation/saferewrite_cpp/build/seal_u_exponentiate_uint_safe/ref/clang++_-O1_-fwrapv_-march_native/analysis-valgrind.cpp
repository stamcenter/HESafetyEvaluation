#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint64_t exponentiate_uint_safe(uint64_t,uint64_t);

uint64_t static_operand[1];
uint64_t static_exponent[1];
uint64_t static_z[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_operand = (uint64_t *) malloc(8);
  uint64_t *alloc_exponent = (uint64_t *) malloc(8);
  uint64_t *alloc_z = (uint64_t *) malloc(8);

  alloc_z[0] = exponentiate_uint_safe(*alloc_operand,*alloc_exponent);

  return 0;
}
