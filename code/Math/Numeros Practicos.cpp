#include "../template.h"

/* 
- Halla si un numero 'n' es practico.
- Complejidad: O(sqrt(n)) pero en la practica suele ser mejor.
  (Se puede mejorar con pollard rho).
- Un numero practico es un entero positivo 'n' tal que todo numero
  entero entre '1' y 'n' puede escribirse como suma de distintos
  divisores de 'n'.
Propiedades:
- El unico impar que es numero practico es el 1.
- Todas las potencias de '2' son practicas.
- Todos los numeros perfectos pares son practicos.
- Todo practico mayor que '2' es divisible por '4' o por '6'.
- El producto de dos numeros practicos es practico.
*/

bool isPractical(ll n){
    if(n == 1) return 1;
    if(n & 1) return 0;

    ll sigma = 1;                       // σ de la parte ya procesada
    for(ll p = 2; p * p <= n && p <= sigma + 1; ++p){
        if(n % p) continue;
        ll pk = 1, term = 1;            // term = 1 + p + ... + p^a
        while(n % p == 0){
            n /= p;
            pk *= p;
            term += pk;
        }
        sigma *= term;
    }
    if(n > 1 && n > sigma + 1) return 0;
    return 1;
}

void solver(){
    ll n; cin>>n;
    cout<<(isPractical(n) ? "Yes" : "No")<<endl;
}
