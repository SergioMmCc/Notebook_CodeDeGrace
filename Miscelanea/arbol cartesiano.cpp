// Teniendo un array a de numeros distintos, armar su arbol 
// cartesiano, es decir, un arbol donde la raiz es el mayor 
// elemento y para cada nodo, sus 2 hijos son menores. El hijo 
// izquierdo es un nodo menor que se encuentra a la izquierda 
// en el array y el hijo derecho es un nodo menor que se 
// encuentra a la derecha en el array.
// Proceso:
// - Crear una pila
// - Recorrer el array en orden i -> [1, n]
// - Sacar de la pila todos los elementos menores a a[i]
// - El ultimo elemento que se saca es el hijo izquierdo de a[i]
// - Si la pila no esta vacia, a[i] es el hijo derecho del tope
// - Se inserta a[i] en la pila
// Complejidad: O(n)
// Notas:
// - Si en vez de arbol donde cada hijo es menor, se quiere uno
//   donde cada hijo sea mayor, en lugar de sacar de la pila todos
//   los elementos menores que a[i] en la pila, se sacan todos los
//   mayores.
// - Si los elementos de a son muy grandes, comprimir.

void cartesianTree(int n, vi& a, vi& sl, vi& sr){
    stack<int> st;
    for(int i = 1; i <= n; i++){
        int last = -1; 
        while(!st.empty() && a[i] > st.top()){
            last = st.top();
            st.pop();
        }

        if(last != -1) sl[a[i]] = last;
        if(!st.empty()) sr[st.top()] = a[i];

        st.push(a[i]);
    }
}
