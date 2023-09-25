#include <iostream>
#include <bitset>
#include "dec_bin_convertion.h"

int main() {
    long n;
    cout << "Enter your number:" << '\n';
    cin >> n;
    invalid_data(n);
    bitset<32> ans = dec_to_bin(n);
    cout << ans.to_string() << endl;
}