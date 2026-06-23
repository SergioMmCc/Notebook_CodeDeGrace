// Halla phi(n), la cantidad de numeros entre 1 y n que son coprimos con n
// Complejidad: O(sqrt(n))
int phi(int n){
    int result = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

// Halla phi(n) para todos los numeros entre 1 y n
// Complejidad: O(n * log(log(n)))
void phi_1_to_n(int n){
    vi phi(n + 1);
    for(int i = 0; i <= n; i++)
        phi[i] = i;

    for(int i = 2; i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}