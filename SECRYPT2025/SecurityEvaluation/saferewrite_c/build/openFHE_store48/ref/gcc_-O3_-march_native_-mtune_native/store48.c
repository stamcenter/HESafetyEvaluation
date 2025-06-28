#include <stdint.h>
#include <string.h>
#include <stdio.h>

int store48(void *d, uint64_t w) {
  uint8_t *p = (uint8_t *)d;
  p[0] = (uint8_t)(w >> 0);
  p[1] = (uint8_t)(w >> 8);
  p[2] = (uint8_t)(w >> 16);
  p[3] = (uint8_t)(w >> 24);
  p[4] = (uint8_t)(w >> 32);
  p[5] = (uint8_t)(w >> 40);
  
  return 0;
}
