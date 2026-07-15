// Fenwick tree (Binary Indexed Tree), variante "1-indexada":

// Que guarda cada nodo t[p]: la suma de un rango de posiciones
// determinado por los bits de p (no es simplemente "el valor en p").
// Por eso nunca se lee t[p] directamente, siempre a traves de get().
//
// Complejidad: O(log N) por update y por get.
// Soporta operaciones con cualquier operacion asociativa CON INVERSA
// (poder "deshacer" un update). Ejemplos: suma (inversa = resta), xor
// (inversa = si mismo), conteo (caso particular de suma).

// NO soporta min/max con updates arbitrarios (no tienen inversa) -
// para eso se necesita un segment tree.

template<int N> struct FenW {
    ll t[N + 1]; // indices validos: [1, N] (la posicion 0 no se usa)

    FenW() {
        fill(t + 1, t + N + 1, 0ll);
    }

    // Suma x en la posicion p (point update).
    void update(int p, ll x) {
        for (; p <= N; p += p & (-p)) {
            t[p] += x;
        }
    }
 
    // Suma acumulada de las posiciones [1, p] (prefix query).
    // get(0) = 0;
    ll get(int p) {
        ll ret = 0;
        for (; p > 0; p -= p & (-p)) {
            ret += t[p];
        }
        return ret;
    }

    // Suma acumulada de las posiciones [l, r] (range query).
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};


// How to use
int main(){
  // Puedes crearlo con un valor fijo, o variable constante
  FenW<10> A;
}
