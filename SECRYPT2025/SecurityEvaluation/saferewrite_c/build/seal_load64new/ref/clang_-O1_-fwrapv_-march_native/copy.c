#include <stddef.h>
#include <stdint.h>

uint64_t load64(const void *x)
{
    #if defined(NATIVE_LITTLE_ENDIAN)
        uint64_t w;
        memcpy(&w, x, sizeof w);
        return w;
    #else
        const uint8_t *p = (const uint8_t *)x;
        // printf("----printing in load64----\n");
        return ((uint64_t)(p[0]) << 0) | ((uint64_t)(p[1]) << 8) | ((uint64_t)(p[2]) << 16) | ((uint64_t)(p[3]) << 24) |
            ((uint64_t)(p[4]) << 32) | ((uint64_t)(p[5]) << 40) | ((uint64_t)(p[6]) << 48) | ((uint64_t)(p[7]) << 56);
    #endif
}

