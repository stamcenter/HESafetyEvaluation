#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint32_t ReduceRotation(uint32_t,uint32_t);

uint32_t static_slots[1];
uint32_t static_index[1];
uint32_t static_d[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_slots = (uint32_t *) malloc(4);
  uint32_t *alloc_index = (uint32_t *) malloc(4);
  uint32_t *alloc_d = (uint32_t *) malloc(4);

  for (long long i = 0;i < 1;++i)
    alloc_slots[i] = static_slots[i];

  alloc_d[0] = ReduceRotation(*alloc_index,*alloc_slots);

  for (long long i = 0;i < 1;++i)
    static_index[i] = alloc_index[i];
  for (long long i = 0;i < 1;++i)
    static_slots[i] = alloc_slots[i];
  for (long long i = 0;i < 1;++i)
    static_d[i] = alloc_d[i];

  return 0;
}
