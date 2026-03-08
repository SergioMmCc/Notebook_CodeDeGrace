// Teniendo un array a, armar su arbol cartesiano, es decir, un 
// arbol donde la raiz es el mayor elemento y para cada nodo, sus 2 
// hijos son menores. El hijo izquierdo es un nodo menor que se 
// encuentra a la izquierda en el array y el hijo derecho es un nodo 
// menor que se encuentra a la derecha en el array.
// Proceso:
// - Crear una pila
// - Recorrer el array en orden i -> [1, n]
// - Sacar de la pila todos los elementos menores a a[i]
// - El ultimo elemento que se saca es el hijo izquierdo de i
// - Si la pila no esta vacia, i es el hijo derecho del tope
// - Se inserta i en la pila
// Complejidad: O(n)
// Notas:
// - Si en vez de arbol donde cada hijo es menor, se quiere uno
//   donde cada hijo sea mayor, en lugar de sacar de la pila todos
//   los elementos menores que a[i] en la pila, se sacan todos los
//   mayores.
// - En caso de que el array tenga numeros repetidos, la raiz del
//   arbol sera el indice de la primera ocurrencia del mayor 
//   elemento del array.

void cartesianTree(int n, vi& a, vi& sl, vi& sr){
    stack<int> st;
    for(int i = 0; i < n; i++){
        int last = -1; 
        while(!st.empty() && a[i] > a[st.top()]){
            last = st.top();
            st.pop();
        }

        if(last != -1) sl[i] = last;
        if(!st.empty()) sr[st.top()] = i;

        st.push(i);
    }
}
