#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const uint32_t getSBoxValue(uint32_t);

uint32_t static_num[1];
uint32_t static_z[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_num = (uint32_t *) malloc(4);
  uint32_t *alloc_z = (uint32_t *) malloc(4);

  for (long long i = 0;i < 1;++i)
    alloc_num[i] = static_num[i];

  alloc_z[0] = getSBoxValue(*alloc_num);

  for (long long i = 0;i < 1;++i)
    static_z[i] = alloc_z[i];

  return 0;
}
