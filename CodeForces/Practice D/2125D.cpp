#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, ll> pll;
typedef pair<pll, pll> pllll;

const ll mod = 998244353;

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
    int n, m; cin>>n>>m;
    vector<pllll> ran(n);
    vector<ll> comp(m+2, 1);
    for(int i = 0; i < n; i++){
        ll l, r, p, q; cin>>l>>r>>p>>q;
        ll aux = q - p;
        comp[l] *= (mod_inverse(q) * aux) % mod;
        comp[l] %= mod;

        ran[i] = {{l, r}, {p, q}};
    }

    for(int i = 1; i <= m + 1; i++) comp[i] = (comp[i] * comp[i-1]) % mod;

    sort(ran.begin(), ran.end());
    vector<ll> dp(m+1); dp[0] = 1;
    for(int i = 0; i < n; i++){
        ll l = ran[i].fi.fi, r = ran[i].fi.se, p = ran[i].se.fi, q = ran[i].se.se;
        ll aux = q - p;
        ll add = (comp[r] * mod_inverse(comp[l-1])) % mod;
        add = (add * ((mod_inverse(aux) * q) % mod)) % mod;
        add = (add * ((mod_inverse(q) * p) % mod)) % mod;
        add = (add * dp[l-1]) % mod;

        dp[r] = (dp[r] + add) % mod;
    }

    cout<<dp[m]<<endl;
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