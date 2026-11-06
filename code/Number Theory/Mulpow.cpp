#include "../template.h"

// Util si se requiere modularidad pero el modulo es muy grande
// como para multiplicar directamente.
// O(log(n))

const ll mod = (ll)1e18 + 3;

ll binmul(ll b, ll e){
    ll ans = 0;
    b %= mod; e %= mod;
    while(e){
        if(e & 1) ans = (ans + b) % mod;
        b = (b + b) % mod;
        e >>= 1;
    }
    return ans;
}