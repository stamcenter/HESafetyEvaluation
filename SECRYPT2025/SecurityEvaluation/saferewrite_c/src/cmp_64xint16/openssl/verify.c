#include <stdint.h>
#include <stddef.h>

extern int CRYPTO_memcmp(const void *, const void *, size_t);

int cmp_64xint16(const uint16_t *x,const uint16_t *y)
{
  return -CRYPTO_memcmp(x,y,128);
}
