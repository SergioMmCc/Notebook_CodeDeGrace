#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int>> graph(501); 

void topoSort(int n, vector<int>& in){
    queue<int> q;
    for(int i = 1; i <= n; i++) if(!in[i]) q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
}

vector<int> BFS(int s, int n){
    vector<int> vis(n+1); vis[s] = 1;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(i != s && vis[i]) ans.pb(i);
    }
    return ans;
}

struct comp{
    bool operator() (pii a, pii b){
        if(a.se == b.se)
            return a.fi < b.fi;
        return a.se < b.se;
    }
};

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0){
		adj[a].pb({b, (int)adj[b].sz, c, c});
		adj[b].pb({a, (int)adj[a].sz - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f){
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].sz; i++){
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))){
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t){
		ll flow = 0; q[0] = s;
		for(ll L = 0; L < 31; L++) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int> (q.sz);
			int qi = 0, qe = lvl[s] = 1;
			while(qi < qe && !lvl[t]){
				int v = q[qi++];
				for(Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; } // 1 si es parte del lado de source
};

void solver(){
    int n, m; cin>>n>>m;
    vector<int> in(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v; u++; v++;
        graph[u].pb(v);
        in[v]++;
    }

    topoSort(n, in);
    int res = 0;

    Dinic g(2*n + 2);
    for(int i = 1; i <= n; i++){
        if(in[i]){
            res++;
            continue;
        }
        g.addEdge(0, 2*i, 1);
        g.addEdge(2*i + 1, 1, 1);
        vector<int> adj = BFS(i, n);
        for(int v : adj){
            // cout<<"pos -> "<<i<<' '<<v<<endl;
            g.addEdge(2*i, 2*v + 1, 1);
        }
    }

    cout<<n - res - g.calc(0, 1)<<endl;
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