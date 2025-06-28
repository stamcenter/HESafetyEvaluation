#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const void longtobitvector(uint64_t,uint64_t);

uint64_t static_num[1];
uint64_t static_bitsize[1];

int main(int argc,char **argv)
{
  uint64_t *alloc_num = (uint64_t *) malloc(8);
  uint64_t *alloc_bitsize = (uint64_t *) malloc(8);

  for (long long i = 0;i < 1;++i)
    alloc_num[i] = static_num[i];
  for (long long i = 0;i < 1;++i)
    alloc_bitsize[i] = static_bitsize[i];

  longtobitvector(*alloc_num,*alloc_bitsize);


  return 0;
}
