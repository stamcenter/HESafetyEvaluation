#include <stdio.h>
#include <stdint.h>
#include <vector>
//#include "seal/modulus.h"
using namespace std;

int get_primes(uint64_t factor, uint32_t bitsize, size_t count)
{
    // Start with (2^bit_size - 1) / factor * factor + 1
	uint64_t value = ((uint64_t(0x1) << bitsize) - 1) / factor * factor + 1;
	//uint64_t lower_bound = uint64_t(0x1) << (bitsize - 1);
	/*vector<Modulus> destination;
    // Start with (2^bit_size - 1) / factor * factor + 1
    while (count > 0 && value > lower_bound)
    {
     	Modulus new_mod(value);
        if (new_mod.is_prime())
        {
             destination.emplace_back(move(new_mod));
             count--;
        }
         value -= factor;
    }*/
	return value;
}

int verify(uint64_t factor, uint32_t bitsize){
	return get_primes(factor, bitsize, 64);
} 
