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

const int maxn = 1e5 + 1;
const ll inf = 1e15;
vector<vector<pil>> graph(maxn);

// Complejidad O(n * m)
/* 
    Sirve cuando tenemos pesos negativos y detecta si hay ciclos negativos.
    Si bien su complejidad en el peor de los casos es la misma que en Bellman-Ford,
    suele ser mejor para un grafo promedio.
*/

// Implementacion normal:
bool spfa(int s, int n, vector<ll>& d){
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0;
    vector<int> count(n+1);
    vector<bool> in(n+1);
    in[s] = 1;
    queue<int> q;
    q.push(s);
 
    while(!q.empty()){
        int u = q.front(); q.pop();
        in[u] = 0; // Marca que el vertice ya no esta en la cola
 
        for(pil edge : graph[u]){
            int v = edge.fi; ll w = edge.se;
            
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                if(!in[v]){ // Antes de agregar un vertice a la cola, verifica que no se encuentre ya en ella
                    in[v] = 1; // Marca que el vertice ahora esta en la cola
                    q.push(v);
                    count[v]++;
                    if(count[v] > n)
                        return 0; // Si el nodo ha sido metido en la cola más de n veces, hay un ciclo negativo
                }
            }
        }
    }
 
    return 1; // No hay ciclos negativos
}

// Implementacion usando mcfx optimization:
/*
    Esta implementacion utiliza "mcfx optimization", la cual consiste en utilizar una 
    deque en lugar de una queue, antes de agregar cada vertice revisamos si este ha 
    sido procesado entre 2 y sqrt(n) veces, le damos prioridad a visitarlo y por ende 
    lo agregamos al inicio de la deque. En cambio, si solo ha sido procesado una vez, 
    no hay nada raro con este, y cuando ha sido visitado muchas veces (mas de sqrt(n)), 
    posiblemente sea un "bad vertex" o "trick vertex", el cual nos lleva a un camino 
    suboptimo y por ende en estos 2 casos, no le damos prioridad a volver a visitar a 
    este vertice y lo agregamos al final de la deque. Si bien esta optimizacion tambien
    corre en O(n * m), en muchos casos logra correr mas rapido, evitando el TLE.
    - Suele funcionar muy bien en grid graphs (grafos tipo cuadro)
    - No funciona bien en star graphs (un nodo central y n-1 aristas, las cuales conectan
      los nodos perifericos con el nodo central)
*/
bool spfa(int s, int n, vector<ll>& d){
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0;
    vector<int> count(n+1);
    vector<bool> in(n+1);
    in[s] = 1;
    deque<int> q;
    q.push_front(s);

    int mini = 2, maxi = sqrt(n) + 5;
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        in[u] = 0; // Marca que el vertice ya no esta en la cola

        for(pil edge : graph[u]){
            int v = edge.fi; ll w = edge.se;
            
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                if(!in[v]){ // Antes de agregar un vertice a la cola, verifica que no se encuentre ya en ella
                    in[v] = 1; // Marca que el vertice ahora esta en la cola
                    if(count[v] >= mini && count[v] <= mini) q.push_back(v);
                    else q.push_front(v);
                    count[v]++;
                    if(count[v] > n)
                        return 0; // Si el nodo ha sido metido en la cola más de n veces, hay un ciclo negativo
                }
            }
        }
    }

    return 1; // No hay ciclos negativos
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; ll w; cin>>u>>v>>w;
        graph[u].pb({v, w});
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