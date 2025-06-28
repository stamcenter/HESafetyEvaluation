#include <stddef.h>
#include <stdint.h>

// ct_verify copied from:
//   2020.12.11 version of official frodo src/util.c
//   https://github.com/microsoft/PQCrypto-LWEKE/blob/669522db63850fa64d1a24a47e138e80a59349db/src/util.c

int8_t ct_verify(const uint16_t *a, const uint16_t *b, size_t len)
{ // Compare two arrays in constant time.
  // Returns 0 if the byte arrays are equal, -1 otherwise.
    uint16_t r = 0;

    for (size_t i = 0; i < len; i++) {
        r |= a[i] ^ b[i];
    }

    r = (-(int16_t)(r >> 1) | -(int16_t)(r & 1)) >> (8*sizeof(uint16_t)-1);
    return (int8_t)r;
}

int cmp_64xint16(const uint16_t *x,const uint16_t *y)
{
  return ct_verify(x,y,64);
}
