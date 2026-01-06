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

const ll mod = 998244353;

const int maxn = 2e5 + 1;
vector<vector<int>> graph(maxn), gAux(maxn);
vector<bool> visited(maxn);
vector<int> dp(maxn), sons[maxn], father(maxn), depth(maxn);

void DFS(int u, int prev){
    visited[u] = 1;
    for(int v : graph[u]){
        if(v == prev) continue;
        if(visited[v]){
            if(depth[v] > depth[u]) continue;
            dp[u]++;
            dp[v]--;
            continue;
        }
        sons[u].pb(v);
        father[v] = u;
        depth[v] = depth[u] + 1;
        DFS(v, u);
    }
}

int calc(int u){
    for(int v : sons[u]) dp[u] += calc(v);
    return dp[u];
}

ll component(int s, vector<int>& side, vector<int>& c, ll v){
    queue<int> q; q.push(s);
    side[s] = 1;
    int maxc = c[s];
    bool bip = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : gAux[u]){
            if(side[v]){
                if(side[u] == side[v]) bip = 0;
                continue;
            }

            if(side[u] == 1) side[v] = 2;
            else side[v] = 1;
            q.push(v);

            if(maxc == c[v] || c[v] == -1) continue;
            if(maxc == -1) maxc = c[v];
            else return 0;
        }
    }

    if(!bip) return maxc > 0 ? 0 : 1;
    return maxc == -1 ? v : 1;
}

void solver(){
    int n, m; ll v; cin>>n>>m>>v;

    for(int i = 1; i <= n; i++){
        graph[i].clear();
        gAux[i].clear();
        visited[i] = 0;
        dp[i] = 0;
        sons[i].clear();
        father[i] = 0;
        depth[i] = 0;
    }

    vector<int> c(n+1);
    for(int i = 1; i <= n; i++) cin>>c[i];

    set<pii> e;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        e.insert({min(u, v), max(u, v)});
        graph[u].pb(v);
        graph[v].pb(u);
    }

    DFS(1, -1);
    calc(1);

    for(int i = 2; i <= n; i++) if(!dp[i]) e.erase({min(i, father[i]), max(i, father[i])});

    for(pii ed : e){
        gAux[ed.fi].pb(ed.se);
        gAux[ed.se].pb(ed.fi);
    }

    vector<int> side(n+1);
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        if(side[i]) continue;
        ans *= component(i, side, c, v);
        ans %= mod;
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