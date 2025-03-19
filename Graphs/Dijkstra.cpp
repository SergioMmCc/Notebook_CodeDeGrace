#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, ll> pil;

const int maxn = 1e5 + 1;
const ll inf = 1e15;
vector<vector<pil>> graph(maxn);

struct comp{
    bool operator() (pil a, pil b){
        return a.second > b.second;
    }
};

// Complejidad O(m*log(n))
void dijkstra(int source, int n, vector<ll>& d, vector<int>& parent){
    for(int i = 1; i <= n; i++){
        d[i] = inf;
        parent[i] = -1;
    }   
    d[source] = 0;
    priority_queue<pil, vector<pil>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first; ll w1 = pq.top().second;
        pq.pop();
        if(d[u] < w1) continue;
        for(pil edge : graph[u]){
            int v = edge.first; ll w2 = edge.second;
            if(d[v] > w1 + w2){
                d[v] = w1 + w2;
                parent[v] = u;
                pq.push({v, d[v]});
            }
        }
    }
}

// Algunas aplicaciones:
/*
    Tambien sirve para grafos con pesos negativos siempre y cuando no haya ciclos 
    negativos, en ese caso usar Bellman-Ford
*/

/* 
    Para saber las k menores distancias desde s hasta t (usando k caminos diferentes)
    podemos modificar el vector de distancias, haciendo que sea un vector de colas de 
    prioridad. Asi cuando llegamos para cada nodo almacenamos las k distancias menores.
    Entonces cuando sacamos un nodo u de la cola de prioridad del dijkstra, verificamos
    si su peso mayor en su cola de prioridad es menor que el que estamos analizando en
    el momento, en caso de que si, continuamos con la siguiente iteracion. Luego, para
    cada nodo adyacente v, verificamos si este aun no tiene k elementos en su cola de 
    prioridad y agregamos el nuevo peso tanto en su cola de prioridad como en la del
    dijkstra. En caso de que si tenga k elementos, verificamos si la distancia w1 mas
    el peso de la arista que estamos analizando es menor que el valor mayor de la cola
    de prioridad de v, en caso de que si, sacamos el valor mayor de la cola de prioridad
    de v y ponemos esta nueva distancia, ademas de agregarla a la cola de prioridad del
    dijkstra.

    La complejidad es O(m*k*log(n*k)), por lo tanto m*k debe ser pequeño.
    Link de un ejercicio: https://cses.fi/problemset/task/1196/
*/

/*  
    Para saber si una arista puede estar en un camino más corto desde s hasta t
    podemos hacer un dijsktra desde s y desde t, despues recorrer cada arista u, v
    y revisar si la distancia de s hasta u, mas la distancia de t hasta v, (o la
    distancia desde s hasta v mas la distancia desde t hasta u si el grafo es no
    dirigido) mas el peso de esa arista es igual a la distancia desde s hasta t, 
    en caso de que si, quiere decir que esa arista puede hacer parte de un camino
    más corto desde s hasta t.
    También se puede hacer para grafos dirigidos. En ese caso, el dijkstra desde t
    tiene que hacerse inviertiendo todas las aristas del grafo. 
*/

/*  
    Para saber si una arista está en todos los caminos más cortos desde s hasta t
    (que para llegar de s hasta t de la manera mas eficiente posible si o si tengo
    que pasar por cierta arista) podemos armar un grafo auxiliar con las aristas
    que pueden estar en un camino mas corto de s hasta t. Lo podemos armar como si
    fuera un grafo dirigido teniendo en cuenta la distancia de s a los vertices u y
    v de la arista. Despues recorremos el grafo con un BFS de la siguiente manera: 
*/

void BFS(int s, int t, int n, vector<bool>& ans, map<pill, int>& edges, vector<vector<pil>>& graph, vector<int>& inDegree){
    // ans está inicializado con 0s
    vector<bool> visited(n+1); visited[s] = 1;
    queue<int> q; q.push(s);
    int roads = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u != t) roads += graph[u].sz - 1; // Aumentamos roads con el numero de salidas de u, - 1
        for(pil edge : graph[u]){
            int v = edge.first; ll w = edge.second;
            int index = edges[{{u, v}, w}]; // Para acceder al indice de la arista;
                                            // tener cuidado por si la arista en el grafo fuera (v, u) en lugar de (u, v)
            if(roads == 1) ans[index] = 1; // Si roads es 1, esa arista está en todos los caminos más cortos de s a t

            // Despues de visitar v por primera vez, cada que lo vuelva a visitar disminuyo roads
            if(visited[v]) roads--;
            visited[v] = 1; // Marco que ya lo visite por si es la primera vez
            inDegree[v]--; // Resto su número de aristas de entrada
            if(!inDegree[v]) q.push(v); // Cuando he visitado la ultima arista que entra en v, lo meto en la cola
        }
    }
}

void solver(){
    int n, m, s; cin>>n>>m>>s;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<ll> d(n+1);
    vector<int> parent(n+1);
    dijkstra(s, n, d, parent);
    for(int i = 1; i <= n; i++)
        cout<<"vertex: "<<i<<" d: "<<d[i]<<" parent: "<<parent[i]<<endl;
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