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
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod;

void DFS1(int u, int pa, vector<vi>& tree, vector<vl>& ps, vector<vl>& ss, vl& f){
    for(int i = 1; i < sz(tree[u]); i++){
        ps[u][i] = ps[u][i-1];
        int v = tree[u][i];
        if(v == pa) continue;

        DFS1(v, u, tree, ps, ss, f);

        f[u] = (f[u] * ((f[v] + 1) % mod)) % mod;
        ps[u][i] = (ps[u][i] * ((f[v] + 1) % mod)) % mod;
    }

    for(int i = sz(tree[u]) - 1; i > 0; i--){
        ss[u][i] = ss[u][i+1];
        int v = tree[u][i];
        if(v == pa) continue;
        ss[u][i] = (ss[u][i] * ((f[v] + 1) % mod)) % mod;
    }
}

void DFS2(int u, int pa, vector<vi>& tree, vector<vl>& ps, vector<vl>& ss, vl& f, vl& g){
    for(int i = 1; i < sz(tree[u]); i++){
        int v = tree[u][i];
        if(v == pa) continue;

        ll aux = (ps[u][i-1] * ss[u][i+1]) % mod;
        g[v] = (((aux * g[u]) % mod) + 1) % mod;

        DFS2(v, u, tree, ps, ss, f, g);
    }
}

void solver(){
    int n; cin>>n>>mod;
    vector<vi> tree(n+1, vi(1));
    vector<vl> ps(n+1, vl(1, 1)), ss(n+1, vl(2, 1));
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
        ps[u].pb(1); ss[u].pb(1);
        ps[v].pb(1); ss[v].pb(1);
    }

    vl f(n+1, 1), g(n+1, 1);

    DFS1(1, 0, tree, ps, ss, f);
    DFS2(1, 0, tree, ps, ss, f, g);

    for(int i = 1; i <= n; i++) cout<<(f[i] * g[i]) % mod<<endl;
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