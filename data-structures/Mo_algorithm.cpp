#include "../template.h"

/*
- Queries [l, r]
- Complejidad: O((n+q) * sqrt(n) * (complejidad add + del))
- Se ordenan las querys por bloque al que pertenece l y por
  r creciente si el bloque es par y r decreciente si el
  bloque es impar.
- Se usa principalmente para ejercicios en los cuales la
  funcion de consulta es facil de actualizar agregando o
  eliminando un elemento a la vez pero dificil de combinar
  entre dos rangos disjuntos, como contar la cantidad de 
  valores diferentes en un rango.
- Si para hacer las actualizaciones necesito hacer algun
  tipo de consultas en rango, sqrt decomposition es la mejor
  opcion ya que no aumenta la complejidad. Esto debido a que
  las updates son O(1) y las consultas O(sqrt(n)), y al ser
  q consultas, se mantiene el factor de q*sqrt(n).
- Se puede variar con que los bloques se definan por r en 
  lugar de l, que en el lado que se extiende solo se agregue
  y nunca se quite (siempre ++r o --l), que en el lado del
  bloque siempre se eliminen los valores y se vuelvan a
  agregar en cada query (por ejemplo para queries de solo
  tomar aristas en cierto rango).
- Consultas en subarbol:
  Se halla el rango de cada subarbol con Euler Tour Tecnique
  y se utiliza este para las queries, al pasar por la 
  posicion i, no se agrega ni elimina directamente la 
  posicion i sino la posicion orden[i]. (Euler Tour es 
  1-index asi que Inicializar con l = 1 y r = 0).
- Consultas en un camino de u hacia v en un arbol:
  * De manera similar, se usa Euler Tour pero esta vez cada 
    nodo se copia en el array tanto al iniciar como al terminar
    la visita de su subarbol (estos puntos de inicio y de fin 
    son marcados como su rango). 
  * Para cada query [u, v], primero se asegura que 
    ran[u].fi sea <= ran[v].fi.
  * Si lca(u,v) es u, se hace la query [ran[u].fi, ran[v].fi].
    Si no, se hace la query [ran[u].se, ran[v].fi] y 
    [ran[lca].fi, ran[lca].fi].
  * Igual que en la aplicacion anterior, al pasar los indices
    por la posicion i, no se usa el valor de i sino de orden[i].
  * Como cada valor se encuentra 2 veces en el array orden, si
    en el rango que se analiza el nodo i solo esta una vez, 
    entonces se tiene en cuenta, pero si en el rango el nodo i
    esta 0 o 2 veces, entonces no se tiene en cuenta.
*/

struct query {
    int l, r, idx;
};
int blen; // blen = sqrt(n)
bool cmp(query u, query v){
    int x = u.l / blen;
    if(x != v.l / blen) return x < v.l / blen;
    return x&1 ? u.r > v.r : u.r < v.r; // Bloque impar r decreciente, par r creciente
}

// Estas funciones se usan para hacer el proceso requerido al 
// agregar o eliminar valores y contestar queries
void add(int idx){

}
void del(int idx){

}
int getAns(){

}

void solver(){
    // Leer y ordenar las queries
    int q; cin>>q;
    blen = sqrt(n); // Raiz del tamaño del arreglo
    vector<query> qs(q);
    for0(i,q){
        cin>>qs[i].l>>qs[i].r;
        qs[i].idx = i;
    }
    sort(all(qs), cmp);

    // Procesar
    vi ans(q);
    int l = 0, r = -1;
    for0(i,q){
        while(r < qs[i].r) add(++r);
        while(l > qs[i].l) add(--l);
        while(r > qs[i].r) del(r--);
        while(l < qs[i].l) del(l++);
        ans[qs[i].idx] = getAns();
    }
}