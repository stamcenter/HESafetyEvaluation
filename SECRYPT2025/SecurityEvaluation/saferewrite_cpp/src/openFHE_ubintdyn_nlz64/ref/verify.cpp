
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <array>
using namespace std;

int verify(uint64_t x) {  // todo: needs to be flexible and select
                                // the appropriate nlz based on limb size..
    int n;

    if (x == 0) {
        return (64);
    }
    n = 0;
    if (x <= 0x000000FF) {
        n = n + 32;
        x = x << 32;
    }
    if (x <= 0x0000FFFF) {
        n = n + 16;
        x = x << 16;
    }
    if (x <= 0x00FFFFFF) {
        n = n + 8;
        x = x << 8;
    }
    if (x <= 0x0FFFFFFF) {
        n = n + 4;
        x = x << 4;
    }
    if (x <= 0x3FFFFFFF) {
        n = n + 2;
        x = x << 2;
    }
    if (x <= 0x7FFFFFFF) {
        n = n + 1;
    }
    return n;
}

