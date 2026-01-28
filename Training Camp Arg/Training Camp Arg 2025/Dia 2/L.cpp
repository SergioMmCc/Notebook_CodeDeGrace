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

const ll mod = 998244353;
ll mod_inverse(ll a) {
    ll i = (ll)mod, v = 0, d = 1;
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

vector<ll> fact(300001);
void calcFact(){
    fact[0] = 1;
    for(ll i = 1; i <= 300000; i++) fact[i] = (fact[i-1] * i) % mod;
}

void solver(){
    ll n; cin>>n;
    vector<ll> a(2*n);
    for(ll i = 0; i < 2*n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    ll sum = 0;
    for(int i = 0; i < n; i++){
        a[i] %= mod; a[i+n] %= mod;
        sum = (sum + a[i+n]) % mod;
        sum = (sum - a[i] + mod) % mod;
    }

    ll num = fact[2*n];
    ll den = (fact[n] * fact[n]) % mod;
    den = mod_inverse(den);

    ll ans = (((sum * num) % mod) * den) % mod;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcFact();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}