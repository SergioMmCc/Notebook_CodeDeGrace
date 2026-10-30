#include "../template.h"

/*
- 1-index, para 0-index cambiar en la inicializacion "comp(n-1)"
  por "comp(n)" y en lugar de llamarlo como "DSU uf(n+1)", 
  llamarlo como "DSU uf(n)".
- Compresion de caminos y union-by-size.
- Al hacer join(a, b), retorna 0 si 'a' y 'b' ya estaban en el mismo
  componente, retorna 1 y actualiza en caso contrario.
- Complejidad: Inicializacion O(n), find y join O(α(n)).
*/

struct DSU {
    vi p, len; int comp; // p es el lider de cada nodo
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
    DSU uf(n+1);
    for0(i,m){
        int u, v; cin>>u>>v;
        uf.join(u, v);
    }

    // Preguntar si 2 vertices estan en el mismocomponente
    cout<<(uf.find(u) == uf.find(v) ? "Mismo componente" : "Diferente componente")<<endl;

    cout<<uf.comp<<endl; // Numero de componentes tras agregar todas las aristas
}