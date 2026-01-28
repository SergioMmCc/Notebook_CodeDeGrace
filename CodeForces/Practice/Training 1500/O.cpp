#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 3e5 + 5;
const ll mod = 1e9 + 7;
vector<ll> factorial(maxn);

void preCalcFactorial(){
    factorial[0] = 1;
    for(ll i = 1; i < maxn; i++) factorial[i] = (factorial[i-1] * i) % mod;
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
    return v; // (a * v) % mod = 1
}

void solver(){
    int n, k; cin>>n>>k;
    ll total = n;
    for(int i = 0; i < k; i++){
        int x, y; cin>>x>>y;
        if(x == y) total--;
        else total -= 2;
    }

    ll multi = 1;
    ll ans = 0;
    ll pot2 = 1;
    for(ll i = 0; i <= total; i += 2){
        ll inv1 = mod_inverse(factorial[i]);
        ll inv2 = mod_inverse(factorial[total - i]);
        ll pascal = (((factorial[total] * inv1) % mod) * inv2) % mod;

        ans = (ans + ((((pascal * multi) % mod) * pot2) % mod)) % mod;

        multi = (multi * (i + 1)) % mod;
        pot2 = (2 * pot2) % mod;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    preCalcFactorial();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}