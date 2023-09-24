#include <iostream>
#include <bitset>
#include "dec_bin_convertion.h"
using namespace std;

bitset<32> dec_to_bin(long n) {
    bitset<32> answer(n);
    
    return answer;
}

unsigned long long bin_to_dec(bitset<32> a) {
    unsigned long long dec = 0;
    dec = a.to_ullong();

    return dec;
}