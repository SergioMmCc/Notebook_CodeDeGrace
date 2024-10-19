#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const ll mod = 1e9 + 7;

ll myPow(ll b, ll e){
    ll result = 1;
    while (e > 0) {
        if (e % 2 == 1)
            result = ((b % mod) * (result % mod)) % mod;
        b = ((b % mod) * (b % mod)) % mod;
        e /= 2;
    }
    return result;
}

int main() {
    ll b, e, result;
    cin >> b >> e;
    result = myPow(b, e);
    cout << result << endl;
    return 0;
}