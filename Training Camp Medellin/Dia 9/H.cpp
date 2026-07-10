#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr<< #x<<" "<<x<<endl
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int limite = 200010, inf = 1e9;

vb esPrimo(limite + 1, 1);
vi primos;

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(int i = 2; i < limite; i++)
        if(esPrimo[i]) primos.pb(i); 
}

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

struct Edge{
    int p, c, l;
};

struct comp{
    bool operator() (Edge a, Edge b){
        return a.l < b.l;
    }
};

bool check(int n, int k, vector<Edge>& edges, int m){
    vi par, impar;
    int ans = 0;
    pii max1 = {0, 0};
    Dinic graph(n + 2); //Crear un grafo para usar Dinic
    for(int i = 0; i < sz(edges); i++){
        Edge e = edges[i];
        if(e.l > m) break;
        if(e.c == 1){
            max1 = max(max1, {e.p, i});
            continue;
        }
        ans += e.p;
        if(e.c & 1){
            graph.addEdge(n, i, e.p);
            impar.pb(i);
        }
        else{
            graph.addEdge(i, n+1, e.p);
            par.pb(i);
        }
    }

    if(max1.fi){
        ans += edges[max1.se].p;
        graph.addEdge(n, max1.se, max1.fi);
        impar.pb(max1.se);
    }

    for(int x : impar){
        for(int y : par){
            if(esPrimo[edges[x].c + edges[y].c]) graph.addEdge(x, y, inf);
        }
    }

    ans -= graph.calc(n, n+1);
    return ans >= k;
}

void solver(){
    int n, k; cin>>n>>k;
    vector<Edge> edges(n);
    for(int i = 0; i < n; i++) cin>>edges[i].p>>edges[i].c>>edges[i].l;
    sort(all(edges), comp());

    int l = 1, r = n+1;
    while(l < r){
        int m = (l + r) / 2;
        if(check(n, k, edges, m)) r = m;
        else l = m+1;
    }

    cout<<(l <= n ? l : -1)<<endl;
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