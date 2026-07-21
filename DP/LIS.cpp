#include "../template.h"

// Complejidad: O(n * log(n))
/*
- LIS:
  es un array a donde para cada i, j con i < j, a[i] < a[j].
- Reconstruccion:
  Se puede usar un enfoque con indices en el cual cada que se ubica
  un elemento en el array del LIS se guarda el indice del elemento 
  anterior y su propio indice. De esta manera cuando se termina el 
  procesamiento, se toma el indice del ultimo valor del LIS y se va 
  viajando hacia el indice que se puso como anterior a este, hasta 
  llegar al primer elemento.
- Elementos que no estan en ningun LIS:
  Si mi array original es a, contruyo otro array b donde 
  b[n-i-1] = -a[i] (0-index). Entonces hago el LIS para ambos arrays
  y calculo la posicion en la que ubico cada elemento en ambos.
  Si pos_a[i] + pos_b[i] - 1 != ValLIS, a[i] no puede estar en el LIS.
- Elementos que estan en todos los LIS:
  Tomo los elementos que si pueden estar en el LIS y reviso en que 
  posicion se puso cada uno, si a[i] es el unico elemento ubicado en la
  posicion pos, quiere decir que esta en todos los LIS.
- Longest Non-Decreasing Subsequence:
  el tamaño del mayor array a donde para cada i < j, a[i] <= a[j],
  solo hay que revisar la inecuacion de la busqueda binaria.
- Longest Decreasing Subsequence (LDS):
  es quivalente a el LIS de un array invertido.
- Menor numero de Increasing Subsequences:
  es equivalente al tamaño de la Longest Non-Increasing Subsequence.
  Es decir, el mayor tamaño de array a, donde para cada 
  i < j, a[i] >= a[j].
- Mayor subsecuencia de numeros consecutivos: 
  se puede usar un enfoque con sets o mapas, en el que se guarde 
  cada valor en donde termina una subsecuencia consecutiva, y el
  tamaño de esta. Entonces cada que queramos agregar un valor x,
  buscamos si existe una subsecuencia que termine en el x - 1,
  con longitud l, en caso de que si la eliminamos y agregamos una
  nueva subsecuencia que termina en x con longitud l + 1. Finalmente,
  recorremos todas las subsecuencias guardadas en el set o map y nos
  quedamos con la que tenga mayor longitud. Para reconstruir los 
  indices podemos encontrar la ultima ubicacion del numero mayor x de 
  subsecuencia mas larga y recorrer hacia la izquierda buscando x-1,
  despues x-2, hasta llegar a x - l + 1.
*/
/*
Con Segmet Tree (compresion):
- Para hallar el LIS usando Segment Tree, decimos que 
  t[a[i]] = max(t[0], t[1], ..., t[a[i] - 1]) + 1
  Esta definicion quiere decir que el LIS que puedo obtener finalizando en el 
  valor a[i] es igual a 1 mas el mayor de los LIS para j < i && a[j] < a[i]
  Para hallar el valor mayor usamos Segment Tree.
- Cantidad total de Increasing Subsequence's:
  tenemos que modificar este enfoque haciendo que el Segment Tree no nos de el 
  maximo en un rango si no la suma en un rango. Asi cada elemento t[i] 
  representa la cantidad de LIS que terminan en a[i].
*/

const int inf = 1e9 + 1;

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<int> d(n+1, inf); d[0] = -inf;

    for(int i = 1; i <= n; i++){
        auto it = ub(d.begin(), d.end(), a[i]);
        if(it == d.end()) continue;

        int index = distance(d.begin(), it);
        // Este if se encarga de no poner numeros iguales
        // Si me piden que cada numero sea estrictamente mayor
        // Si piden mayor o igual se puede quitar
        if(a[i] > d[index - 1]) d[index] = a[i]; 
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] < inf) ans = i;
    }

    cout<<ans<<endl;
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