#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, ll> pil;

struct Edge{
    int u, v; ll w;
};

const ll inf = 1e15;

// Complejidad O(n * m)
/*
    Permite saber la menor distancia desde s hacia cualquier vertice, en un grafo con pesos negativos.
    Si el grafo no tiene pesos negativos, usar Dijkstra.
    En caso de que haya un ciclo negativo alcanzable desde s, permite saberlo

    Para saber si el grafo tiene algun ciclo negativo no necesariamente alcanzable desde un vertice s, 
    podemos inicializar todas las distancias en 0 y el proceso es el mismo

    Para saber si hay un ciclo negativo en algun camino desde s hasta t, podemos correr el Bellman-Ford, 
    marcar los vertices para los cuales puede haber una mejora en la n-esima ronda (lo cual quiere decir que
    estos vertices hacen parte de algun ciclo negativo alcanzable desde s) y despues correr un BFS o DFS 
    con t como source, invirtiendo las arisats del grafo. Si alguna arista marcada es alcanzable desde t, 
    quiere decir que si hay ciclos negativos en el camino desde s hasta t.
*/
bool bellmanFord(int s, int n, vector<Edge>& edges, vector<ll>& d){
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0;

    for(int i = 1; i < n; i++){
        bool cond = 0;
        for(Edge e : edges){
            int u = e.u, v = e.v; ll w = e.w;
            if(d[u] < inf && d[v] > d[u] + w){ 
                // Si d[u] == inf, quiere decir que ese nodo aun no se ha podido alcanzar desde s
                d[v] = d[u] + w;
                cond = 1; // Marcamos que en esta ronda hubo al menos una mejora
            }
        }

        // Si en alguna ronda no hay ninguna mejora, significa que ya no podemos optimizar mas las distancias
        if(!cond) return 1; 
        // Retornamos 1 ya que si hubieran ciclos negativos alcanzables desde s, siempre podriamos mejorar las distancias
    }

    // Hacemos una n-esima ronda, si en esta hay alguna mejora, quiere 
    // decir que hay ciclos de peso negativo alcanzables desde s en el grafo
    for(Edge e : edges){
        int u = e.u, v = e.v; ll w = e.w;
        if(d[u] < inf && d[v] > d[u] + w) return 0; // Si hay ciclos de peso negativo alcanzables desde s
    }

    return 1; // No hay ciclos de peso negativo alcanzables desde s
}

void solver(){
    int n, m; cin>>n>>m;
    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        int u, v; ll w; cin>>u>>v>>w;
        edges.pb({u, v, w});
    }

    vector<ll> d(n+1);
    bool cond = bellmanFord(1, n, edges, d);
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