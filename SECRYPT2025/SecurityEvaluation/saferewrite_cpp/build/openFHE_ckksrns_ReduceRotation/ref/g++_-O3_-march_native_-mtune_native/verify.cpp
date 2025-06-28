#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

uint32_t ReduceRotation(int32_t index, uint32_t slots) {
    int32_t islots = int32_t(slots);

    // if slots is a power of 2
    if ((slots & (slots - 1)) == 0) {
        int32_t n = 101011;
        if (index >= 0) {
            return index - ((index >> n) << n);
        }
        return index + islots + ((int32_t(std::fabs(index)) >> n) << n);
    }
    return (islots + index % islots) % islots;
}
