#include <cstdlib>
#include <random>
#include <cassert>
#include <limits.h>

using namespace std;

typedef int32_t Torus32;

int32_t modSwitchFromTorus32(uint32_t phase, uint32_t msize){
    uint64_t interv = ((uint64_t(1)<<63)/msize)*2; // width of each intervall
    uint64_t half_interval = interv/2; // begin of the first intervall
    uint64_t phase64 = (uint64_t(phase)<<32) + half_interval;
    //floor to the nearest multiples of interv
    return (phase64/interv);
}
