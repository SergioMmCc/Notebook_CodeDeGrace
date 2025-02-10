#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2e5 + 1;
vector<vector<int>> graph(maxn);
vector<bool> visited(maxn);
vector<int> topo_sort;

// Sirve para hallar un "Topological Sort" en un DAG (Directed Acyclic Graph)
// Un "Topological Sort", es una forma de ordenar los nodos dado que para cada
// arista dirigida de 'u' a 'v', 'u' aparece antes que 'v' en el orden
// Esta implementacion se base en un DFS, por ende la complejidad es O(n + m)
void DFS(int u, vector<int>& orden){
    for(int v : graph[u]){
        if(visited[v]) continue;
        visited[v] = 1;
        DFS(v, orden);
    }
    orden.pb(u);
}

bool topoSort(int n, vector<int>& orden){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            DFS(i, orden);
        }
    }

    reverse(orden.begin(), orden.end());

    vector<int> pos(n+1);
    for(int i = 1; i <= n; i++) pos[orden[i-1]] = i;
    // Para cada vertice guardamos su posicion en el toposort

    bool valid = 1;
    for(int i = 1; valid && i <= n; i++){
        for(int j : graph[i]){
            if(pos[j] <= pos[i]){ 
                // Para cada arista, si la posicion de i (source) es 
                // mayor o igual a la de j (to), quiere decir que no
                // hay un orden valido
                valid = 0;
                break;
            }
        }
    }

    return valid;
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
    }

    vector<int> ans;
    bool cond = topoSort(n, ans);
    if(!cond) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i = 0; i < ans.sz; i++){
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
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