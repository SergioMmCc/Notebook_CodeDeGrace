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

void tarjan(int u, vector<vi>& graph, vi&d, vi& low, vi& scc, vi& reps, vb& stacked, stack<int>& s, int& ticks, int& current_scc){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vi &out = graph[u];
    for(int k=0, m=out.size(); k<m; ++k){
        const int &v = out[k];
        if(d[v] == -1){
            tarjan(v, graph, d, low, scc, reps, stacked, s, ticks, current_scc);
            low[u] = min(low[u], low[v]);
        }
        else if(stacked[v])
            low[u] = min(low[u], low[v]);
    }
    if(d[u] == low[u]){
        int v;
        do{
            v = s.top();
            s.pop();
            stacked[v] = false;
            scc[v] = current_scc;
        }while (u != v);
        current_scc++;
    }
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
    vector<vi> graph(2*m+1);
    for(int i = 1; i <= n; i++){
        char op1, op2; int u, v; cin>>op1>>u>>op2>>v;
        if(op1 == '+' && op2 == '+'){
            graph[2*u - 1].pb(2*v);
            graph[2*v - 1].pb(2*u);
        }
        else if(op1 == '+' && op2 == '-'){
            graph[2*u - 1].pb(2*v - 1);
            graph[2*v].pb(2*u);
        }
        else if(op1 == '-' && op2 == '+'){
            graph[2*u].pb(2*v);
            graph[2*v - 1].pb(2*u - 1);
        }
        else{
            graph[2*u].pb(2*v - 1);
            graph[2*v].pb(2*u - 1);
        }
    }

    vi d(2*m + 1, -1), low(2*m + 1), scc(2*m + 1), reps(2*m + 1, 0);
    vb stacked(2*m + 1);
    stack<int> s;
    int ticks = 0, current_scc = 0;
    for(int i = 1; i <= 2*m; i++) if(d[i] == -1) tarjan(i, graph, d, low, scc, reps, stacked, s, ticks, current_scc);

    vector<vi> comp(current_scc+1);
    for(int i = 1; i <= m; i++){
        if(scc[2*i - 1] == scc[2*i]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        comp[scc[2*i - 1] + 1].pb(2*i - 1);
        comp[scc[2*i] + 1].pb(2*i);
    }

    // Comprimir
    vi inDegree(current_scc + 1);
    vector<vi> graph2(current_scc+1);
    for(int i = 1; i <= 2*m; i++){
        for(int x : graph[i]){
            if(scc[x] == scc[i]) continue;
            graph2[scc[i]+1].pb(scc[x]+1);
            inDegree[scc[x]+1]++;
        }
    }

    // Toposort
    vi orden;
    topoSort(current_scc, orden, inDegree, graph2);
    vb ans(m+1), vis(m+1);
    for(int c : orden){
        for(int u : comp[c]){
            int num = (u+1)/2;
            if(!vis[num]){
                vis[num] = 1;
                ans[num] = u & 1;
            }
        }
    }

    for(int i = 1; i <= m; i++){
        if(i > 1) cout<<' ';
        cout<<(ans[i] ? '+' : '-');
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