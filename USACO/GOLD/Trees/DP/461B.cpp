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
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 1e5;
const ll mod = 1e9 + 7;
vector<vector<int>> tree(maxn);
vector<bool> b(maxn);
vector<vector<ll>> dp(maxn, vector<ll>(2));

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

void DFS(int u, int pa){
    ll prod = 1;
    for(int v : tree[u]){
        DFS(v, u);
        prod = (prod * ((dp[v][1] + dp[v][0]) % mod)) % mod;
    }

    if(b[u]) dp[u][1] = prod;
    else{
        dp[u][0] = prod;
        ll sum = 0;
        for(int v : tree[u]){
            ll den = (dp[v][0] + dp[v][1]) % mod;
            sum = (sum + ((dp[v][1] * ((prod * mod_inverse(den)) % mod)) % mod)) % mod;
        }
        dp[u][1] = sum;
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u; cin>>u;
        tree[u].pb(i);
    }

    for(int i = 0; i < n; i++){
        int num; cin>>num;
        b[i] = num;
    }

    DFS(0, -1);
    cout<<dp[0][1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}