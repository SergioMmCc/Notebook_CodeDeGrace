#include "../template.h"

/*
- 1-index.
- Permite hacer borrado de aristas, con el orden de una pila.
- La complejidad es la igual a la del DSU normal, en este 
  caso usando union-by-size sin compresion.
Funcionamiento:
- Cuando se agrega una arista u->v, si 'u' y 'v' ya estaban 
  en el mismo componente esta se ignora. De lo contrario se 
  agrega al DSU y a la pila de aristas.
- Se hacen checkpoints para guardar estados del DSU, asi 
  cuando se quiere hacer rollback se restaura el DSU hasta el 
  ultimo checkpoint y se borra este.
- checkpoint guarda la cantidad de operaciones reales que se 
  han hecho en el DSU hasta ahora. Quiere decir que al hacer 
  join entre dos nodos que ya estan en el mismo componente, 
  esta operacion no se cuenta.
- Si en los rollback se quiere borrar la arista 
  inmediatamente anterior, es posible que esta haya sido 
  ignorada ya que conectaba dos nodos que ya estaban en el 
  mismo componente.
  Para manejar este caso se hace checkpoint cada que se 
  agrega una arista al grafo. 
Aplicaciones:
- Tambien se puede usar para cualquier otro tipo de DSU como
  revisar si un grafo es bipartito.
*/

struct DSURollback {
    vi p, len;
    stack<pii> st; stack<int> save;
    int comps;

    DSURollback(int n) : p(n), len(n, 1), comps(n-1) { iota(all(p), 0); }
    int find(int x){
        while(p[x] != x) x = p[x];
        return x;
    }
    bool join(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return 0;
        if(len[a] < len[b]) swap(a, b);
        p[b] = a; len[a] += len[b]; comps--;
        st.push({a, b});
        return 1;
    }
    void checkpoint() { save.push(sz(st)); }
    void rollback(){ // Deshace hasta el ultimo checkpoint
        if(save.empty()) save.push(0); // Si no habia checkpoint, borrar todo
        while(sz(st) > save.top()){
            auto [a, b] = st.top(); st.pop();
            len[a] -= len[b]; p[b] = b; comps++;
        }
        save.pop();
    }
};

void solver(){
    int n, q; cin>>n>>q;
    DSURollback uf(n+1);
    for0(i,q){
        int op; cin>>op;
        if(op == 1){ // Agregar arista
            int u, v; cin>>u>>v;
            uf.join(u, v);
        }
        else if(op == 2) uf.checkpoint(); // Agregar guardado
        else if(op == 3) uf.rollback(); // Hacer rollback al ultimo guardado
        else cout<<uf.comps<<endl; // Query -> Numero actual de componentes del grafo
    }
}