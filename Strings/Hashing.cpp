// Halla el hashing de una cadena en 0(n)
// La probabilidad de fallar es q / B, siendo q el numero de comparaciones
ll compute_hash(string s){
    ll p = 31; // Si s se compone de lowercase english letters
    // ll p = 53; // Si s se compone de lowercase y uppercase english letters
    ll p_pow = 1; // Si precalculo las potencias de p podria ser ligeramente mas eficiente
    ll m = 1e9 + 9;
    ll ans = 0;

    for(char c : s){
        ans = (ans + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m; 
    }

    return ans;
}

// Sirve para hacer precalculos para hacer queries de la subcadena
// sl, sl+1, ..., sr
// Construir el array toma O(n), las queires son O(1)
void precalc_hashing(string s, vector<ll>& h, vector<ll>& ph){
    ll p = 31;
    ll m = 1e9 + 9;

    h[0] = s[0] - 'a' + 1;
    ph[0] = 1;

    for(int i = 1; i < s.sz; i++){
        h[i] = (((h[i-1] * p) % m) + (s[i] - 'a' + 1)) % m;
        ph[i] = (ph[i-1] * p) % m;
    }

    /* 
        Para hacer queries:
        - Si l = 0: h[r]
        - Si no: (h[r] - h[l-1] * ph[r-l+1]) % m
    */
}

ll queries(ll l, ll r, vector<ll>& h, vector<ll>& ph){
    if(!l) return h[r];
    return (h[r] - h[l-1] * ph[r-l+1]) % (1000000009LL); // Si cambio el valor del modulo, tambien cambiarlo aca
}