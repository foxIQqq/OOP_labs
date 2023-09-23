#include <iostream>
#include <vector>
#include "valid.h"
#include "func.h"
#include "back.h"

using namespace std;

bool invalid_data(long n) {
    std::vector<int> ans(32);
    long back_dec = 0;
    if (n <= 0) {
        throw invalid_argument("Argument must be positive");
        return 0;
    }
    if (n > 4294967295) {
        throw out_of_range("Argument must be lower 4294967295");
        return 0;
    }
}