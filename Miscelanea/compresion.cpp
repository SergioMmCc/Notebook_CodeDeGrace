#include "../template.h"
typedef pair<pii, int> piii;
typedef vector<piii> viii;

// O(n*lg(n))

// Comprimir array
void compressArr(vi& a){
    vi comp = a;
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    for0(i,sz(a)) a[i] = lb(all(comp), a[i]) - comp.begin();
    
    /* En caso de requerir hallar la compresion de algun 
    valor k, sin que se necesite guardar en el array:
    k = lb(all(comp), k) - comp.begin();
    Usar lb o ub segun sea el caso.*/
}

// Comprimir queries para segtree
void compressQ(viii& a){
    vi comp;
    for0(i,sz(a)){
        comp.pb(a[i].fi.fi);
        comp.pb(a[i].fi.se);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    for0(i,sz(a)){
        a[i].fi.fi = lb(all(comp), a[i].fi.fi) - comp.begin();
        a[i].fi.se = lb(all(comp), a[i].fi.se) - comp.begin();
    }
}