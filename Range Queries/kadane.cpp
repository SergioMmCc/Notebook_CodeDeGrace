#include "../template.h"

// Calcula el valor del subsegmento con mayor suma para un array a con numeros positivos y negativos 
// Complejidad: O(n)
int kadane(vl& a){
    int n = sz(a);
    ll cur = 0, best = -INF;
    for0(i,n){
        cur = max(a[i], cur + a[i]); // cur guarda el valor mayor de un subsegmento terminado en i
        best = max(best, cur); // Actualiza el resultado
    }

    return best;
}

// Se calcula el valor del subsegmento con mayor suma para cada subsegmento [l, r] existente
// Complejidad: O(n^2), debido a que hay n*(n+1) / 2 subsegmentos
void kadaneAll(vl& a, vector<vl>& ans){
    int n = sz(a);
    for0(l,n){ // Calculo para los subsegmentos iniciados en l
        ll cur = 0, best = -INF;
        for(int r = l; r < n; r++){
            cur = max(a[r], cur + a[r]); // cur guarda el valor del mayor subsegmento terminado en r
            best = max(best, cur); // Actualiza el resultado
            ans[l][r] = best;
        }
    }
}