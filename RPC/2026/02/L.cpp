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
typedef pair<ll, int> pli;
typedef pair<pli, int> plii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<plii> vlii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

struct comp{
    bool operator() (plii a, plii b){
        if(a.fi.fi == b.fi.fi) return a.fi.se > b.fi.se;
        return a.fi.fi < b.fi.fi;
    }
};

stack<int> BFS(int s, int n, vl& dis, vi& pa, vi& ps, vb& check, vector<vi>& tree){
    queue<int> q; q.push(s);
    vb vis(n+1); vis[s] = 1;
    stack<int> order; order.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            order.push(v);
            vis[v] = 1;
            q.push(v);
            pa[v] = u;
            ps[v] = check[u] ? u : ps[u];
            dis[v] = dis[u] + 1;
        }
    }

    return order;
}

void solver(){
    int n, m, k; cin>>n>>m>>k;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vii racer(m);
    vi runn(n+1, -1);
    for(int i = 0; i < m; i++){
        cin>>racer[i].fi>>racer[i].se;
        runn[racer[i].fi] = i;
    }

    int fin; cin>>fin;

    vb check(n+1);
    int p; cin>>p;
    for(int i = 0; i < p; i++){
        int aux; cin>>aux;
        check[aux] = 1;
    }

    vi pa(n+1), ps(n+1, fin);
    vl dis(n+1);
    stack<int> order = BFS(fin, n, dis, pa, ps, check, tree);

    vector<set<plii>> pos(n+1);
    vl ans(m, -1);

    while(!order.empty()){
        int u = order.top(); order.pop();

        if(u == fin){
            for(plii x : pos[u]){
                ans[x.se] = x.fi.fi;
            }
            continue;
        }

        if(runn[u] >= 0){
            int ins = check[u] ? u : ps[u];
            pos[ins].insert({{(ll)racer[runn[u]].se * (dis[u] - dis[ins]), racer[runn[u]].se}, runn[u]});
            if(ins != fin && sz(pos[ins]) > k){
                auto it = pos[ins].end(); --it;
                pos[ins].erase(it);
            }
        }

        if(pos[u].empty()) continue;

        for(plii x : pos[u]){
            pos[ps[u]].insert({{x.fi.fi + (ll)racer[x.se].se * (dis[u] - dis[ps[u]]), x.fi.se}, x.se});
            if(ps[u] != fin && sz(pos[ps[u]]) > k){
                auto it = pos[ps[u]].end(); --it;
                pos[ps[u]].erase(it);
            }
        }
    }

    for(int i = 0; i < m; i++) cout<<ans[i]<<endl;
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