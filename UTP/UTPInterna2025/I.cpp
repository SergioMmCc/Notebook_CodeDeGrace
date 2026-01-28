#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;
ll md;

ll mod_inverse(ll a){
    ll i = mod, v = 0, d = 1;
    while(a > 0){
        ll t = i / a, x = a;
        a = i%x;
        i = x;
        x = d;
        d = v - t*x;
        v = x;
    }

    v %= mod;
    if(v < 0) v += mod;
    return v;
}

void solver(){
    ll n; cin>>n;
    n -= 2; n %= mod;

    ll ft = (2 * n) % mod;
    ft = (ft * n) % mod;
    ft = (ft * n) % mod;

    ll st = (6 * n) % mod;
    st = (st * n) % mod;

    ll tt = (4 * n) % mod;

    ll numerador = (ft + st + tt) % mod;

    cout<<(numerador * md) % mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    md = mod_inverse(12);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}