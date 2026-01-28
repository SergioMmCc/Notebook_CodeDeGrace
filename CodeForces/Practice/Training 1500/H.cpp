#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void BFS(int n, vector<int> graph[], vector<int>& distance, vector<int>& father){
    father[1] = -1;
    vector<bool> visited(n + 1);
    visited[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(visited[v]) continue;
            q.push(v);
            father[v] = u;
            visited[v] = 1;
            distance[v] = distance[u] + 1;
        }
    }
}

void solver(){
    int n; cin>>n;
    vector<int> graph[n+1], distance(n+1), father(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    BFS(n, graph, distance, father);

    // Comprobar cantidad de nodos con cada profundidad y cuales son hojas
    // Hijos de cada nodo no hoja
    vector<int> prof[n + 1], hijos(n + 1);
    vector<bool> leaf(n + 1), deleted(n + 1);
    for(int i = 2; i <= n; i++){
        prof[distance[i]].pb(i);
        hijos[i] = graph[i].sz - 1;
        if(graph[i].sz == 1) leaf[i] = 1;
    }

    // Prefix Sum de la cantidad de elementos de profundidad menor o igual a i
    vector<int> psProfLen(n + 1);
    psProfLen[0] = 1;
    for(int i = 1; i < n; i++){
        psProfLen[i] = psProfLen[i-1] + (int)prof[i].sz;
    }

    // Inicializar respuesta dejando hojas de tamaño 1
    int ans = n - psProfLen[1];
    
    // Testear movimientos para cada profundidad de hoja
    int cutted = 0;
    for(int iProf = 2; iProf < n; iProf++){
        if(!prof[iProf].sz) break;
        for(int u : prof[iProf - 1]){
            if(!leaf[u]) continue;

            // Borrar el camino desde una hoja que solo le queda 1 hijo
            // Si la hoja tiene mas de un hijo, solo le resto 1
            cutted++;
            deleted[u] = 1;
            u = father[u];
            while(u != 1 && !deleted[u]){
                hijos[u]--;
                if(!hijos[u]){
                    cutted++;
                    deleted[u] = 1;
                    u = father[u];
                }
                else break;
            }
        }

        int aux = n - psProfLen[iProf] + cutted;
        ans = min(ans, aux);
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}