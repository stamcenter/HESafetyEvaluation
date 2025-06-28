#include <stdint.h>
#include <string.h>
#include <stdio.h>

int store32(void *dst, uint32_t w) {
    #if defined(NATIVE_LITTLE_ENDIAN)
      memcpy(dst, &w, sizeof w);
    #else
      uint8_t *p = (uint8_t *)dst;
      p[0] = (uint8_t)(w >> 0);
      p[1] = (uint8_t)(w >> 8);
      p[2] = (uint8_t)(w >> 16);
      p[3] = (uint8_t)(w >> 24);
    #endif
    return 0;
}

