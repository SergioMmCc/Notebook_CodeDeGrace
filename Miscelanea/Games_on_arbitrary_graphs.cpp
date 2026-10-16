#include "template.h"

/*
- Para juegos donde ambos juagadores juegan optimamente, en grafos 
  dirigidos arbitrarios, se quiere saber cuales estados (vertices) 
  son ganadores, perdedores o llevan a empate.
- En caso de que los movimientos no dependan solo del vertice sino
  tambien de cual jugador tiene el turno se debe tomar cada estado como
  una pareja {vertice, jugador}.
- Si un estado no tiene aristas de salida o si todas sus aristas llevan
  a estados ganadores, es perdedor.
- Si un estado tiene al menos una arista a un estado perdedor, es ganador.
- Si ninguna de estas se cumple, este estado lleva a un ciclo donde no va
  a haber un ganador.
- Complejidad: O(m).
- Si las transiciones de los estados son similares (ir a los lados en un 
  laberinto, desde cada vertice u ir al vertice u + x, etc). Se puede
  evitar consruir el grafo para ahorrar memoria.
*/

const int maxn = 2e5 + 1;
vector<vi> graph(maxn);
vi indegree(maxn);
vb win(maxn), lose(maxn), vis(maxn);
void DFS(int u){
    vis[u] = 1;
    for(int v : graph[u]){
        if(vis[v]) continue;
        if(lose[u]) win[v] = 1;
        else if(--indegree[v] == 0) lose[v] = 1;
        else continue;
        DFS(v);
    }
}

void solver(){
    // Crear grafo
    int n, m; cin>>n>>m;
    for0(i,m){
        int u, v; cin>>u>>v;
        graph[v].pb(u); // Guardar las aristas alreves
        indegree[u]++;
    }

    // Procesar
    for1(i,n) if(!indegree[i]) lose[i] = 1;
    for1(i,n) if(lose[i]) DFS(i);

    // Resultados
    for1(i,n){
        if(win[i]) cout<<i<<" es ganador"<<endl;
        if(lose[i]) cout<<i<<" es perdedor"<<endl;
        else cout<<i<<" lleva a empate"<<endl;
    }
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