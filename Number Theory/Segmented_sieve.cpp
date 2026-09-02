#include "../template.h"

// Halla los numeros primos en [L, R].
// isPrime[idx] dice si L + idx es primo
// Complejidad: O((R-L+1)*log(log(R)) + sqrt(R)*log(log(R))).
// Usar hasta R-L+1 aprox 1e7 y R aprox 1e12.

vb segmentedSieve(ll L, ll R){
    // generate all primes up to sqrt(R)
    ll lim = sqrt(R);
    vb mark(lim + 1);
    vl primes;
    for(ll i = 2; i <= lim; ++i){
        if(!mark[i]){
            primes.emplace_back(i);
            for(ll j = i * i; j <= lim; j += i)
                mark[j] = 1;
        }
    }

    vb isPrime(R - L + 1, 1);
    for(ll i : primes)
        for(ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = 0;
    if(L == 1) isPrime[0] = 0;
    return isPrime;
}