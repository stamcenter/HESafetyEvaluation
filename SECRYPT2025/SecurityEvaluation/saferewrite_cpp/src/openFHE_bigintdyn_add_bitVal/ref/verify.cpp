#include <stdio.h>
#include <vector>
#include <array>

typedef unsigned char uschar;
const unsigned int m_numDigitInPrintval = 1500;

void addbitVal(unsigned char* a, unsigned char b) {
    uschar ofl = 0;
    *(a + m_numDigitInPrintval - 1) += b;
    for (int i = m_numDigitInPrintval - 1; i > -1; i--) {
        *(a + i) += ofl;
        if (*(a + i) > 9) {
            *(a + i) = 0;
            ofl      = 1;
        }
    }
}
