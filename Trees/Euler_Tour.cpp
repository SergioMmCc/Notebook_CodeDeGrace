#include "../template.h"

/*
- Compeljidad: O(n+m)
- Implementacion 1-index
- La posicion de cada nodo i en el arbol aplanado es ran[i].fi
- Llamar con DFS(ran, root, -1, cnt(inicializado en 1))
- Los rangos se guardaran ran[u] = [l, r]

- Si nos dan un arbol rooteado y tenemos que hacer queries de algun tipo sobre
  algunos subarboles (como sumar los valores de cada elemento de algun subarbol)
  y tenemos que hacer updates sobre los valores de los nodos, se puede construir
  un array de modo que todos los elementos de cualquier subarbol seran continuos
  y se puede guardar cual es el rango de cada subarbol mediante un DFS. Una vez
  se ha procesado todo esto y generado el nuevo array, se pueden realizar queries
  y updates de cualquier tipo usando un segment tree.
- Si no necesitamos hallar valores entre el subarbol de algun nodo sino en su 
  camino hacia la raiz entonces hacemos updates en rango y queries individuales,
  es decir, el valor de un nodo se le actualiza a todo su correspondiente subarbol, 
  y para hacer una query entre el camino de un nodo hacia la raiz, se hace la query
  especificamente sobre el nodo que se pregunta (query individual).
*/

const int maxn = 2e5 + 1;
vector<vi> tree(maxn);

void DFS(vii& ran, int u, int pa, int &cnt){
    // El rango de u inicia en cnt. Ademas ese sera su indice en el array que se construira.
    ran[u].fi = cnt;
    cnt++; // Se suma 1 para guardar que se ha visitado un nuevo nodo
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS(ran, v, u, cnt);
    }

    // Despues de visitar los nodos del subarbol de u, decimos en que indice termina el rango de u
    ran[u].se = cnt - 1;
}

void solver(){
    // Llamar el DFS para hallar los rangos de cada subarbol
    vii ran(n+1);
    int cnt = 1;
    DFS(ran, 1, -1, cnt);

    // Arbol aplanado
    vi orden(n+1);
    for1(i,n) orden[ran[i].fi] = i; // El vertice i se encuentra en la posicion ran[i].fi
}