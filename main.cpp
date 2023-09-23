#include <iostream>
#include <vector>
#include "func.h"
#include "valid.h"
#include "back.h"

using namespace std;

int main() {
    long n;
    cout << "Enter your number:" << '\n';
    cin >> n;
    invalid_data(n);
    vector<int> ans = dec_to_bin(n);
    for (int elem : ans) {
        cout << elem;
    }
    cout << endl;
}