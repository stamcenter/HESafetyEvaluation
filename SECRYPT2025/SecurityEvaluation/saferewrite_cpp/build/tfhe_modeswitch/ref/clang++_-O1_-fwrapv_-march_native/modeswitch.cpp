#include <cstdlib>
#include <random>
#include <cassert>
#include <limits.h>

using namespace std;

int32_t modSwitchToTorus32(uint32_t mu, uint32_t msize){
    uint64_t interv = ((uint64_t(1)<<63)/msize)*2; // width of each intervall
    uint64_t phase64 = mu*interv;
    //floor to the nearest multiples of interv
    return phase64;
}
