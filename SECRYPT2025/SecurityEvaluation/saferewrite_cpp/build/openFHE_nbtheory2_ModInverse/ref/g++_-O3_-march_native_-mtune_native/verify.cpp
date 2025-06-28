#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <array>
using namespace std;

uint32_t ModInverse(uint32_t a, uint32_t b) {
    // usint b0 = b;
    uint32_t t, q;
    uint32_t x0 = 0, x1 = 1;
    if (b == 1)
        return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    // if (x1 < 0) x1 += b0;
    // TODO: x1 is never < 0

    return x1;
}
