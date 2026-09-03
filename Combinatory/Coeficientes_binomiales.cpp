#include "../template.h"

// Complejidad O(n ^ 2)
// binom[i][j] = (i!) / (j! * (i - j)!)
// Usar si el modulo no es primo o no hay modulo y se debe hacer con sumas para no tener overflow

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
//////////////////////////////////////////////////////////////////////////////
// Si el modulo es primo (o son numeros pequeños y no se requiere modulo), se puede obtener en O(n + logk)
const int limite=1e6;
vl factorial(limite+1);

void precalcular_factorial(){
    factorial[0] = 1;
    for1(i,limite){
        factorial[i] = (factorial[i-1]*(ll)i) % mod;
    }
}

ll calculateBinomial(int n, int k){
    if(k < 0 || k > n) return 0;
    ll numerator = factorial[n];
    ll denominador = (factorial[k]*factorial[n-k]) % mod;

    // Apply when mod is prime, if mod is not necesary, just divide those numbers normaly
    return (numerator * binpow(denominador, mod-2)) % mod; // Binary exponancion for eficiencia
}
