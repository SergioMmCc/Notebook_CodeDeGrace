#include "../template.h"

/////////////////////////////////////////////
// Precálculo de Factorial e Inverso de Factorial módulo MOD
//
// Complejidad temporal:
//   - Precálculo: O(N + log(MOD)) gracias a la propagación hacia atrás:
//     invFact[i] = (invFact[i + 1] * (i + 1)) % MOD
//   - Consultas (nCr, nPr): O(1)
// Complejidad espacial: O(N)
//
// NOTA: MOD debe ser un número primo para usar el Pequeño Teorema de Fermat:
//       a^(MOD - 2) ≡ a^(-1) (mod MOD)
/////////////////////////////////////////////////

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll fact[MAXN];
ll invFact[MAXN];

// Exponenciación binaria: O(log(e))
ll binpow(ll b, ll e, ll m = MOD) {
    b %= m;
    ll ans = 1;
    while (e > 0) {
        if (e & 1) ans = (ans * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return ans;
}

// Inverso modular usando el Pequeño Teorema de Fermat (MOD primo)
ll mod_inv(ll a, ll m = MOD) {
    return binpow(a, m - 2, m);
}

// Precálculo de factoriales e inversos de factoriales hasta n
void precomputeFactorials(int n, ll mod = MOD) {
    fact[0] = 1;
    for1(i, n) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    // Se calcula el inverso del factorial de n en O(log MOD)
    invFact[n] = mod_inv(fact[n], mod);

    // Se calculan los inversos de factorial hacia atrás en O(1) cada uno
    // (i!)^(-1) = ((i + 1)!)^(-1) * (i + 1) % MOD
    forn0(i, n) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

// Inverso modular de un número x (1 <= x <= n) en O(1)
ll get_inv(int x, ll mod = MOD) {
    if (x <= 0) return 0;
    return (invFact[x] * fact[x - 1]) % mod;
}
