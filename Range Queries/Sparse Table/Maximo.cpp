#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const int lgn = 17; //Piso del Lg2 de MAXN (maximo numero de elementos)
const ll maxn = 2e5 + 2;
typedef pair<ll, int> pli;

/* 
    Complejidad:
    - Queries O(1)
    - Creacion O(n * lg(n))
*/
/*  
    - Si bien en este ejemplo se usa 1-index, el algoritmo es valido
      para 0-index, simplemente se deben cambiar los limites de
      i dentro del for(i = 1; i <= n; i++) por for(i = 0; i < n; i++)
      tanto en la lectura de los datos como en el llenado de la sparse
      table.
    - En esta implementacion tambien se calcula el indice en el cual se encuentra
      el elemento mas peuqeño, se puede eliminar simplemente dejando el primer elemento
      del par
    - Para valor minimo simplemente cambiar los max por min
*/

vector<ll> a(maxn);
pli rmq[maxn][lgn + 1];

void solver(){
    int n;cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        rmq[i][0] = {a[i], i}; //Inicializar sparse table
    }
    
    //Llenar sparse table
    for(int j = 1; j <= lgn; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }

    //Queries
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        int lg = 31 - __builtin_clz(r - l + 1); // Piso del Log2 del tamaño del rango
        pli maxi = max(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]); // [l, r]
        cout<<"El mayor numero entre "<<l<<" y "<<r<<" es: "<<maxi.first<<", y se encuentra en la posicion: "<<maxi.second<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}