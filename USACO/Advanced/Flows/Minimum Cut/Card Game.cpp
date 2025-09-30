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

const int inf = 1e6, limite = 2e5 + 1;

vector<bool> esPrimo(limite + 1, 1);

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }
}

struct Edge{
    int p, c, l;
};

struct comp{
    bool operator() (Edge a, Edge b){
        return a.l < b.l;
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

bool check(int k, vector<Edge>& edges, int mini){
    vector<Edge> impar, par;
    int p1 = 0, total = 0;
    for(Edge e : edges){
        if(e.l > k) break;
        if(e.c == 1) p1 = max(p1, e.p);
        else{
            total += e.p;
            if(e.c % 2) impar.pb(e);
            else par.pb(e);
        }
    }
    total += p1;
    impar.pb({p1, 1, k});

    int n = impar.sz, m = par.sz;
    Dinic graph(n + m + 2);

    for(int i = 0; i < n; i++){
        graph.addEdge(n + m, i, impar[i].p);
        for(int j = 0; j < m; j++){
            if(esPrimo[impar[i].c + par[j].c]) graph.addEdge(i, n + j, inf);
        }
    }

    for(int j = 0; j < m; j++) graph.addEdge(n + j, n + m + 1, par[j].p);

    int ans = graph.calc(n + m, n + m + 1);
    ans *= -1;
    ans += total;
    return ans >= mini;
}

void solver(){
    int n, k; cin>>n>>k;
    vector<Edge> edges(n);
    for(int i = 0; i < n; i++) cin>>edges[i].p>>edges[i].c>>edges[i].l;
    sort(edges.begin(), edges.end(), comp());
    
    int i = 1, j = n, ans = -1;
    while(i <= j){
        int m = (i + j) / 2;
        bool cond = check(m, edges, k);
        if(cond){
            ans = m;
            j = m - 1;
        }
        else i = m + 1;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    sieve();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}