// O(log(n))
// Calcula (b ^ e) % mod
ll binpow(ll b, ll e){
    ll result = 1;
    while(e > 0){
        if(e % 2 == 1)
            result = ((b % mod) * (result % mod)) % mod;
        b = ((b % mod) * (b % mod)) % mod;
        e /= 2;
    }
    return result;
}