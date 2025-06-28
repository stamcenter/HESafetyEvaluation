#include <stdint.h>
#include <string.h>

int cmp_64xint16(const uint16_t *x,const uint16_t *y)
{
  return memcmp(x,y,128);
}
