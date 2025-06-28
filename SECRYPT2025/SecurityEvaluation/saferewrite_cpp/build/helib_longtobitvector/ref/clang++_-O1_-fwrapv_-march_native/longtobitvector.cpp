#include <cstdlib>
#include <cstdio>
#include <stdint.h>
#include <vector>

using namespace std;

// Return a number as a vector of bits with little endian-ness
uint32_t longtobitvector(unsigned long num, unsigned long bitsize)
{
  std::vector<long> result;
  for (unsigned long i = 0; i < bitsize; num >>= 1, ++i)
     i=i;
    //result.push_back(num & 1);
  return 0;
}
