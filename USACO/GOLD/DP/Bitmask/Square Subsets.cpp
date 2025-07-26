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
const int limite = 35, maxn = 1e5 + 1;

vector<bool> esPrimo(limite + 1, 1);
vector<int> primos;

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(int i = 2; i < limite; i++){
        if(esPrimo[i]) primos.pb(i);
    }
}

vector<ll> fact(maxn);
void calcFact(){
    fact[0] = 1;
    for(ll i = 1; i < maxn; i++) fact[i] = (fact[i-1] * i) % mod;
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
    int n; cin>>n;
    int count1 = 0;
    vector<int> a;
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        if(num == 1){
            count1++;
            continue;
        }

        int mask = 0;
        for(int i = 0; num > 1 && i < primos.sz; i++){
            int parity = 0;
            while(num % primos[i] == 0){
                parity++;
                num /= primos[i];
            }

            if(parity % 2) mask += (1 << i);
        }

        if(num > 1) freq[num]++;
        else a.pb(mask);
    }

    vector<ll> dp(1 << 11); dp[0] = 1;
    for(int i = 0; i < a.sz; i++){
        vector<ll> next = dp;
        for(int mask = 0; mask < (1 << 11); mask++){
            next[mask ^ a[i]] += dp[mask];
            next[mask ^ a[i]] %= mod;
        }

        swap(dp, next);
    }

    ll ans = dp[0];

    // Contar las formas de usar los 1
    for(int i = 0; i < count1; i++) ans = (ans * 2) % mod;

    for(const auto& par : freq){
        ll total = (ll)par.se;
        ll sum = 0, nume = fact[total];
        for(ll i = 0; i <= total; i += 2){
            ll deno = (fact[total - i] * fact[i]) % mod;
            deno = mod_inverse(deno);
            sum = (sum + ((nume * deno) % mod) + mod) % mod;
        }

        // cout<<"numero -> "<<par.fi<<" total -> "<<total<<" sum -> "<<sum<<endl;

        ans = (ans * sum) % mod;
    }
    
    cout<<(ans - 1 + mod) % mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    sieve();
    calcFact();
    // for(int p : primos) cout<<p<<endl;
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}