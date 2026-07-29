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