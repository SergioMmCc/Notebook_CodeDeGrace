#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

ll mod_inverse(ll a, ll n) {
    ll i = n, v = 0, d = 1;
    while(a > 0) {
        ll t = i/a, x = a;
        a = i%x;
        i = x;
        x = d;
        d = v - t*x;
        v = x;
    }
    v %= n;
    if(v < 0)
        v += n;
    return v; // (a * v) mod n = 1
}

int main() {
    ll a, n;
    cin >> a >> n;
    cout << mod_inverse(a, n) << endl;
    return 0;
}