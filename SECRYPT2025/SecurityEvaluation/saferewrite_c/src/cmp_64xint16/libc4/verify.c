#include <stdint.h>
#include <string.h>

int cmp_64xint16(const uint16_t *x,const uint16_t *y)
{
  int r = memcmp(x,y,127);
  if (r != 0) return -1;
  return 0;
}
