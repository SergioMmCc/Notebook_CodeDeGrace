#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, ll> pil;

const ll mod = 1e9 + 7;
const int maxn = 100005;
vector<int> leader(maxn);
vector<ll> dep(maxn);

void initDSU(int n){
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        dep[i] = 0;
    }
}

pil find(int u){
    if(leader[u] != u){
        pil upd = find(leader[u]);
        leader[u] = upd.fi;
        dep[u] += upd.se;
        dep[u] %= mod;
    }
    return {leader[u], dep[u]};
}

void join(int u, int v, ll w){
    leader[v] = u;
    dep[v] = w;
}

void solver(){
    int n; cin>>n;
    initDSU(n);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int k; cin>>k;
        for(int j = 0; j < k; j++){
            int v; ll w; cin>>v>>w;
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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}