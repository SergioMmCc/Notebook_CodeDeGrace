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

void solver(){
    map<string, int> T = {{"S", 0}, {"M", 1}, {"L", 2}, {"XL", 3}, {"XXL", 4}, {"XXXL", 5}};
    map<int, string> R = {{0, "S"}, {1, "M"}, {2, "L"}, {3, "XL"}, {4, "XXL"}, {5, "XXXL"}};

    vector<int> a(6);
    for(int i = 0; i < 6; i++) cin>>a[i];
    int n; cin>>n;
    Dinic graph(n + 8);
    for(int i = 0; i < 6; i++) graph.addEdge(i, n + 7, a[i]);
    for(int i = 0; i < n; i++) graph.addEdge(n + 6, i + 6, 1);

    for(int i = 0; i < n; i++){
        string s; cin>>s;
        int j = 0;
        while(j < s.sz){
            string aux = "";
            while(j < s.sz && s[j] != ','){
                aux += s[j];
                j++;
            }

            j++;
            graph.addEdge(i + 6, T[aux], 1);
        }
    }

    int ans = graph.calc(n + 6, n + 7);
    if(ans != n){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i = 6; i < n + 6; i++){
        for(auto &e : graph.adj[i]) {
			int v = e.to;
			ll f = e.flow(); // f = flujo enviado desde u a v

			// Mostrar solo aristas "reales" (no las de retroceso)
			if (f > 0 && e.oc > 0) {
				cout<<R[v]<<endl;
                break;
			}
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