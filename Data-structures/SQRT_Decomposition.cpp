#include "../template.h"

/*
- 0-index
- Complejidad: build O(n), update O(1), calc O(sqrt(n)).
- Ajustar el tamaño del bloque a conveniencia.
- La complejidad de update depende de la complejidad de reversar el calculo.
- Ejemplo con suma en rango.

Trucos para hacer soluciones en sqrt(n) (no necesariamente usando la estructura):
- Queries de menor distancia a un nodo marcado, y queries de marcar nodos:
  Para un problema donde se tienen queries de hallar la menor distancia desde
  un nodo u hacia cualquier nodo marcado (ya sea en un arbol o matriz) y
  queries de marcar algun nodo, se puede resolver combinando 2 algoritmos:
  * Se crea un array con la distancia actual de cada nodo hacia todos los 
    marcados inicialmente (si no hay ninguno se pone como inf).
  * Cuando se marca un nodo, agregarlo a una lista de ultimos nodos marcados.
  * Cuando dicha lista llega a sqrt(n) nodos, se hace un BFS empezando 
    simultaneamente en cada uno. Se halla la distancia de todos los nodos a 
    los de esta lista y se revisa si esta distancia es menor a la que se tenia 
    guardada antes (y se actualiza). Al final se limpia la lista.
  * Cuando se pregunta la menor distancia de u hacia cualquier nodo marcado, 
    primero se revisa la distancia hacia cualquiera de los nodos ya procesados
    y despues se revisa la distancia de u hacia cualquiera de los nodos que
    estan actualmente en la lista (procurar que esa distancia se pueda revisar
    en O(1) o de alguna forma muy eficiente).
- A cada nodo se le da una letra, hallar minima distancia entre dos nodos con
  la misma letra:
  * Si una letra k esta en <= sqrt(n) nodos, se va a traves de cada par nodos
    con esta letra y se calcula su distancia (hacerlo en O(1)).
  * Si una letra k esta en mas de sqrt(n) nodos, se hace un BFS empezando
    simultaneamente en cada uno para hallar la distancia.
- Si me dan numeros positivos (o longitudes) diferentes, y me dicen que la suma 
  de estos es maximo n, entonces como maximo tengo sqrt(n) numeros diferentes.
  A veces eso se puede usar para resolver ejercicios en O(sqrt(n)) o O(n*sqrt(n)).
*/

struct sqrtDecomp{
    int n, blen;
    vl a, b;
    sqrtDecomp(){}
    sqrtDecomp(vl& arr): n(sz(arr)), blen(sqrt(n)+1), a(arr), b(blen){
        for0(i,n) b[i/blen] += a[i];
    }

    void update(int pos, ll val){
        b[pos/blen] += val - a[pos];
        a[pos] = val;
    }

    ll calc(int l, int r){ // [l, r]
        ll sum = 0;
        int bl = l/blen, br = r/blen;
        if(bl == br) forlr(i,l,r) sum += a[i]; // Si l y r estan en el mismo bloque
        else{
            forlr(i, l, blen*(bl+1)-1) sum += a[i]; // Indices en el bloque izquierdo
            forlr(i, blen*br, r) sum += a[i]; // Indices en el bloque derecho
            forlr(i, bl+1, br-1) sum += b[i]; // Bloques centrales
        }
        return sum;
    }
};

void solver(){
    int n; cin>>n;
    vl a(n);
    for0(i,n) cin>>a[i];

    // Inicializar
    sqrtDecomp sq(a);

    // Update
    int pos; ll val; cin>>pos>>val;
    sq.update(pos, val);

    // Calc
    int l, r; cin>>l>>r;
    cout<<sq.calc(l, r)<<endl;
}