#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int len = 51; // Para calcular hasta el n-esimo termino
vl fibo(len);

// Calcula Fibonacci. Tomando fibo[0] = 0, fibo[1] = 1
// Complejidad: O(n)
void calcFibo(){
    fibo[1] = 1;
    for(int i = 2; i < len; i++) fibo[i] = fibo[i-2] + fibo[i-1];
}

/* 
  - Calcula el codigo de fibonacci de un numero n.
  - Todo numero natural n puede ser representado como una secuencia unica
    de numeros de Fibonacci tal que no hay 2 numeros consecutivo iguales.
  - El algoritmo itera cada numero de fibonacci f[i] con i desde len hasta
    2, revisa si este es menor o igual a n, en caso de que si asigna 1 en 
    la posicion i-2 del codigo y resta el valor a n, y en caso de que no 
    asigna 0 en la posicion i-2.
*/
// Complejidad: aproximadamente O(log(n))
vb fiboCode(ll n){
    vb code(len - 1);
    for(int i = len - 1; i > 1; i--){
        if(n >= fibo[i]){
            code[i-2] = 1;
            n -= fibo[i];
        }
    }

    return code;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    calcFibo();

    // Mostrar el codigo de fibonacci de los numeros desde 0 hasta 10
    for(int i = 0; i <= 10; i++){
        vb code = fiboCode(i);
        for(int i = 0; i <= 11; i++) cout<<code[i];
        cout<<endl;
    }

    return 0;
}