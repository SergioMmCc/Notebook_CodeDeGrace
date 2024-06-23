#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;


int main() {
    unsigned long long b, e, result = 1;
    cin >> b >> e;
    while (e > 0) {
        if (e % 2 == 1)
            result = ((b % mod) * (result % mod)) % mod;
        b = ((b % mod) * (b % mod)) % mod;
        e /= 2;
    }
    cout << result << "\n";
    return 0;
}