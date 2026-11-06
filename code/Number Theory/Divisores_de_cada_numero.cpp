#include "../template.h"

// Complejidad: O(n * lg(n))
// Almacena en orden ascendente todos los divisores de los numeros del 1 al maxn
const int maxn = 2e5 + 2;

vi divs[maxn];

void pre(){
    forlr(i,2,maxn-1){
        for(int j = i; j < maxn; j += i) divs[j].pb(i);
    }
}