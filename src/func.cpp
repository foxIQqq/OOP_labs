#include <bits/stdc++.h>
#include "func.h"
using namespace std;

vector<int> dec_to_bin(long n) {
    vector<int> answer(32);
    for (int elem : answer) {
        elem = 0;
    }
    
    int i = 31;
    while (n > 0) {
        answer[i] = n % 2;
        n /= 2;
        i--;
    }

    return answer;
}