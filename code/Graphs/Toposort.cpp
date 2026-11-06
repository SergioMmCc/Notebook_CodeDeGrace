#include "../template.h"

// Complejidad: O(n + m)

void topoSort(int n, vi& orden, vi& inDegree, vector<vi>& graph){
    queue<int> q;
    for1(i,n){
        if(!inDegree[i]){ // Agregar si no tiene aristas de entrada
            q.push(i);
            orden.pb(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            inDegree[v]--;
            if(!inDegree[v]){ // Agregar si ya se visitaron todos sus predecesores
                q.push(v);
                orden.pb(v);
            }
        }
    }
}

void solver(){
    // Construir
    int n, m; cin>>n>>m;
    vi inDegree(n+1);
    vector<vi> graph(n+1);
    for0(i,m){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        inDegree[v]++;
    }

    // Hallar
    vi ans;
    topoSort(n, ans, inDegree, graph);
    if(sz(ans) < n) cout<<"IMPOSSIBLE"<<endl; // Si ans no tiene todos los nodos, no es un DAG
    else{
        for0(i,sz(ans)){
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
}