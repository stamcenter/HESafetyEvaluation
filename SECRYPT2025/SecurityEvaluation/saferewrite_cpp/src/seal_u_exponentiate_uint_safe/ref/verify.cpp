#include "seal/common.h"
#include <stdio.h>
#include <array>
#include <algorithm>

using namespace std;

uint64_t exponentiate_uint_safe(uint64_t operand, uint64_t exponent)
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
            //uint64_t ano =0;

            // Initially: power = operand and intermediate = 1, product irrelevant.
            //while (ano < 4)
            int i =0;
            while(i <10)
            {
                //ano ++;
                if (exponent & 1)
                {
                    //product = seal::util::mul_safe(power, intermediate);
                    swap(product, intermediate);
                }
                exponent >>= 1;
                if (exponent == 0)
                {
                    break;
                }
                //product = seal::util::mul_safe(power, power);
                swap(product, power);
                i++;
            }

            return intermediate;
}
