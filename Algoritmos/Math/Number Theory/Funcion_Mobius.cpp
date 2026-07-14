// La función de Möbius (mu) es una función fundamental en teoría de números.
// Se usa mucho en problemas de inclusión-exclusión sobre divisores o primos
// (por ejemplo, para contar pares coprimos, sumas sobre gcd, etc).
//
// Se define según la factorización en primos de x:
/*
        |  1,      si x = 1
u(x) =  |  0,      si x tiene algun factor primo al cuadrado (no es squarefree)
        |  (-1)^k, si x es squarefree y tiene k factores primos distintos
*/
// sieve_mobius calcula mu[x] para todo x en [1, limite] en O(n log log n)
// usando una criba de Eratóstenes modificada:
// - Por cada primo p, multiplica por -1 el mobius de todos sus múltiplos
//   (equivale a agregar un factor primo distinto).
// - Luego anula (pone en 0) el mobius de los múltiplos de p^2,
//   ya que esos x dejan de ser squarefree.

const int limite = 1E6;

vi mobius(limite + 1, 1);
vb esPrimo(limite + 1, 1);

void sieve_mobius(){
    mobius[1] = 1;
    for(ll p = 2; p <= limite; p++){
        if(esPrimo[p]){
            mobius[p] = -1;
            for(ll j = 2*p; j<= limite; j+=p){
                esPrimo[j] = 0;
                mobius[j] *= -1;
            }


            ll p2 = p * p;
            for(ll j = p2; j <= limite; j+=p2){
                mobius[j] = 0;
            }
        }
    }
}



// Una forma alternativa es usando la propiedad de inclusion-exclusion
// Note que el array esta vez tiene que inicializarse en 0
vi mobius(limite + 1, 0);

void inclusion_mobius(){
    mobius[1] = -1;
    for (int i = 1; i < limite; i++) {
        if (mobius[i]) {
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j < limite; j += i) { mobius[j] += mobius[i]; }
        }
    }
}
