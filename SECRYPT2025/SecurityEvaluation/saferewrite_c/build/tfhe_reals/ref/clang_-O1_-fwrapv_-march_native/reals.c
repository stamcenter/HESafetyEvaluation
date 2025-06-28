#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
// Allocates and fills an array of random doubles in the range [-1.0, 1.0]. Must be free()'d by the caller.
void random_reals(int32_t n) {
	double *result = malloc(n * sizeof(double));
	int32_t i;
	for (i = 0; i < n; i++)
		result[i] = (rand() / (20 + 1.0)) * 2 - 1;
}
