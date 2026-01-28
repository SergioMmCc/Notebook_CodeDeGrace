#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
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

ll mod_inverse(ll a) {
    ll i = mod, v = 0, d = 1;
    while(a > 0) {
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
    return v; // (a * v) mod n = 1
}

void solver(){
    ll n, k, a, b;cin>>n>>k>>a>>b;
    ll s = b - a;
    ll p = (myPow(s, k) * myPow(b, n)) % mod;
    ll q = (myPow(b, k) * ((mod + myPow(b, n) - myPow(s, n)) % mod)) % mod;
    cout<<(p * mod_inverse(q)) % mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}