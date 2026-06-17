// Complejidad: O(n * lg(n))
// Almacena en orden ascendente todos los divisores de los numeros del 1 al maxn
const int maxn = 2e5 + 2;

vector<int> divs[maxn];

void pre(){
    for(int i = 2; i < maxn; i++){
        for(int j = i; j < maxn; j += i) divs[j].pb(i);
    }
}