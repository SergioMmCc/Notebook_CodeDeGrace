#include "../template.h"

// Halla phi(n), la cantidad de numeros entre 1 y n que son coprimos con n
// Complejidad: O(sqrt(n))
int phi(int n){
    int ans = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            ans -= ans / i;
        }
    }
    if(n > 1) ans -= ans / n;
    return ans;
}

// Halla phi(n) para todos los numeros entre 1 y n
// Complejidad: O(n * log(log(n)))
void phi_1_to_n(int n){
    vi phi(n + 1);
    for0(i,n+1) phi[i] = i;

    forlr(i,2,n){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}