#include <complex>
#include <stdint.h>
#include <cmath>

using namespace std;
//evaluate f at e^{2 pi i/m}, returning a complex number

int evalpoly(uint64_t i, uint64_t m)
{
	double f =2;
  	complex<double> t(0.0, 2*M_PI*i/((double) m));
  	complex<double> x = exp(t);

  	complex<double> res = 0.0;
  	for (long j = m-1; j >= 0; j--)
    	res = res*x + f;
  	return 0;
}
