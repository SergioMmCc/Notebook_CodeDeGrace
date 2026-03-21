#include <bits/stdc++.h>
using namespace std;
 
const int mod = 998244353;
 
int main() {
    unsigned long long a, n, e, b = 2, result = 1;
    cin >> a >> n;
    e = a + n;
    while (e > 0) {
        if (e % 2 == 1)
            result = ((b % mod) * (result % mod)) % mod;
        b = ((b % mod) * (b % mod)) % mod;
        e /= 2;
    }
    cout << result << "\n";
    return 0;
}