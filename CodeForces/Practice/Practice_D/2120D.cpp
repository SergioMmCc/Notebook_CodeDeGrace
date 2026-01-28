#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;

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
    ll a, b, k; cin>>a>>b>>k;
    ll n = k * (a - 1) + 1;
    ll comp = n - a;

    ll num = 1;
    for(ll i = comp + 1; i <= n; i++){
        num *= (i % mod);
        num %= mod;
    }

    ll den = 1;
    for(ll i = 2; i <= a; i++){
        den *= (i % mod);
        den %= mod;
    }

    den = mod_inverse(den);

    ll m = (num * den) % mod;
    m *= k;
    m %= mod;
    m *= (b - 1);
    m %= mod;
    m++;
    m %= mod;
    
    n %=mod;

    cout<<n<<' '<<m<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}