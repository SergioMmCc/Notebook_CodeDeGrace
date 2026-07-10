#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

const int maxn = 3e5 + 5;
vector<vector<int>> graph(maxn);
vector<bool> visited(maxn);
vector<int> dp(maxn), sons[maxn], father(maxn), depth(maxn);

void DFS(int u, int prev){
    visited[u] = 1;
    for(int v : graph[u]){
        if(v == prev) continue;
        if(visited[v]){ // Back-edge
            // Revisar que la arista vaya de abajo hacia arriba
            // para no considerarla 2 veces
            if(depth[v] > depth[u]) continue;
            dp[u]++;
            dp[v]--;
            continue;
        }
        sons[u].pb(v); // Span-edge
        father[v] = u;
        depth[v] = depth[u] + 1;
        DFS(v, u);
    }
}

int calc(int u){
    for(int v : sons[u]) dp[u] += calc(v);
    return dp[u];
}

void BFS(int s, vb& vis, set<pii>& b, vi& comp, int cntComp){
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(b.find({v, u}) != b.end() || b.find({u, v}) != b.end() || vis[v]) continue;
            vis[v] = 1;
            comp[v] = cntComp;
            q.push(v);
        }
    }
}

pii BFS1(int s, int n, vector<vi>& tree){
    queue<int> q; q.push(s);
    vb vis(n+1); vis[s] = 1;
    vi dis(n+1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }

    pii ans = {0, 0};
    for(int i = 1; i <= n; i++) ans = max(ans, {dis[i], i});
    return ans;
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    DFS(1, -1); // Crear DFS tree
    calc(1); // Calcular el dp

    set<pii> b;
    for(int i = 2; i <= n; i++){
        // Si dp[i] == 0, la arista que conecta i y su padre son un puente
        if(!dp[i]) b.insert({father[i], i});
    }

    int cntComp = 1;
    vb vis(n+1);
    vi comp(n+1);
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        comp[i] = cntComp;
        BFS(i, vis, b, comp, cntComp);
        cntComp++;
    }

    vector<vi> tree(cntComp);
    for(pii e : b){
        tree[comp[e.fi]].pb(comp[e.se]);
        tree[comp[e.se]].pb(comp[e.fi]);
    }

    if(cntComp == 2){
        cout<<0<<endl;
        return;
    }

    pii s = BFS1(1, cntComp-1, tree);
    cout<<BFS1(s.se, cntComp-1, tree).fi<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
