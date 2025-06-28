#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <array>

using namespace std;

int k, log_base;
uint64_t mask;

// SampleC defined in the UCSD paper
int64_t SampleC(uint64_t center) {
    int64_t c;
    c = center;
    int64_t sample = 19;
    for (int i = 0; i < k; ++i) {
        //sample = base_samplers[mask & c]->GenerateInteger();
        if ((mask & c) > 0 && c < 0)
            sample -= 1;
        for (int j = 0; j < log_base; ++j) {
            c /= 2;
        }
        c += sample;
    }
    return c;
}
