#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// M_PI isn't defined with C99 for whatever reason
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

// Returns sin(2 * pi * i / n), for n that is a multiple of 4.
int accurate_sine(uint64_t i, uint64_t n) {
	if (n % 4 != 0)
		return 0;
	else {
		int32_t neg = 0;  // Boolean
		// Reduce to full cycle
		i %= n;
		// Reduce to half cycle
		if (i >= n / 2) {
			neg = 1;
			i -= n / 2;
		}
		// Reduce to quarter cycle
		if (i >= n / 4)
			i = n / 2 - i;
		// Reduce to eighth cycle
		double val;
		if (i * 8 < n)
			val = (2 * M_PI * i / n);
		else
			val = (2 * M_PI * (n / 4 - i) / n);
		// Apply sign
		return neg ? -val : val;
	}
}
