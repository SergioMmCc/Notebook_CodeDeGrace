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

void topoSort(int n, vi& orden, vi& inDegree, vector<vi>& graph, vb& vis){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!inDegree[i] && vis[i]){ 
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
    vb imp(n+1);
    vb vis(n+1);
    queue<int> q;
    for(int i = 0; i < m; i++){
        int aux; cin>>aux;
        q.push(aux);
        imp[aux] = 1;
        vis[aux] = 1;
    }

    vector<vi> g1(n+1);
    for(int i = 1; i <= n; i++){
        int num; cin>>num;
        while(num--){
            int v; cin>>v;
            g1[i].pb(v);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g1[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }

    int cnt = 0;
    vector<vi> g2(n+1);
    vi inDegree(n+1);
    for(int i = 1; i <= n; i++){
        if(!vis[i]) continue;
        cnt++;
        for(int v : g1[i]){
            if(vis[v]){
                g2[v].pb(i);
                inDegree[i]++;
            }
        }
    }

    vi orden;
    topoSort(n, orden, inDegree, g2, vis);
    if(sz(orden) != cnt){
        cout<<-1<<endl;
        return;
    }

    cout<<sz(orden)<<endl;
    for(int x : orden) cout<<x<<' ';
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