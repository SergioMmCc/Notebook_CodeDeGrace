#include "../template.h"

/* 
- 0-index.
- Para cualquier operacion asociativa e idempotente (oper(a,a) == a), 
  como min, max, and, or, gcd.
- Cuidado con el neutro.
- Complejidad: calc: 0(1), build(nlog(n))
*/

struct rmq {
    ll neutro = LLONG_MAX - 1; // Change
    int n, lgn;
    vector<vl> st;
    inline ll oper(ll a, ll b){ return a < b ? a : b; } // Change

    void build(const vl& a){
        n = sz(a);
        lgn = 32 - __builtin_clz(n); // floor(log2(n))
        st.assign(lgn, vl(n));
        st[0] = a;
        for1(j,lgn) 
            for(int i = 0; i + (1 << j) - 1 < n; i++) 
                st[j][i] = oper(st[j-1][i], st[j-1][i + (1 << (j-1))]);
    }

    ll calc(int l, int r){ // [l, r]
        if(l > r) return neutro;
        int j = 31 - __builtin_clz(r-l+1); // floor(log2(r-l+1))
        return oper(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

void solver(){
    int n; cin>>n;
    vl a(n);
    for0(i,n) cin>>a[i];

    // Inicializar
    rmq st; 
    st.build(a);

    // Calc
    int l, r; cin>>l>>r;
    cout<<st.calc(l, r)<<endl;
}