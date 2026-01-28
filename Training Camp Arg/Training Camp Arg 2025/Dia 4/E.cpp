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

struct comp{
    bool operator() (pii a, pii b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
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
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].pb({b, adj[b].size(), c, c});
		adj[b].pb({a, adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
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

vector<pii> check(int k, int n, int m, vector<pii> edges){
    Dinic graph(n + m + 2);
    for(int i = 1; i <= n; i++) graph.addEdge(0, i, k);
    for(int i = 0; i < m; i++){
        int u = edges[i].fi, v = edges[i].se;
        graph.addEdge(u, i + n + 1, 1);
        graph.addEdge(v, i + n + 1, 1);
        graph.addEdge(i + n + 1, n + m + 1, 1);
    }

    int ans = graph.calc(0, n + m + 1);

    vector<pii> adj;
    if(ans == m){
        for(int u = 1; u <= n; ++u) {
            for(auto &e : graph.adj[u]) {
                int v = e.to;
                ll f = e.flow(); // f = flujo enviado desde u a v

                // Mostrar solo aristas "reales" (no las de retroceso)
                if(f > 0 && e.oc > 0){
                    int index = v - n - 1;
                    int aux = edges[index].fi == u ? edges[index].se : edges[index].fi;
                    adj.pb({u, aux});
                }
            }
        }
    }

    return adj;
}

void solver(){
    int n, m; cin>>n>>m;
    if(!m){
        cout<<0<<endl;
        return;
    }
    vector<pii> edges(m);
    for(int i = 0; i < m; i++) cin>>edges[i].fi>>edges[i].se;

    int l = 0, r = n / 2 + 1; int ans = r;
    vector<pii> adj;
    while(l <= r){
        int k = (l + r) / 2;
        vector<pii> aux;
        aux = check(k, n, m, edges);
        if(aux.sz){
            swap(adj, aux);
            ans = k;
            r = k - 1;
        }
        else l = k + 1;
    }

    cout<<ans<<endl;
    for(int i = 0; i < m; i++) cout<<adj[i].fi<<' '<<adj[i].se<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}