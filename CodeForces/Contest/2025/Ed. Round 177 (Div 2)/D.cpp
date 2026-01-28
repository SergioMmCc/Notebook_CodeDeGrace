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
const int maxn = 5e5 + 1;
vector<ll> fact(maxn);
void calcFact(){
    fact[0] = 1;
    for(int i = 1; i < maxn; i++){
        fact[i] = i * fact[i-1];
        fact[i] %= mod;
    }
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
    return v;
}

void solver(){
    vector<int> c; c.pb(0);
    int total = 0;
    for(int i = 0; i < 26; i++){
        int save; cin>>save;
        if(!save) continue;
        c.pb(save);
        total += save;
    }

    int n = c.sz - 1, x = (total + 1) / 2;
    vector<vector<ll>> dp(n+1, vector<ll>(x+1)); dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        int valor = c[i];
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            int resta = j - valor;
            if(resta >= 0){
                dp[i][j] += dp[i-1][resta];
                dp[i][j] %= mod;
            }
        }
    }
    
    ll nume = (fact[(total + 1) / 2] * fact[total / 2]) % mod;
    ll den = 1;
    for(int i = 1; i < c.sz; i++){
        den *= fact[c[i]];
        den %= mod;
    }

    den = mod_inverse(den);
    ll ans = (((den * nume) % mod) * dp[n][x]) % mod;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcFact();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}