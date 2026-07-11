// Encuentra todos los numeros primos entre 1 y n
// Complejidad: O(n * log(log(n)))
// Algoritmo: Criba de Eratóstenes.

// Se usa limite como n
// Hasta este numero hay un poco mas de 6e5 primos
// Fomula de cantidad de primos aproximado dado n -> n / log(n)
const int limite = 10001000;

vector<bool> esPrimo(limite + 1, 1);
vector<int> primos;

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p <= limite; p++){
        if(esPrimo[p]){
            primos.push_back(p);
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }
}

