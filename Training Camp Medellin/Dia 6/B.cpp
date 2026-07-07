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

void solver(){
    int n, m; cin>>n>>m;
    int x = n*m;

    vector<vi> graph(x+1);
    vi d(x+1, -1), low(x+1), scc(x+1), reps(x+1, 0);
    vb stacked(x+1);
    stack<int> s;
    int ticks = 0, current_scc = 0;

    vs maze(n);
    for(int i = 0; i < n; i++){
        cin>>maze[i];
    }
    int ig;
    for(int i = 0; i < m; i++) cin>>ig;

    int take = x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] != '#') continue;
            take--;
            int u = m*i + j + 1;
            if(i && maze[i-1][j] == '#') graph[u].pb(m*(i-1) + j + 1);
            if(j && maze[i][j-1] == '#') graph[u].pb(m*i + j);
            if(j < m-1 && maze[i][j+1] == '#') graph[u].pb(m*i + j + 2);

            for(int k = i+1; k < n; k++){
                if(j && maze[k][j-1] == '#') graph[u].pb(m*k + j);
                if(j < m-1 && maze[k][j+1] == '#') graph[u].pb(m*k + j + 2);
                if(maze[k][j] == '#'){
                    graph[u].pb(m*k + j + 1);
                    break;
                }
            }
        }
    }

    // Hallar los SCC
    for(int i = 1; i <= x; i++){
        if(d[i] == -1) 
            tarjan(i, graph, d, low, scc, reps, stacked, s, ticks, current_scc);
    }

    vector<vi> graph2(current_scc+1);
    vi inDegree(current_scc+1);
    for(int i = 1; i <= x; i++){
        for(int v : graph[i]){ // Buscar en las aristas del grafo original
            if(scc[v] != scc[i]){ // Verificar que la arista vaya a otro SCC
                graph2[scc[i]+1].pb(scc[v]+1);
                inDegree[scc[v]+1]++;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= current_scc; i++) if(!inDegree[i]) ans++;
    cout<<ans - take<<endl;
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