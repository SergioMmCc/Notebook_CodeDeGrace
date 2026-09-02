#include "../template.h"

// O(log(e))
// Calcula (b ^ e) % mod
ll binpow(ll b, ll e){
    b %= mod;
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return ans;
}