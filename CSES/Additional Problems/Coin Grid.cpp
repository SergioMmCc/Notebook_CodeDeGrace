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
			lvl = ptr = vector<int> (q.sz);
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

const ll inf = 1e7;

void solver(){
    int n; cin>>n;
    Dinic graph(2*n + 2);
    for(int i = 1; i <= n; i++){
        graph.addEdge(0, i, 1);
        graph.addEdge(n + i, 2*n + 1, 1);
        string save; cin>>save;
        for(int j = 1; j <= n; j++) if(save[j-1] == 'o') graph.addEdge(i, n + j, inf);
    }

    cout<<graph.calc(0, 2*n + 1)<<endl;

    for(auto &e : graph.adj[0]){
        int v = e.to;
        if(!graph.leftOfMinCut(v)) cout<<1<<' '<<v<<endl;
    }
    for(int u = n+1; u <= 2*n; u++){
        if(!graph.leftOfMinCut(u)) continue;
        for(auto &e : graph.adj[u]){
			int v = e.to;
            if(v != 2*n + 1) continue;
            cout<<2<<' '<<u - n<<endl;
            break;
		}
    }
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