#include "../template.h"

/* 
Complejidad:
- Queries O(1)
- Creacion O(n * lg(n))
*/
/*  
- Implemetacion 0-index.
- En esta implementacion tambien se calcula el indice en el cual se encuentra
  el elemento mas pequeño, se puede eliminar simplemente dejando el primer elemento
  del par.
*/

typedef pair<ll, int> pli;

// Llenar sparse table
void fillRMQ(vector<ll>& a, vector<vector<pli>>& rmq){ // O(nlg(n))
    int n = sz(a); rmq.resize(n);
    int lgn = 31 - __builtin_clz(n); // Piso del log2 de n

    for0(i,n){
        rmq[i].resize(lgn + 1);
        rmq[i][0] = {a[i], i};
    }

    for1(j,lgn){
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
}

// [l, r]
pli query(int l, int r, vector<vector<pli>>& rmq){ // O(1)
    int lg = 31 - __builtin_clz(r - l + 1); // Piso del Log2 del tamaño del rango
    return max(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]);
}

void solver(){
    int n; cin>>n;
    vl a(n);
    for0(i,n) cin>>a[i];

    // Inicializar
    vector<vector<pli>> rmq;
    fillRMQ(a, rmq);

    // Queries
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        pli maxi = query(l, r, rmq); // [l, r]
        cout<<"El mayor numero entre "<<l<<" y "<<r<<" es: "<<maxi.first<<", y se encuentra en la posicion: "<<maxi.second<<endl;
    }
}