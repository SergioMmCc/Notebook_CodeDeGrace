#include "../template.h"

/*
- Dado n! y una base k, se quiere hallar el mayor x tal que k ^ x sea divisor de n!
- Se hallan todos los divisores primos de k y se llama a la funcion findExp. x es
  la menor respuesta entre todos los llamados.
- La complejidad de findExp es O(log_k(n)), asi que la complejidad total es eso por
  la cantidad de divisores primos de k, mas el tiempo que se tarde en hallar dichos
  divisores.
*/
int findExp(int n, int k){
    int ans = 0;
    while(n){
        n /= k;
        ans += n;
    }
    return ans;
}