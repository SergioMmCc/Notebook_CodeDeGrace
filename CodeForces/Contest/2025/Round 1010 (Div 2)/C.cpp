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
vector<ll> pot2(100001);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 100001; i++) pot2[i] = (pot2[i-1] * 2) % mod;
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

ll calc(int index){

}

void solver(){
    int n; cin>>n;
    string x; cin>>x;
    bool cond = 0;
    for(int i = 1; i < n; i++){
        if(x[i] == '1') cond = 1;
    }

    if(!cond){
        cout<<n-1<<endl;
        return;
    }

    x[0] = '0';

    ll q = pot2[n];
    ll inv2 = mod_inverse(2);
    vector<ll> p(n);
    p[n-1] = x[n-1] == '1' ? q : 0;
    for(int i = n - 2; i >= 0; i--){
        if(x[i] == '1') p[i] = q;
        p[i] += (p[i + 1] * inv2) % mod;
    }

    ll ans = (((q - p[0] + mod) % mod) * (n- 1)) % mod;
    ans += (p[0] * n) % mod;
    ans = ans % mod;

    cout<<(ans * mod_inverse(q)) % mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPot2();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}