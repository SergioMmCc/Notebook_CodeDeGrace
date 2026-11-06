#include "../template.h"

/*
- Se le van agregando aristas a un grafo y avisa cual es la
  primer arista que al agregarse hace que el grafo deje de ser
  bipartito.
- Para realizarlo se duplican los nodos, de modo que cada nodo
  nodo 'u' se duplica siendo tambien el nodo 'u+n' (siendo 'n'
  el total de nodos del grafo original). Entonces en este 
  grafo el nodo 'u' representa al 'u' original en el lado '0' 
  y 'u+n' representa al 'u' original en el lado '1' del 
  bipartito. 
  Cada que se agrega una arista u->v en el grafo original, en
  el grafo duplicado se crean aristas u->v+n y u+n->v.
  Si en algun punto, cuando se va a agregar una arista u->v en
  el grafo original, 'u' y 'v' estan en el mismo componente 
  del grafo duplicado, quiere decir que hay una conexion entre
  nodos del mismo color, asi que el grafo deja de ser 
  bipartito desde esa arista.
- En cualquier punto (mientras el grafo aun pueda ser 
  considerado bipartito), si dos nodos 'u' y 'v' (del grafo 
  duplicado) estan en el mismo componente, quiere decir que 
  en el grafo original son del mismo color. Si 'u' y 'v+n' 
  estan en el mismo componente entonces son de diferente.
  Si no se cumple ninguna, quiere decir que no estan en el
  mismo componente en el grafo original y por ende podrian
  ser de cualquier color.
*/

struct DSU {
    vi p, len; int comp;
    DSU(int n) : p(n), len(n, 1), comp(n-1) { iota(all(p), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool join(int a, int b){
        if((a = find(a)) == (b = find(b))) return 0;
        if(len[a] < len[b]) swap(a, b);
        p[b] = a; len[a] += len[b]; --comp;
        return 1;
    }
};

void solver(){
    int n, m; cin>>n>>m;
    
    DSU uf(2*n + 1);
    int badIdx = 0;
    for1(i,m){
        int u, v; cin>>u>>v;
        if(badIdx) continue;

        if(uf.find(u) == uf.find(v)) badIdx = i; // Primer arista que rompe el bipartito
        else{
            uf.join(u, v+n);
            uf.join(u+n, v);
        }
    }

    cout<<"La primera arista que rompe el bipartito es: "<<badIdx<<endl;
}