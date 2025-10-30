// - Si nos dan un arbol rooteado y tenemos que hacer queries de algun tipo sobre
//   algunos sub arboles (como sumar los valores de cada elemento de algun subarbol)
//   y tenemos que hacer updates sobre los valores de los nodos, se puede construir
//   un array de modo que todos los elementos de cualquier subarbol seran continuos
//   y se puede guardar cual es el rango de cada subarbol mediante un DFS. Una vez
//   se ha procesado todo esto y generado el nuevo array, se pueden realizar queries
//   y updates de cualquier tipo usando un segment tree.
// - Los rangos se guardaran ran[u] = [l, r)
// - Si no necesitamos hallar valores entre el subarbol de algun nodo sino en su 
//   camino hacia la raiz entonces hacemos updates en rango y querys individuales,
//   es decir, el valor de un nodo se le suma a todo su correspondiente subarbol, y
//   para hacer una query entre el camino de un nodo hacia la raiz, se hace la query
//   especificamente sobre el nodo que se pregunta (query individual).

const int maxn = 2e5 + 1;
vector<vector<int>> tree(maxn);

void DFS(vector<pii>& ran, int u, int pa, int &cnt){
    // Se dice que el rango de u inicia en cnt. Ademas ese sera su indice en el array que se contruira.
    ran[u].fi = cnt;
    cnt++; // Se suma 1 para guardar que se ha visitado un nuevo nodo
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS(ran, v, u, cnt); // Se visita el subarbol que tiene u como raiz
    }

    // Despues de visitar los nodos que pertenecen al subarbol de u, podemos decir en que indice termina el rango de u
    ran[u].se = cnt;
}