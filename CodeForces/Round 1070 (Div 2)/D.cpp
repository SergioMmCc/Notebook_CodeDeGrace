#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<ll, pair<int, int>> plii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 998244353;

struct Edge{
    int from, to; ll val;
};

void solver(){
    int n, m; cin>>n>>m;
    vector<ll> a(n+1);
    for(int i = 0; i < n; i++) cin>>a[i+1];

    vector<plii> edj;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        ll w = max(a[u], a[v]);
        edj.pb({w, {u, v}});
    }

    sort(all(edj));

    ll ans = 0;
    vector<map<ll, ll>> add(n+1);
    for(plii e : edj){
        int from = e.se.fi, to = e.se.se; ll w = e.fi;
        if(a[to] <= a[from]){
            add[to][a[from]]++;
            add[to][a[from]] %= mod;
            // cout<<"to -> "<<to<<" from -> "<<from<<" a[from] -> "<<a[from]<<" aux -> "<<add[to][a[from]]<<endl<<endl;
            ans = (ans + 1LL) % mod;
        }

        else{
            ll s = a[to] - a[from];
            ll aux = 1LL;
            if(add[from].find(s) != add[from].end()) aux = (add[from][s] + 1LL) % mod;
            // cout<<"to -> "<<to<<" from -> "<<from<<" s -> "<<s<<" add[from][s] -> "<<add[from][s]<<" aux -> "<<aux<<endl<<endl;
            add[to][a[from]] += aux;
            add[to][a[from]] %= mod;
            ans = (ans + aux) % mod;
        }
        // cout<<"w -> "<<w<<" ans -> "<<ans<<endl;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}