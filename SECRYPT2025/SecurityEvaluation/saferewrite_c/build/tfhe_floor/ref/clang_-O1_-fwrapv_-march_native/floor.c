#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Returns the largest i such that 2^i <= n.
int32_t floor_log2(uint64_t n) {
	int32_t result = 0;
	for (; n > 1; n /= 2)
		result++;
	return result;
}

