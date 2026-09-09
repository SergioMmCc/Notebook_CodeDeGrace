#include "../template.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Complejidad O(n ^ 2).
// binom[i][j] = (i!) / (j! * (i - j)!)
// Usar si N es pequeño y, el modulo no es primo (no se puede dividir) 
// o no hay modulo y se debe hacer con sumas para no tener overflow.
const int N = 501;
const ll mod = 1e9 + 7;
ll binom[N][N];

void calcBinom(){
    for0(i,N) binom[i][0] = binom[i][i] = 1;
    for1(i,N-1){
        for1(j,i-1){
            binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % mod;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Si el modulo es primo, se puede obtener en O(n + logk).
// Primero se precalcula el factorial hasta maxn
ll calculateBinomial(int n, int k){
    if(k < 0 || k > n) return 0;
    ll numerator = fact[n];
    ll denominador = (fact[k]*fact[n-k]) % mod;

    // Apply when mod is prime, if mod is not necesary, just divide those numbers normaly
    return (numerator * binpow(denominador, mod-2)) % mod; // Binary exponancion for eficiencia
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
Coeficiente binomial modulo mod = p ^ b, siendo p un numero primo:
- Si p > max(k, n-k) se puede usar el metodo de siempre.
- De lo contrario, k! y/o (n-k)! no son coprimos con m asi que no se puede usar el inverso modular.
- Para cada x! se computa el mayor exponente c(x) tal que p ^ c(x) es divisor de x!, y se halla
  g(x) = x! / (p ^ c(x)). g(x) es x! sin factores de p, modulo mod.
- Ahora (n) = (g(n) / (g(k)*g(n-k))) * (p ^ (c(n) - c(k) - c(n-k)))
        (k)
  Con esto se asegura que g(x) es coprimo con mod, por lo tanto se puede usar el inverso modular.
- Si c(n) - c(k) - c(n-k) >= b, entonces el coeficiente binomial es 0, ya que es multiplo de m.
- La complejidad es O(maxn) del precalculo de g y c, mas O(log(n)) por cada query.
*/
void precompute(int n, ll p, ll b, ll mod, vl& g, vl& c){
    g[0] = 1 % mod;
    for1(x,n){
        ll cur = x, cnt = 0;
        while(cur % p == 0){
            cur /= p;
            cnt++;
        }
        c[x] = c[x - 1] + cnt;
        g[x] = g[x - 1] * (cur % mod) % mod;
    }
}

ll binomial(int n, int k, ll p, ll b, ll mod, ll phimod, vl& g, vl& c){
    if(k < 0 || k > n) return 0;
    ll exp_p = c[n] - c[k] - c[n - k];
    if(exp_p >= b) return 0;
    ll res = g[n] % mod;
    res = (res * binpow(g[k], phimod - 1, mod)) % mod;
    res = (res * binpow(g[n-k], phimod - 1, mod)) % mod;
    res = res * binpow(p, exp_p, mod) % mod;
    return res;
}

void solver(){
    // Obtener p, b, mod y phi(mod)
    ll p, b; cin>>p>>b;
    ll mod = 1;
    for0(i,b) mod *= p;
    ll phimod = mod / p * (p-1);

    // Precalcular g y c
    int maxn = 1000; // límite superior de n
    vl g(maxn+1, 1), c(maxn+1);
    precompute(maxn, p, b, mod, g, c);

    // Hallar el coeficiente binomial
    int n, k; cin>>n>>k;
    cout<<binomial(n, k, p, b, mod, phimod, g, c);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Coeficiente binomial con un modulo mod arbitrario:
- Se halla la factorizacion prima: mod = p_1 ^ b_1 * p_2 ^ b_2 * ... * p_h ^ b_h.
- Se dice que mod_i = p_i ^ b_i.
- Para cada mod_i, se precalculan las funciones g_i y c_i igual que en el metodo anterior.
- Para hallar el coeficiente binomial (n k), por cada mod_i se halla
  r_i = binomial(n, k, p_i, b_i, mod_i, phi(mod_i), g_i, c_i).
- Se usa el Chinese Remainder Theorem para hallar ans = (n k) % mod, en el conjunto de ecuaciones:
  ans % mod_1 = r_1 % mod_1
  ans % mod_2 = r_2 % mod_2
  ...
  ans % mod_h = r_h % mod_h
*/

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Coeficiente binomial cuando n es muy grande y mod no tanto (mod tiene que ser primo):
- Complejidad: O(mod) del precalculo del factorial, mas O(log_mod(n)) por query.
- Se halla el factorial de cada numero hasta mod-1.
- Se tiene que:
  (n) % mod = (n_0) * (n_1) * ... * (n_e) % mod
  (k)         (k_0)   (k_1)         (k_e)
  Donde n = (n_e * mod ^ e) + (n_(e-1) * mod ^ (e-1)) + ... + (n_1 * mod) + n_0.
  y     k = (k_e * mod ^ e) + (k_(e-1) * mod ^ (e-1)) + ... + (k_1 * mod) + k_0.
- Si para cualquier i, k_i > n_i, el resultado del coeficiente binomial es 0.
*/
ll lucasBinomial(ll n, ll k){ // Coeficientes binomiales
    ll ans = 1;
    while(n > 0 || k > 0){
        ll ni = n % mod;
        ll ki = k % mod;
        if(ki > ni) return 0;
        ans *= (fact[ni] * mod_inverse((fact[ki] * fact[ni - ki]) % mod)) % mod;
        ans %= mod;
        n /= mod;
        k /= mod;
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Coeficiente binomial cuando n es muy grande y mod no tanto (mod tiene que ser square free, es decir,
en su descomposicion prima: mod = p_1 ^ e_1 * p_2 ^ e_2 * ... * p_h ^ e_h, cada e_i es igual a 1):
- Complejidad: O(m) del precalculo de factoriales, mas O(h*log(n)) para cada query.
- Para cada p_i se debe precalcular el factorial hasta p_i - 1.
- r_i = lucasBinomial(n, k) % p_i.
- Se usa el Chinese Remainder Theorem para hallar ans en las ecuaciones: ans % p_i = r_i % p_i.
- Tener cuidado con los llamados a las funciones, usar el mod adecuado.
*/