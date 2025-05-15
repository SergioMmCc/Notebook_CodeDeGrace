#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int limite = 10001000; // Hasta este numero hay un poco mas de 6e5 primos

vector<bool> esPrimo(limite + 1, 1);

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }
}

int main() {
    sieve();
    
    return 0;
}
