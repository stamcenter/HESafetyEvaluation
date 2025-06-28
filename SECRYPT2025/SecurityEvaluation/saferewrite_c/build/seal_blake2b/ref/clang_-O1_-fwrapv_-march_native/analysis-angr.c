#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern uint32_t blake2(uint8_t *,uint8_t,uint8_t *);

uint8_t static_in[1];
uint8_t static_key[1];
uint8_t static_out[1];
uint32_t static_z[1];

int main(int argc,char **argv)
{
  uint8_t *alloc_in = malloc(1);
  uint8_t *alloc_key = malloc(1);
  uint8_t *alloc_out = malloc(1);
  uint32_t *alloc_z = malloc(4);

  for (long long i = 0;i < 1;++i)
    alloc_in[i] = static_in[i];
  for (long long i = 0;i < 1;++i)
    alloc_key[i] = static_key[i];

  alloc_z[0] = blake2(alloc_in,*alloc_key,alloc_out);

  for (long long i = 0;i < 1;++i)
    static_out[i] = alloc_out[i];
  for (long long i = 0;i < 1;++i)
    static_z[i] = alloc_z[i];

  return 0;
}
