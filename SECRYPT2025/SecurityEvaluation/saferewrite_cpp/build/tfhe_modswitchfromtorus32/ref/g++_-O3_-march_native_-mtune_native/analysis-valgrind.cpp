#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern const void modSwitchFromTorus32(uint32_t,uint32_t);

uint32_t static_phase[1];
uint32_t static_msize[1];

int main(int argc,char **argv)
{
  uint32_t *alloc_phase = (uint32_t *) malloc(4);
  uint32_t *alloc_msize = (uint32_t *) malloc(4);

  modSwitchFromTorus32(*alloc_phase,*alloc_msize);

  return 0;
}
