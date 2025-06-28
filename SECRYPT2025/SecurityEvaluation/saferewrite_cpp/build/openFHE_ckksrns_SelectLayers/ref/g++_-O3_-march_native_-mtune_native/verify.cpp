#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

uint32_t SelectLayers(uint32_t logSlots, uint32_t budget) {
    uint32_t layers = ceil(static_cast<double>(logSlots) / budget);
    uint32_t rows   = logSlots / layers;
    uint32_t rem    = logSlots % layers;

    uint32_t dim = rows;
    if (rem != 0) {
        dim = rows + 1;
    }

    // the above choice ensures dim <= budget
    if (dim < budget) {
        layers -= 1;
        rows = logSlots / layers;
        rem  = logSlots - rows * layers;
        dim  = rows;

        if (rem != 0) {
            dim = rows + 1;
        }

        // the above choice endures dim >=budget
        while (dim != budget) {
            rows -= 1;
            rem = logSlots - rows * layers;
            dim = rows;
            if (rem != 0) {
                dim = rows + 1;
            }
        }
    }

    return rows;
}
