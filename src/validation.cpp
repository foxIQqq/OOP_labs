#include <iostream>
#include <cmath>
#include "dec_bin_convertion.h"

bool invalid_data(long n) {
    if (n <= 0 || n > lround(pow(2, 32))) {
        throw out_of_range("Argument must be positive and lower 2^32 (4294967296)");
    }
    return 0;
}