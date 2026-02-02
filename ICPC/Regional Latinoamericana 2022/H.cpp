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
		adj[a].pb({b, sz(adj[b]), c, c});
		adj[b].pb({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f){
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++){
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
			lvl = ptr = vector<int> (sz(q));
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
    int n; cin>>n;
    vs a(n);
    map<string, int> c;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        c[a[i]] = i;
    }

    int r; cin>>r;
    vi last(n);
    vb used(n);
    vector<vb> appear(n, vb(n, 1));
    for(int i = 0; i < r; i++){
        int m, w; cin>>m>>w; w--;
        used[w] = 1;
        vb aux(n);
        for(int j = 0; j < m; j++){
            string s; cin>>s;
            int idx = c[s];
            aux[idx] = 1;
            last[idx] = max(last[idx], w);
        }
        for(int j = 0; j < n; j++) if(!aux[j]) appear[j][w] = 0;
    }

    Dinic graph(2*n + 2);
    for(int i = 0; i < n; i++){
        graph.addEdge(0, i+2, 1);
        graph.addEdge(i+n+2, 1, 1);
        for(int j = last[i]; j < n; j++){
            if(!used[j] || appear[i][j]) graph.addEdge(i+2, j+n+2, 1);
        }
    }

    vi ans(n);
    assert(graph.calc(0, 1) == n);

    for(int i = 0; i < n; i++){
        for(auto &e : graph.adj[i+2]){
            if(e.flow() > 0 && e.oc > 0){
                ans[e.to - n - 2] = i;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<a[ans[i]];
    }
    cout<<endl;
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