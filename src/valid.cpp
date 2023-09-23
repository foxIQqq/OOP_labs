#include <iostream>
#include "valid.h"

using namespace std;

bool invalid_data(long n) {
    if (n <= 0) {
        throw invalid_argument("Argument must be positive");
    }
    if (n > 4294967295) {
        throw out_of_range("Argument must be lower 4294967295");
    }
    return 0;
}