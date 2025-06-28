#include <stdint.h>

int cmp_64xint16(const uint16_t *x,const uint16_t *y)
{
  for (int i = 0;i < 64;++i)
    if (x[i] != y[i])
      return -1;
  return 0;
}
