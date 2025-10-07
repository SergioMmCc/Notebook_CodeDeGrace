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

int ckmin(int &a, int b) { return a > b ? ((a = b), true) : false; }

/**
 * return the jobs of each worker in the optimal assignment,
 * or -1 if the worker is not assigned
 */
template <class T> vector<int> hungarian(const vector<vector<T>> &C){
	int J = C.size();
	int W = C[0].size();
	assert(J <= W);

	// job[w] = job assigned to w-th worker, or -1 if no job assigned
	// note: a W-th worker was added for convenience
	vector<int> job(W + 1, -1);
	vector<T> h(W);  // Johnson potentials

	const T inf = numeric_limits<T>::max();
	// assign j_cur-th job using Dijkstra with potentials
	for(int j_cur = 0; j_cur < J; j_cur++){
		int w_cur = W;  // unvisited worker with minimum distance
		job[w_cur] = j_cur;

		vector<T> dist(W + 1, inf);  // Johnson-reduced distances
		dist[W] = 0;
		vector<bool> vis(W + 1);     // whether visited yet
		vector<int> prv(W + 1, -1);  // previous worker on shortest path
		while(job[w_cur] != -1){   // Dijkstra step: pop min worker from heap
			T min_dist = inf;
			vis[w_cur] = true;
			int w_next = -1;  // next unvisited worker with minimum distance

			// consider extending shortest path by w_cur -> job[w_cur] -> w
			for(int w = 0; w < W; w++){
				if(!vis[w]){
					// sum of reduced edge weights w_cur -> job[w_cur] -> w
					T edge = C[job[w_cur]][w] - h[w];
					if (w_cur != W) {
						edge -= C[job[w_cur]][w_cur] - h[w_cur];
						assert(edge >= 0);
					}
					if (ckmin(dist[w], dist[w_cur] + edge)) { prv[w] = w_cur; }
					if (ckmin(min_dist, dist[w])) { w_next = w; }
				}
			}
			w_cur = w_next;
		}

		for(int w = 0; w < W; w++){  // update potentials
			ckmin(dist[w], dist[w_cur]);
			h[w] += dist[w];
		}

		while(w_cur != W){  // update job assignment
			job[w_cur] = job[prv[w_cur]];
			w_cur = prv[w_cur];
		}
	}

	return job; // Retorna la mejor asignacion encontrada
}

int dis(pii a, pii b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

void solver(){
    int n, m; cin>>n>>m;
    vector<pii> a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    for(int i = 0; i < m; i++) cin>>b[i].fi>>b[i].se;
    pii r; cin>>r.fi>>r.se;

    int ans = 0, aum = 5000;
    vector<vector<int>> c(n, vector<int>(m));
    vector<int> dr(n);
    for(int i = 0; i < n; i++){
        dr[i] = dis(r, a[i]);
        ans += dr[i];
        int minus = 5000;
        for(int j = 0; j < m; j++){
            c[i][j] = dis(a[i], b[j]);
            minus = min(minus, c[i][j]);
            c[i][j] = min(c[i][j], dr[i]);
        }

        aum = min(aum, minus - dr[i]);
    }

    if(aum > 0){
        ans *= 2;
        ans += aum;
        cout<<ans<<endl;
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = m; j < n; j++){
            c[i].pb(dr[i]);
        }
    }

	m = max(m, n);

    vector<int> mat = hungarian(c);
    for(int i = 0; i < m; i++) if(mat[i] != -1) ans += c[mat[i]][i];

    cout<<ans<<endl;
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