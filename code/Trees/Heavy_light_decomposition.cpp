#include "../template.h"

/*
- Puede ser tanto 1-index como 0-index (ojo con la raiz por defecto).
- Para hacer queries conmutativas y updates en caminos de un arbol y en subarboles.
- Si los valores van en las aristas ve = 1, si van en los nodos ve = 0.
- Ajustar el segtree segun el tipo de update y el tipo de queries, teniendo en cuenta que para suma de valores en un camino
  y updates normales (no lazy) normalmente se puede hacer simplemente con Euler Tour.
- Esta escrito para segtree lazy, ajustar si se quiere normal.
- Si las updates se dan con el indice de las aristas toca almacenar el indice de la arista que conecta u con su padre.
- Construccion: O(n), hallar los rangos del path: O(log n), update y query path: O(log²n), update y query subtree: O(log n).
- Memoria: O(n).
- Para queries no conmutativas tocaria ordenar los rangos que devuelve path para que vayan de x hacia y (no se como xd).
*/
struct HLD {
    int n, t = 0; bool ve; vector<vi> g; vi par, dep, sub, head, pos, ord; segTree st;

    // g: lista de adyacencia, a: valor de cada nodo, r: raíz (1 por defecto), e: 1 si val en aristas, 0 si val en nodos
    HLD(vector<vi>& adj, vl& a, int r = 1, bool e = 0) : n(sz(adj)), ve(e), g(adj), par(n), dep(n), sub(n), head(n), pos(n) {
        dfs1(r); head[r] = r; dfs2(r);
        vl b; for(int x : ord) b.pb(a[x]);
        st.init(sz(b)); st.build(b);
    }
    void dfs1(int x){
        sub[x] = 1; // sub es el tamaño del subarbol
        for(int &y : g[x]){
            par[y] = x; dep[y] = dep[x] + 1;
            auto it = find(all(g[y]), x); if(it != g[y].end()) g[y].erase(it); // Si tiene arista al padre, la elimina
            dfs1(y); sub[x] += sub[y];
            if(sub[y] > sub[g[x][0]]) swap(y, g[x][0]);
        }
    }
    void dfs2(int x){
        pos[x] = t++; ord.pb(x); // pos[x] es la POSICION de x en el arreglo del segtree
        for(int y : g[x]){ head[y] = (y == g[x][0] ? head[x] : y); dfs2(y); } // g[x][0] es el hijo pesado de x
    }
    // rangos [l, r) a procesar (hacen parte del camino entre 'x' y 'y'), sin rangos vacíos
    vii path(int x, int y){
        vii r;
        for(; head[x] != head[y]; y = par[head[y]]){
            if(dep[head[x]] > dep[head[y]]) swap(x, y);
            r.pb({pos[head[y]], pos[y] + 1});
        }
        if(dep[x] > dep[y]) swap(x, y);
        if(pos[x] + ve < pos[y] + 1) r.pb({pos[x] + ve, pos[y] + 1});
        return r;
    }
    void updatePath(int x, int y, ll v){ for(auto p : path(x, y)) st.update(p.fi, p.se, v); }
    ll queryPath(int x, int y){
        ll res = 0; // CHANGEEE: Valor neutro de cual sea la operacion
        for(auto p : path(x, y)) res += st.calc(p.fi, p.se); // CHANGEEE segun la operacion
        return res;
    }
    void updateSub(int x, ll v){ if(ve < sub[x]) st.update(pos[x] + ve, pos[x] + sub[x], v); }
    ll querySub(int x){ return ve < sub[x] ? st.calc(pos[x] + ve, pos[x] + sub[x]) : 0 /*VALOR NEUTROOO*/; }
};

void solver(){
    // Inicializar
    int n, q, root; cin>>n>>q>>root;
    vector<vi> tree(n+1);
    // vector<vil> aux(n+1); // Si los pesos estan en las aristas
    for0(i, n-1){
        int u, v; cin>>u>>v;
        // ll w; cin>>w; // Si los pesos estan en las aristas
        tree[u].pb(v); tree[v].pb(u);
        // aux[u].pb({v, w}); aux[v].pb({u, w}); // Si los pesos estan en las aristas
    }
    vl val(n+1);
    for1(i, n) cin>>val[i]; // Si los pesos estan en los nodos, si no comentar

    // Si los pesos estan en las aristas:
    // function<void(int,int)> go = [&](int x, int p){ 
        // for(auto [y, c] : aux[x]) if(y != p){ val[y] = c; go(y, x); }
    // };
    // go(root, -1);

    HLD h(tree, val, root, valsInEdges); // 1 para valores en aristas, 0 para valores en vertices
    
    h.updatePath(x, y, valor); // Update path
    cout<<h.queryPath(x, y)<<endl; // Query path
    h.updateSub(x, valor); // Update subtree
    cout<<h.querySub(x)<<endl; // Query subtree
}