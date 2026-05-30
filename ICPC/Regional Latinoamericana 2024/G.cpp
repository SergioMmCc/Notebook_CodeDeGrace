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
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

vector<piii> f(1e5 + 1, {(int)1e9, {0, 0}});
vector<piii> g(1e5 + 1, {(int)1e9, {0, 0}});
vector<piii> h(1e5 + 1, {(int)1e9, {0, 0}});
vector<piii> win(1e5 + 1);
vi cnt(1e5 + 1);

vi ans(1e5);
vector<vii> queries(1e5 + 1);

void DFS1(int u, int pa, vector<vii>& tree){
    if(sz(tree[u]) == 1) f[u] = {0, {u, u}};
    for(pii e : tree[u]){
        int v = e.fi, w = e.se;
        if(v == pa) continue;
        DFS1(v, u, tree);

        piii comp = {f[v].fi + w, {f[v].se.fi, v}};
        if(comp < f[u]){
            g[u] = f[u];
            f[u] = comp;
        }
        else g[u] = min(comp, g[u]);
    }

    win[u] = f[u];
    cnt[win[u].se.fi]++;
}

void DFS2(int u, int pa, vector<vii>& tree){
    bool leaf = sz(tree[u]) == 1;
    for(pii e : tree[u]){
        int v = e.fi, w = e.se;
        if(v == pa) continue;

        if(leaf) h[v] = {w, {u, u}};
        else{
            h[v] = {h[u].fi + w, {h[u].se.fi, u}};
            piii comp = f[u].se.se == v ? g[u] : f[u];
            comp.fi += w; comp.se.se = u;
            h[v] = min(h[v], comp);
        }

        DFS2(v, u, tree);
    }
}

void DFS3(int u, int pa, vector<vii>& tree){
    for(pii q : queries[u]) ans[q.se] = cnt[q.fi];
    
    for(pii e : tree[u]){
        int v = e.fi, w = e.se;
        if(v == pa) continue;

        if(win[u].se.fi != win[v].se.fi){ // A cada uno lo toma su propio subarbol
            piii save = win[v];
            piii comp = {win[u].fi + w, {win[u].se.fi, u}};
            bool cond = 0;
            if(comp < win[v]){
                cond = 1;
                win[v] = comp;
                cnt[comp.se.fi]++;
                cnt[save.se.fi]--;
            }
            DFS3(v, u, tree);
            if(cond){
                win[v] = save;
                cnt[comp.se.fi]--;
                cnt[save.se.fi]++;
            }
        }
        else{ // Ambos los toma el subarbol de v
            piii save = win[u];
            piii comp = f[u].se.se == v ? g[u] : f[u];
            win[u] = comp;
            cnt[comp.se.fi]++;
            cnt[save.se.fi]--;
            DFS3(v, u, tree);
            win[u] = save;
            cnt[comp.se.fi]--;
            cnt[save.se.fi]++;
        }
    }
}

void solver(){
    int n; cin>>n;
    vector<vii> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v, w; cin>>u>>v>>w;
        tree[u].pb({v, w});
        tree[v].pb({u, w});
    }

    DFS1(1, 0, tree);
    DFS2(1, 0, tree);

    for(int i = 1; i <= n; i++){
        if(h[i] < f[i]){
            g[i] = f[i];
            f[i] = h[i];
        }
        else g[i] = min(g[i], h[i]);
    }

    int q; cin>>q;
    for(int i = 0; i < q; i++){
        int a, b; cin>>a>>b;
        queries[b].pb({a, i});
    }

    DFS3(1, 0, tree);
    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
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