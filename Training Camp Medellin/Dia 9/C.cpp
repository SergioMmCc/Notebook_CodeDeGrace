#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

vi BFS(int s, int n, vector<vi>& graph){
    vi dis(n+1);
    vb vis(n+1); vis[s] = 1;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }

    return dis;
}

void topoSort(int n, vi& orden, vi& inDegree, vector<vi>& graph){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!inDegree[i]){ 
            // Si el nodo no tiene ningun inDegree, quiere decir que puede ir al incio del topoSort
            q.push(i);
            orden.pb(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            inDegree[v]--; // Quitamos un inDegree a cada vertice que puede ser visitado desde otro ya procesado
            if(!inDegree[v]){ 
                // Si su inDegree ahora es 0, quiere decir que ya fueron procesados todos los nodos que lo 
                // anteceden, por ende ahora puede ser agregado al topoSort, y lo metemos a la cola
                q.push(v);
                orden.pb(v);
            }
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    vector<vi> graph(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vi d1 = BFS(1, n, graph), d2 = BFS(n, n, graph);
    vector<vi> DAG1(n+1), DAG2(n+1);
    vi ind1(n+1), ind2(n+1);
    for(int i = 1; i <= n; i++){
        for(int v : graph[i]){
            if(d1[i] + d2[v] + 1 == d1[n]){
                DAG1[i].pb(v);
                DAG2[v].pb(i);
                ind1[v]++;
                ind2[i]++;
            }
        }
    }

    vi o1, o2;
    topoSort(n, o1, ind1, DAG1);
    topoSort(n, o2, ind2, DAG2);
    vl dp1(n+1), dp2(n+1);
    dp1[1] = 1;
    for(int u : o1){
        for(int v : DAG1[u]){
            dp1[v] += dp1[u];
        }
    }

    dp2[n] = 1;
    for(int u : o2){
        for(int v : DAG2[u]){
            dp2[v] += dp2[u];
        }
    }

    vl prod(n+1);
    for(int i = 1; i <= n; i++) prod[i] = dp1[i] * dp2[i];

    ll maxp = dp1[n];
    for(int i = 2; i < n; i++){
        maxp = max(maxp, 2LL*prod[i]);
    }

    ld ans = (ld)maxp / (ld)dp1[n];
    cout<<fixed<<setprecision(8)<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
