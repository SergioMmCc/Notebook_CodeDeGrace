#include "../template.h"

/*
- Verificar rapidamente si un numero n es primo.
- Complejidad por cada check_composite: log(n).
*/

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpow(u64 b, u64 e, u64 m){
    b %= m;
    u64 ans = 1;
    while(e){
        if(e & 1) ans = ((u128)b * ans) % m;
        b = ((u128)b * b) % m;
        e >>= 1;
    }
    return ans;
}

bool check_composite(u64 n, u64 a, u64 d, int s){
    u64 x = binpow(a, d, n);
    if(x == 1 || x == n - 1) return 0;
    for1(r,s-1){
        x = ((u128)x * x) % n;
        if(x == n - 1) return 0;
    }
    return 1;
};

// Version optimizada
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if(n < 2) return 0;

    // Testear con los primeros primos para optimizar ya que el 88% de numeros son divisibles por al menos uno. 
    // Agregar mas no optimiza casi nada.
    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}){
        if(n == (u64)a) return 1;
        if(!(n % a)) return 0;
    }
    for(u64 a : {193, 407521, 299210837}) if(n == a) return 1; // Primos especiales que se testean aparte

    int r = 0;
    u64 d = n - 1;
    while((d & 1) == 0){
        d >>= 1;
        r++;
    }

    for(u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
        if(check_composite(n, a, d, r)) return 0;
    }
    return 1;
}

// Version un poco mas lenta.
// Si n es un entero de 32 bits, solo testear con 2, 3, 5 y 7.
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if(n < 2) return 0;

    int r = 0;
    u64 d = n - 1;
    while((d & 1) == 0){
        d >>= 1;
        r++;
    }

    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(n == a) return 1;
        if(check_composite(n, a, d, r)) return 0;
    }
    return 1;
}

void solver(){
    u64 n; cin>>n;
    cout<<(MillerRabin(n) ? "YES" : "NO")<<endl;
}