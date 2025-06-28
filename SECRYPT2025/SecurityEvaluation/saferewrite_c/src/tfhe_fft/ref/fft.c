#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// M_PI isn't defined with C99 for whatever reason
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

// Private data structure
struct FftTables {
	uint64_t n;
	uint64_t *bit_reversed;
	double *trig_tables;
};

// Deallocates the given structure of FFT tables.
void fft_destroy(void *tables) {
	if (tables == NULL)
		return;
	struct FftTables *tbl = (struct FftTables *)tables;
	free(tbl->bit_reversed);
	free(tbl->trig_tables);
	memset(tbl, 0, sizeof(struct FftTables));  // Prevent accidental memory reuse
	free(tbl);
}

