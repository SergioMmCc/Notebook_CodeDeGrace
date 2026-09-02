#include "../template.h"

/*
- Halla la factorizacion prima de n.
- Complejidad: O(n^(1/4) * log(n)).
- Para numeros grandes es mas eficiente que el algoritmo clasico en sqrt(n).
  Para numeros pequeños si es mejor usar el otro.
*/

using i128 = __int128_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll mult(ll a, ll b, ll mod){ return ((i128)a * b) % mod; }
ll f(ll x, ll c, ll mod){ return (mult(x, x, mod) + c) % mod; }

ll rho(ll n){
    ll x = rng() % n;
    ll c = (rng() % (n-1)) + 1;
    ll g = 1;
    ll q = 1;
    ll xs, y;

    int m = 128;
    int l = 1;
    while(g == 1){
        y = x;
        for(int i = 1; i < l; i++) x = f(x, c, n);
        int k = 0;
        while(k < l && g == 1){
            xs = x;
            for(int i = 0; i < m && i < l - k; i++){
                x = f(x, c, n);
                q = mult(q, abs(y - x), n);
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if(g == n){
        do{
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g == n ? rho(n) : g;
}

void factorize(ll n, map<ll, int>& fact){
    if(n == 1) return;
    if(MillerRabin(n)){ // Primero testear si es primo
        fact[n]++;
        return;
    }
    ll g = rho(n);
    factorize(g, fact); factorize(n/g, fact);
}

void solver(){
    ll n; cin>>n; // Se puede optimizar testeando antes los primeros primos (aprox hasta 1000)
    map<ll, int> fact;
    factorize(n, fact); // Se guarda en fact la factorizacion prima de n
}