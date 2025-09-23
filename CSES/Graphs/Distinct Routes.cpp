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

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].pb({b, (int)adj[b].sz, c, c});
		adj[b].pb({a, (int)adj[a].sz - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].sz; i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		for(ll L = 0; L < 31; L++) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int> (q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solver(){
    int n, m; cin>>n>>m;
    Dinic graph(n + 2); //Crear un grafo para usar Dinic

    for(int i = 0; i < m; i++){
        int s, d; cin>>s>>d;
        graph.addEdge(s, d, 1);
    }
    
    cout<<graph.calc(1, n)<<endl;

    vector<queue<int>> paths(n);
    for(int u = 0; u < n; ++u) {
		for(auto &e : graph.adj[u]) {
			int v = e.to;
			ll f = e.flow(); // f = flujo enviado desde u a v

			// Mostrar solo aristas "reales" (no las de retroceso)
			if (f > 0 && e.oc > 0) paths[u].push(v);
		}
	}

    while(!paths[1].empty()){
        queue<int> ans; ans.push(1);
        int u = 1;
        while(u != n){
            int v = paths[u].front();
            paths[u].pop();
            u = v;
            ans.push(u);
        }

        cout<<ans.sz<<endl;
        while(!ans.empty()){
            cout<<ans.front()<<' ';
            ans.pop();
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}