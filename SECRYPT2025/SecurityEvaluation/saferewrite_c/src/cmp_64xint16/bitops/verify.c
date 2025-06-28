#include <stdint.h>

int cmp_64xint16(const uint16_t *x,const uint16_t *y)
{
  uint32_t differentbits = 0;
  for (long long i = 0;i < 64;++i)
    differentbits |= x[i] ^ y[i];
  return (1 & ((differentbits - 1) >> 16)) - 1;
}
