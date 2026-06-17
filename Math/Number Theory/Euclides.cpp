// O(log(n)), siendo n el minimo entre a y b
// En versiones recientes de C++ ya estan de forma nativa, en otras 
// mas antiguas se puede llamar usando __gcd o __lcm
ll gcd(ll a, ll b){
    ll temp;
    while(b != 0){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b)) * b;
}