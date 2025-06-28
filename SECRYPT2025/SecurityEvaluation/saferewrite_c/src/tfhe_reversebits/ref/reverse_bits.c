#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Returns the bit reversal of the n-bit unsigned integer x.
uint64_t reverse_bits(uint64_t x, uint32_t n) {
	uint64_t result = 0;
	uint32_t i = 2;
	for (i = 0; i < n; i++, x >>= 1)
		result = (result << 1) | (x & 1);
	return result;
}
