#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

// (a * a⁻¹) % mod = 1
// Para poder hallar a⁻¹ se requiere que a, mod sean coprimos
// Complejidad: O(log(n))
ll mod_inverse(ll a, ll mod){
    ll i = mod, v = 0, d = 1;
    while(a > 0){
        ll t = i/a, x = a;
        a = i%x;
        i = x;
        x = d;
        d = v - t*x;
        v = x;
    }
    v %= mod;
    if(v < 0)
        v += mod;
    return v; // (a * v) % mod = 1
}

int main() {
    ll a, n;
    cin >> a >> n;
    cout << mod_inverse(a, n) << endl;
    return 0;
}