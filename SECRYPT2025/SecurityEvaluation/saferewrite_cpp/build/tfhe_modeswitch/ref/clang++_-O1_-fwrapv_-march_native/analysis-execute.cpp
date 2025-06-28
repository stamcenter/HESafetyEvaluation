#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const void modSwitchToTorus32(uint32_t,uint32_t);

uint32_t static_mu[1];
uint32_t static_msize[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_mu = (uint32_t *) malloc(4);
  uint32_t *alloc_msize = (uint32_t *) malloc(4);

  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_mu[i] = x;
  }
  for (long long i = 0;i < 1;++i) {
    unsigned long long x;
    if (scanf("%llu",&x) != 1) abort();
    static_msize[i] = x;
  }

  for (long long i = 0;i < 1;++i)
    alloc_mu[i] = static_mu[i];
  for (long long i = 0;i < 1;++i)
    alloc_msize[i] = static_msize[i];

  modSwitchToTorus32(*alloc_mu,*alloc_msize);



  return 0;
}
