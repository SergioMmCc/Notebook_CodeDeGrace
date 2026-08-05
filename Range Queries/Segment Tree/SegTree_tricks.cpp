/**************************************************************************
Nested segments:
Para contar la cantidad de segmentos contenidos en otro se pueden recorrer los
segmentos en order descendente de l y ascendente de r, se hace una querie de 
suma en su rango (ese valor es la cantidad de segmentos contenidos en este) y
finalmente se actualiza su valor con 1 en r.
***************************************************************************/

/***************************************************************************
Intersecting Segments:
Para hallar la cantidad de segmentos que se intersectan con otro, se recorren
los puntos del arreglo. Al llegar a un extremo l, se marca esta posicion en 1. 
Al llegar a un extremo r se marca la posicion en l con -1 y en r con 1 y se hace 
una querie de suma en (l, r) o [l, r] segun sea el caso, ese valor es la 
cantidad de segmentos que se intersectan con este. La suma total dividido 2 es 
la cantidad de intersecciones.
***************************************************************************/

/***************************************************************************
kth one:
En un array de 1s y 0s, hallar la kth posicion donde hay un 1. Sirve para ejercicios
donde me pidan activar y desactivar posiciones. Consultas sobre el array completo.
Tambien se puede usar un enfoque similar para hallar el kth elemento mayor o igual a x
(pero las queries deben ser sobre el array completo y no sobre rangos especificos, de
lo contrario usar persistente).
Usar operacion de sumas y: */
int calc(int l, int r, int k, int v, int tl, int tr){
    // propagate(v, tl, tr); // Si es lazy
    if(tl >= r || l >= tr) return -1; // Hay menos de k 1s
    if(tr - tl == 1) return tl;

    int tm = (tl + tr) / 2;
    if(tree[2*v + 1].val >= k) return calc(l, r, k, 2*v + 1, tl, tm);
    k -= tree[2*v + 1].val;
    return calc(l, r, k, 2*v + 2, tm, tr);
}
/***************************************************************************/

/***************************************************************************
- Primer elemento >= x:
  Hallar la primera posicion i >= l con a[i] >= x. Usar operacion de maximos y: */
int calc(int l, int r, ll x, int v, int tl, int tr){ // Change si walking on segment tree
    // propagate(v, tl, tr); // Si es lazy
    if(tl >= r || l >= tr) return -1; // No hay ninguno
    if(tr - tl == 1) return tree[v].val >= x ? tl : -1;

    int tm = (tl + tr) / 2;
    int ans = -1;
    if(tree[2*v + 1].val >= x) ans = calc(l, r, x, 2*v + 1, tl, tm);
    if(ans == -1 && tree[2*v + 2].val >= x) ans = calc(l, r, x, 2*v + 2, tm, tr);
    return ans;
}