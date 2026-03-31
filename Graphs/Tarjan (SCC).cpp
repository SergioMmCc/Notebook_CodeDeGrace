#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back

/* 
    Tarjan’s algorithm for finding strongly connected
    components.
    Complexity: O(E + V)
    - d[i] = Discovery time of node i. (Initialize to -1)
    - low[i] = Lowest discovery time reachable from node
      i. (Doesn’t need to be initialized)
    - scc[i] = Strongly connected component of node i. (Doesn’t
      need to be initialized) (0-index)
    - s = Stack used by the algorithm (Initialize to an empty
      stack)
    - stacked[i] = True if i was pushed into s. (Initialize to
      false)
    - ticks = Clock used for discovery times (Initialize to 0)
    - current_scc = ID of the current_scc being discovered
      (Initialize to 0)

    Aplicaciones:
    - Al comprimir cada SCC como un nodo individual, se obtiene un DAG
    - Si de un SCC A hay un camino a otro SCC B, no hay camino de B hacia A
    - Si se invierten todas las aristas, los SCC no cambian
*/

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

    vector<vi> graph(n+1);
    vi d(n+1, -1), low(n+1), scc(n+1), reps(n+1, 0);
    vb stacked(n+1);
    stack<int> s;
    int ticks = 0, current_scc = 0;

    for(int i = 1; i <= m; i++){
        int u, v;cin>>u>>v;
        graph[u].pb(v);
    }

    // Hallar los SCC
    for(int i = 1; i <= n; i++){
        if(d[i] == -1) 
            tarjan(i, graph, d, low, scc, reps, stacked, s, ticks, current_scc);
    }

    cout<<current_scc<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}