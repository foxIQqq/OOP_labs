#include <iostream>
#include <vector>
#include "back.h"

using namespace std;

long back_to_dec(vector<int> a) {
    int x = 1, i = 31; 
    long dec = 0;
    while (i >= 0) {
        if (a[i] == 1) {
            dec += x;
        }
        x *= 2;
        i--;
    }
    return dec;
}