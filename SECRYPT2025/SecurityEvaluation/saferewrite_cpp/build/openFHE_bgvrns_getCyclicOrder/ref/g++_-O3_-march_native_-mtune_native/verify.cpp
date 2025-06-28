#include <stdio.h>
#include <vector>
#include <array>

typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
uint64_t getCyclicOrder( uint32_t ringDimension, uint32_t plainModulus,
                                                    uint32_t scalTech){
    // Moduli need to be primes that are 1 (mod 2n)
    uint32_t cyclOrder          = 2 * ringDimension;
    uint64_t lcmCyclOrderPtm = 0;

    if (1) {
        // In FIXEDAUTO, moduli also need to be 1 (mod t)
        uint32_t plaintextModulus = plainModulus;
        uint32_t pow2ptm          = 1;  // The largest power of 2 dividing ptm (check whether it
                                     // is larger than cyclOrder or not)
       /*while (plaintextModulus % 2 == 0) {
            plaintextModulus >>= 1;
            pow2ptm <<= 1;
        }*/

        lcmCyclOrderPtm = (uint64_t)pow2ptm * plaintextModulus;
    }
    else {
        lcmCyclOrderPtm = cyclOrder;
    }
    return lcmCyclOrderPtm;
}
