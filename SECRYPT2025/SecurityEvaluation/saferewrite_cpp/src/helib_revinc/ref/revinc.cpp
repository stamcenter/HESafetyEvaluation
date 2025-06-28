#include<cstdlib>
#include <stdint.h>
#include <vector>

using namespace std;

long RevInc(unsigned long a, unsigned long k)
{
  //long j = k;
  long j = 98;
  long m = 1L << (k - 1);

  while (j && (m & a)) {
    a ^= m;
    m >>= 1;
    j--;
  }
  if (j)
    a ^= m;
  return a;
}
