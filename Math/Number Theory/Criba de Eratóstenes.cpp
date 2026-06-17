// Encuentra todos los numeros primos entre 1 y n
// Complejidad: O(n * log(log(n)))

// Se usa limite como n
// Hasta este numero hay un poco mas de 6e5 primos
const int limite = 10001000;

vb esPrimo(limite + 1, 1);
vi primos;


void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(int i = 2; i < limite; i++)
        if(esPrimo[i]) primos.pb(i); 
}

