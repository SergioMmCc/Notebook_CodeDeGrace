// Algunas notas:
// - Usar Hashing en codeforces puede ser peligroso debido al hacking
// - La probabilidad de que 2 cadenas tengan el mismo hashing es de n / m
//   siendo n la longitud de la cadena mas larga
// - Si tengo un conjunto de hashes de k cadenas con longitud de maximo n,
//   la probabilidad de que 2 cadenas tengan igual hash es de (k^2 * n) / m
//   Por ende, si k y n son de alrededor de 1e5 y m alrededor de 1e9, es 
//   casi seguro que habra colisiones. Una forma de solucionarlo puede ser 
//   un primo m mas largo, como 2^61 - 1 y usar enteros de 128 bits para las
//   multiplicaciones, aunque ahora el hashing y las queries serian un poco
//   mas lentas.

// Halla el hashing de una cadena en 0(n)
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
    ll m = 1000000009;
    if(!l) return h[r];
    return (h[r] - ((h[l-1] * ph[r-l+1]) % m) + m) % m;
}