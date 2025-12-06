// Calcula el valor del subsegmento con mayor suma para un array a con numeros positivos y negativos 
// Complejidad: O(n)
int kadane(vector<ll>& a){
    int n = sz(a);
    ll cur = 0, best = -inf;
    for(int i = 0; i < n; i++){
        cur = max(a[i], cur + a[i]); // cur guarda el valor mayor de un subsegmento terminado en i
        best = max(best, cur); // Actualiza el resultado
    }

    return best;
}

// Se calcula el valor del subsegmento con mayor suma para cada subsegmento [l, r] existente
// Complejidad: O(n^2), debido a que hay n*(n+1) / 2 subsegmentos
void kadaneAll(vector<ll>& a, vector<vector<ll>>& ans){
    int n = sz(a);
    for(int l = 0; l < n; l++){ // Calculo para los subsegmentos iniciados en l
        ll cur = 0, best = -inf;
        for(int r = l; r < n; r++){
            cur = max(a[r], cur + a[r]); // cur guarda el valor del mayor subsegmento terminado en r
            best = max(best, cur); // Actualiza el resultado
            ans[l][r] = best;
        }
    }
}