// Complejidad O(n ^ 2)
// binom[i][j] = (i!) / (j! * (i - j)!)

const int N = 501;
const ll mod = 1e9 + 7;
ll binom[N][N];

void calcBinom(){
    for(int i = 0; i < N; i++) binom[i][0] = binom[i][i] = 1;
    for(int i = 1; i < N; i++){
        for(int j = 1; j < i; j++){
            binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % mod;
        }
    }
}

// Si es la complejidad de un unico numero, entonces se puede obtener en O(nlogk)
const int limite=1e6;
vl factorial(limite+1);

void precalcular_factorial(){
    factorial[0] = 1;
    for(long long i=1; i<=limite; i++){
        factorial[i] = (factorial[i-1]*i) % MOD;
    }
}

int calculateBinomial(int n, int k){
    if(k < 0 || k > n) return 0;
    long long numerator = factorial[n];
    long long denominador = (factorial[k]*factorial[n-k]) % MOD;

    // Apply when MOD is prime, if mod is not necesary, just divide those numbers normaly
    return (numerator*binexp(denominador, MOD-2)) % MOD; // Binary exponancio for eficiencia
    
}
