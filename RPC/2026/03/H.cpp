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

struct node{
    int ver, pa, da, dd;
};

const int inf = 20000;
vector<vii> graph(101);
vector<vector<vb>> mark(101, vector<vb>(101, vb(101)));
vector<vector<vi>> dis(101, vector<vi>(101, vi(102, inf)));

struct comp{
    bool operator() (node a, node b){
        if(a.da == b.da) return a.dd > b.dd;
        return a.da > b.da;
    }
};

void dijkstra(int s, int d){
    dis[s][0][0] = 0;
    priority_queue<node, vector<node>, comp> pq;
    pq.push({s, 0, 0, 0});
    while(!pq.empty()){
        int u = pq.top().ver, pa = pq.top().pa, da = pq.top().da, dd = pq.top().dd;
        pq.pop();
        if(dis[u][pa][dd] < da) continue;
        for(pii edge : graph[u]){
            int v = edge.fi, w = edge.se;
            if(v == pa) continue;
            if(mark[pa][u][v]){
                if(dd + w > d || dis[v][u][dd+w] < da + w) continue;
                
                dis[v][u][dd+w] = da + w;
                pq.push({v, u, da + w, dd + w});
                continue;
            }

            int aux = w;
            if(w > d) aux = d+1;
            if(dis[v][u][aux] > da + w){
                dis[v][u][aux] = da + w;
                pq.push({v, u, da + w, aux});
            }
        }
    }
}

void solver(){
    int n, m, k, d, s, t; cin>>n>>m>>k>>d>>s>>t;
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        graph[u].pb({v, w});
        graph[v].pb({u, w});
    }

    for(int i = 0; i < k; i++){
        int a, b, c; cin>>a>>b>>c;
        mark[a][b][c] = 1;
    }

    dijkstra(s, d);
    int ans = inf;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= d+1; j++){
            ans = min(ans, dis[t][i][j]);
        }
    }

    if(ans == inf) cout<<"impossible"<<endl;
    else cout<<ans<<endl;
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