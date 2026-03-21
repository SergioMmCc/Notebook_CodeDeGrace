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

int BFS1(int n, vector<vi>& tree){
    queue<int> q; q.push(1);
    vb vis(n+1); vis[1] = 1;
    int last = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
            last = v;
        }
    }

    return last;
}

pii BFS2(int s, int n, vector<vi>& tree, vi& pa){
    queue<int> q; q.push(s);
    vb vis(n+1); vis[s] = 1;
    vi dis(n+1);
    pii ans = {0, s};
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            dis[v] = dis[u] + 1;
            q.push(v);
            ans = max(ans, {dis[v], v});
            pa[v] = u;
        }
    }

    return ans;
}

void solver(){
    int n; cin>>n;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    int u = BFS1(n, tree);
    vi pa(n+1);
    pii aux = BFS2(u, n, tree, pa);
    int l = aux.fi, v = aux.se;

    if(l == n-1){
        cout<<-1<<endl;
        return;
    }

    vb path(n+1); path[v] = 1;
    int run = v;
    while(pa[run]){
        run = pa[run];
        path[run] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(!path[i] && path[pa[i]]){
            cout<<pa[pa[i]]<<' '<<pa[i]<<' '<<i<<endl;
            return;
        }
    }
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