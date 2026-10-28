#include "../template.h"

/*
- Implementacion del algoritmo de Hierholzer para hallar un
  camino (y posiblemente circuito) euleriano.
- Esta implementacion es obligatoriamente 1-index.
- Si no hay aristas se imprime 1 (podria ser cualquier nodo)
- Complejidad: O(V + E).
- Un camino euleriano pasa exactamente una vez por cada 
  arista del grafo. 
- Un circuito euleriano es un camino euleriano que inicia y 
  termina en el mismo nodo.

Un camino euleriano existe si todas las aristas pertenecen 
al mismo componente y:
* Para grafos no dirigidos:
    - El grado de todos los nodos es par (en este caso tambien
      es un circuito).
    - El grado de exactamente 2 nodos es impar y el del resto
      es par (en este caso el camino inicia en uno de estos y
      termina en el otro).
* Para grafos dirigidos:
    - El inDegree y outDegree de todos los nodos es igual
      (tambien es circuito).
    - Exactamente un nodo tiene inDegree + 1 == outDegree
      (nodo inicial) y exactamente un nodo tiene
      inDegree == outDegree + 1 (nodo final).


APLICACION: DE BRUJIN SEQUENCES:
- Es una secuencia en la cual de un conjunto de k caracteres
  aparece cada cadena posible de longitud n exactamente una
  vez como subcadena.
- Si se puede conectar los ultimos caracteres de la cadena
  con los primeros (como si fuera ciclicla), entonces la
  secuencia tiene tamaño k^n. 
  Ej: K={0,1}, n=2 -> 0011. (00, 01, 11, 10), donde la subcadena 
  '10' se da conectando el ultimo caracter con el primero.
- Si no es ciclica, entonces tiene tamaño k^n + n - 1. Con el
  mismo ejemplo la secuencia puede ser: 00110.
  La version ciclica es simplemente los primeros k^n caracteres
  de esta.
- COMO HALLARLA:
  * Se construye un grafo dirigido donde los nodos son todas las
    cadenas de longitud n-1 (k^(n-1) nodos) y donde cada cadena
    de longitud n es una arista que conecta el nodo que 
    corresponde a su primeros n-1 caracteres con el que 
    corresponde a sus ultimos n-1 caracteres.
    De esta forma se obtiene un grafo conexo donde cada nodo va 
    a tener k aristas de salida y k aristas de entrada.
  * Se halla el circuito euleriano desde cualquier nodo inicial
    y para la secuencia se toma el ultimo caracter de cada arista
    que se visita (que es el mismo ultimo caracter del nodo al 
    que lleva dicha arista) (TENER EN CUENTA que se debe modificar 
    el vector ans para que guarde este caracter, ya que actualmente 
    lo que guarda son los nodos). Debido a como funciona el codigo,
    al vector ans que se recibe al final toca hacerle reverse y
    ya se obtiene la respuesta en orden.
    Para la version no ciclica, antes de hacer el reverse se 
    agregan al final los caracteres del nodo inicial en orden 
    inverso y entonces ya se hace el reverse.
*/

void DFS(int u, vector<vii>& graph, vb& used, vi& ans){
    while(!graph[u].empty()){
        pii edj = graph[u].back();
        int v = edj.fi, idx = edj.se;
        graph[u].pop_back(); // Eliminar arista ya visitada
        if(used[idx]) continue; // En caso de ya haber visitado esta arista partiendo desde v
        used[idx] = 1;
        DFS(v, graph, used, ans);
    }
    ans.pb(u);
}

// Para grafos no dirigidos
void solverNoDirected(){
    int n, m; cin>>n>>m;
    if(!m){cout<<1<<endl;return;} // SI no hay aristas imprime cualquier nodo
    vector<vii> graph(n+1);
    vi degree(n+1);
    for0(i,m){
        int u, v; cin>>u>>v;
        graph[u].pb({v, i});
        graph[v].pb({u, i});
        degree[u]++;
        degree[v]++;
    }

    int a = 0, b = 0; // Nodos desbalanceados
    for1(i,n){
        if(degree[i] & 1){ // Si se quiere un ciclo, simplemente retornar que no se puede
            if(!a) a = i;
            else if(!b) b = i;
            else{
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }

    vb used(m+1);
    vi ans;
    if(a) DFS(a, graph, used, ans); // Llamar a partir del nodo inicial (si lo hay)
    else{
        for1(i,n){
            if(degree[i]){ // Llamar desde un nodo que tenga aristas de salida
                DFS(i, graph, used, ans);
                break;
            }
        }
    }

    if(sz(ans) != m+1){ // Si no todas las aristas estan en el mismo componente
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    for(int x : ans) cout<<x<<' '; // Camino euleriano por orden de visita de los nodos
    cout<<endl;
}

// Para grafos dirigidos
void solverDirected(){
    int n, m; cin>>n>>m;
    if(!m){cout<<1<<endl;return;} // SI no hay aristas imprime cualquier nodo
    vector<vii> graph(n+1);
    vi inDegree(n+1), outDegree(n+1);
    for0(i,m){
        int u, v; cin>>u>>v;
        graph[u].pb({v, i});
        outDegree[u]++;
        inDegree[v]++;
    }

    int a = 0, b = 0; // a seria el nodo inicial y b el nodo final
    for1(i,n){
        if(inDegree[i] > outDegree[i]){ // Si se quiere un ciclo, simplemente retornar que no se puede
            if(inDegree[i] == outDegree[i] + 1 && !b) b = i; // Este tendria que ser el nodo final
            else{
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
        else if(inDegree[i] < outDegree[i]){ // Si se quiere un ciclo, simplemente retornar que no se puede
            if(inDegree[i] + 1 == outDegree[i] && !a) a = i; // Este tendria que ser el nodo inicial
            else{
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }

    if((a && !b) || (!a && b)){ // Si solo hay nodo inicial o solo hay nodo final
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vb used(m+1);
    vi ans;
    if(a) DFS(a, graph, used, ans); // Llamar a partir del nodo inicial (si lo hay)
    else{
        for1(i,n){
            if(outDegree[i]){ // Llamar desde un nodo que tenga aristas de salida
                DFS(i, graph, used, ans);
                break;
            }
        }
    }

    if(sz(ans) != m+1){ // Si no todas las aristas estan en el mismo componente
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    reverse(all(ans));
    for(int x : ans) cout<<x<<' '; // Camino euleriano por orden de visita de los nodos
    cout<<endl;
}