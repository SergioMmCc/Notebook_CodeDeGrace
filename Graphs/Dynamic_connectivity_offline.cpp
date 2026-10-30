#include "../template.h"

/*
IMPORTAR DSU ROLLBACK
- 1-index.
- Complejidad: O(Q*log(Q)*log(n)) tiempo, O(n + Q) memoria 
  (Q = operaciones).
- Dynamic connectivity offline: se guardan todas las operaciones
  de agregar arista, borrar arista y las queries.
  process() responde las consultas en orden.
  * add(u, v): agrega la arista u->v (no debe estar ya presente).
  * remove(u, v): borra la arista u->v (debe estar presente).
  * query(): imprime el numero de componentes en ese momento.
    + Si se quiere otro tipo de consulta, se debe cambiar la 
      informacion que se esta imprimiendo en el primer if dentro 
      de la funcion "go".
    + Asi mismo, se podrian hacer varios tipos de queries, 
      agregando las necesarias en "enum" y en el primer if de la 
      funcion "go".
    + Si se quieren queries que pregunten informacion de algun 
      nodo o par de nodos, se cambia "query()" por "query(u)" o 
      "query(u, v)".
- mt[i] es el emparejamiento de la operacion i:
  * ADD: indice de su DEL (operacion en que se elimina) (sz(q) si 
    nunca se elimina)
  * DEL: indice de su ADD (operacion en que se agrega)
  * QUERY: -1.
- go(s, e) al entrar, el DSU ya tiene todas las aristas vivas 
  durante todo el rango [s, e). Para cada mitad [s, m) y [m, e)
  (con m = (s+e)/2) se agregan las aristas que cubren esa mitad 
  completa (y no todo [s, e)), se hacen los llamados recursivos 
  a cada mitad y se hace rollback.
EXTRAS
- No maneja aristas multiples. Para hacerlo habria que agregar el 
  parametro "idx" a las funciones "add" y "remove", y que la 
  clave del mapa "prv" ahora no solo incluya los 2 vertices sino 
  tambien "idx". Tambien habria que ajustar el solver para que se
  guarden las aristas como un mapa de stack, asi cuando se quiera
  eliminar una arista se busca la ultima vez que se agrego y este 
  sea el parametro "idx" para la funcion "delete" (ademas de 
  eliminar esta ultima aparicion en la pila).
*/


enum {ADD, DEL, QUERY}; // Agregar mas operaciones de consulta de ser necesario
struct Query { int type, u, v; };

struct DynCon {
    vector<Query> q; DSURollback uf;
    vi mt; map<pii,int> prv;
    DynCon(int n) : uf(n+1) {}
    void add(int u, int v){
        if(u > v) swap(u, v);
        q.pb({ADD, u, v}); mt.pb(-1);
        prv[{u, v}] = sz(q)-1;
    }
    void remove(int u, int v){
        if(u > v) swap(u, v);
        q.pb({DEL, u, v});
        int pr = prv[{u, v}];
        mt[pr] = sz(q)-1; mt.pb(pr);
    }
    void query(){ q.pb({QUERY, -1, -1}); mt.pb(-1); } // Agregar parametros nodos de ser necesario
    void process(){ // responde todas las consultas en orden
        if(!sz(q)) return;
        for0(i,sz(q)) if(q[i].type == ADD && mt[i] < 0) mt[i] = sz(q);
        go(0, sz(q));
    }
    void go(int s, int e){
        if(s+1 == e){
            if(q[s].type == QUERY) cout<<uf.comps<<endl; // Cambiar la operacion de ser necesario
            return;
        }
        int m = (s+e)/2;

        uf.checkpoint();
        forlr(i,m,e-1) if(mt[i] >= 0 && mt[i] < s) uf.join(q[i].u, q[i].v);
        go(s, m);
        uf.rollback();

        uf.checkpoint();
        forlr(i,s,m-1) if(mt[i] >= e) uf.join(q[i].u, q[i].v);
        go(m, e);
        uf.rollback();
    }
};

void solver(){
    // Crear
    int n, q; cin>>n>>q;
    DynCon dc(n);
    for0(i,q){
        string op; cin>>op;
        if(op == "ADD"){ int u, v; cin>>u>>v; dc.add(u, v); } // Agregar arista
        else if(op == "DEL"){ int u, v; cin>>u>>v; dc.remove(u, v); } // Eliminar arista
        else dc.query(); // Consultar el numero de componentes
    }
    dc.process(); // Procesar
}