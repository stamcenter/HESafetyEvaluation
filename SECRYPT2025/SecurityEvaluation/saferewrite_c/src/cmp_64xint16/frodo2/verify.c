#include <stddef.h>
#include <stdint.h>

// ct_verify copied from
//   2020.06.18 version of official frodo src/util.c
//   https://github.com/microsoft/PQCrypto-LWEKE/blob/155c24c3df47be6d5d9845fea37be110945e963c/src/util.c

int8_t ct_verify(const uint16_t *a, const uint16_t *b, size_t len)
{ // Compare two arrays in constant time.
  // Returns 0 if the byte arrays are equal, -1 otherwise.
    uint16_t r = 0;

    for (size_t i = 0; i < len; i++) {
        r |= a[i] ^ b[i];
    }

    r = (-(int16_t)r) >> (8*sizeof(uint16_t)-1);
    return (int8_t)r;
}

int cmp_64xint16(const uint16_t *x,const uint16_t *y)
{
  return ct_verify(x,y,64);
}
