#include <stdio.h>
#include <stdint.h>
#include <array>

using namespace std;

uint64_t exponentiate_uint(uint64_t operand, uint64_t exponent)
{
            // Fast cases
            if (exponent == 0)
            {
                return 1;
            }
            if (exponent == 1)
            {
                return operand;
            }

            // Perform binary exponentiation.
            uint64_t power = operand;
            uint64_t product = 0;
            uint64_t intermediate = 1;

            // Initially: power = operand and intermediate = 1, product irrelevant.
            int i=0;
            while (i <10)
            {
                if (exponent & 1)
                {
                    product = power * intermediate;
                    swap(product, intermediate);
                }
                exponent >>= 1;
                if (exponent == 0)
                {
                    break;
                }
                product = power * power;
                swap(product, power);
                i++;
            }

            return intermediate;
}

