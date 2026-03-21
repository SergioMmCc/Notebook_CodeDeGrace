#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, ll> pil;

const ll mod = 1e9 + 7;
const ll maxn = 100005;
vector<ll> leader(maxn);
vector<ll> dep(maxn);

void initDSU(ll n){
    for(ll i = 1; i <= n; i++){
        leader[i] = i;
        dep[i] = 0;
    }
}

pil find(ll u){
    if(leader[u] != u){
        pil upd = find(leader[u]);
        leader[u] = upd.fi;
        dep[u] += upd.se;
        dep[u] %= mod;
    }
    return {leader[u], dep[u]};
}

void join(ll u, ll v, ll w){
    leader[v] = u;
    dep[v] = w;
}

void solver(){
    ll n; cin>>n;
    initDSU(n);
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ll k; cin>>k;
        for(ll j = 0; j < k; j++){
            ll v; ll w; cin>>v>>w;
            w += mod; w %= mod;
            pil cha = find(v);
            ans += (w + cha.se) % mod;
            ans %= mod;
            join(i, cha.fi, (w + cha.se) % mod);
            // cout<<"i -> "<<i<<" cha.fi -> "<<cha.fi<<" cha.se -> "<<cha.se<<" w -> "<<w<<endl;
        }
    }

    cout<<ans<<endl;
}

ll main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}