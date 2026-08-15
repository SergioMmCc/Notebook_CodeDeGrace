#include "../template.h"

/*
- 0-index
- Complejidad: build O(n), update O(1), calc O(sqrt(n))
- Ajustar el tamaño del bloque a conveniencia
- La complejidad de update depende de la complejidad de reversar el calculo
- Ejemplo con suma en rango
*/

struct sqrtDecomp{
    int n, blen;
    vl a, b;
    sqrtDecomp(){}
    sqrtDecomp(vl& arr): n(sz(arr)), blen(sqrt(n)+1), a(arr), b(blen){
        for0(i,n) b[i/blen] += a[i];
    }

    void update(int pos, ll val){
        b[pos/blen] += val - a[pos];
        a[pos] = val;
    }

    ll calc(int l, int r){ // [l, r]
        ll sum = 0;
        int bl = l/blen, br = r/blen;
        if(bl == br) forlr(i,l,r) sum += a[i]; // Si l y r estan en el mismo bloque
        else{
            forlr(i, l, blen*(bl+1)-1) sum += a[i]; // Indices en el bloque izquierdo
            forlr(i, blen*br, r) sum += a[i]; // Indices en el bloque derecho
            forlr(i, bl+1, br-1) sum += b[i]; // Bloques centrales
        }
        return sum;
    }
};

void solver(){
    int n; cin>>n;
    vl a(n);
    for0(i,n) cin>>a[i];

    // Inicializar
    sqrtDecomp sq(a);

    // Update
    int pos; ll val; cin>>pos>>val;
    sq.update(pos, val);

    // Calc
    int l, r; cin>>l>>r;
    cout<<sq.calc(l, r)<<endl;
}