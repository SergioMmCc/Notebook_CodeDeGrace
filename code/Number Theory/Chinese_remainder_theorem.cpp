#include "../template.h"
using i128 = __int128_t;

/*
- Sirve para hallar x para un grupo de ecuaciones de la forma:
  x % m_1 = a_1 % m_1
  x % m_2 = a_2 % m_2
  ...
  x % m_n = a_n % m_n
  Donde para cada par i, j donde i != j, m_i, m_j es coprimo.
- Una vez se halla una solucion se pueden crear infinitas de la forma
  x + k*M, donde M es m_1 * m_2 * ... * m_n, y k es un entero cualquiera.
- Complejidad: O(n*log(n)).
*/

ll mulmod(ll a, ll b, ll mod){
    return (i128)a * b % mod;
}


ll chinese_reminder(int n, ll M, vl& a, vl& m){
    ll x = 0;
    // vl d(n), c(n);
    for0(i,n){
        ll d = M / m[i];
        x += mulmod(a[i], (mulmod(d, mod_inverse(d, m[i]), M)), M);
        x %= M;
        // En caso de ser necesarios los vectores d y c
        // d[i] = M/m[i];
        // c[i] = (d[i] * mod_inverse(d[i], m[i])) % M;
        // x = (x + mulmod(a[i], c[i], M)) % M;
    }
    
    return x % M;
}

void solver(){
    int n; cin>>n;
    vl a(n), m(n);
    ll M = 1;
    for0(i,n){
        cin>>a[i]>>m[i];
        M *= m[i];
    }
    
    ll x = chinese_reminder(n, M, a, m);
    cout<<x<<endl;
}