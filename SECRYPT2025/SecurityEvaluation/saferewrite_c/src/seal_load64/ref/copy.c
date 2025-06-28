#include <stddef.h>
#include <stdint.h>

uint64_t load64(const uint8_t x[8]) {
  unsigned int i;
  uint64_t r = 0;
  for(i=0;i<8;i++)
    r |= (uint64_t)x[i] << 8*i;
  return r;
}
