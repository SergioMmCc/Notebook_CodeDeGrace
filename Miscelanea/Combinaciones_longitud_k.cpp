#include "../template.h"

/*
- Dado un conjunto de n elementos (ordenados y sin repeticiones), se quieren 
  generar sus combinaciones de tamaño k, en orden ascendente.
- La primera combinacion esta compuesta por los elementos [0, k)
- A partir de ahi, se llama next_combination, la cual da la siguiente combinacion y
  retorna True si la hay, o False en caso de que ya se haya llegado a la ultima.
- Complejiadad: O(k) para hallar la siguiente combinacion, O(k * binom{n, k}) para
  hallarlas todas.
*/

bool next_combination(vi& a, int n){
    int k = sz(a);
    forn0(i,k){
        if(a[i] < n - k + i + 1){
            a[i]++;
            forlr(j, i+1, k-1) a[j] = a[j - 1] + 1;
            return 1;
        }
    }
    return 0;
}