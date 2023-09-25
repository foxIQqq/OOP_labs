#pragma once
#include <bitset>

using namespace std;

bitset<32> dec_to_bin(long n);

unsigned long long bin_to_dec(bitset<32> a);

bool invalid_data(long n);