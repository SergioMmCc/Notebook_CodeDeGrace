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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

// Implementacion con array 0-index
/*
    - Esta implementacion es de suma, sin embargo, tambien podemos calcular 
      multiplicaciones (incluyendo multiplicacion modular y multiplicacion de 
      matrices), operaciones bitwise como and (&), or (|) y xor (^), gcd y cualquier 
      operacion que cumpla con la propiedad asociativa.
    - Se pueden contar minimos/maximos utilizando un par que guarde minimo, cantidad 
      de apariciones.
*/ 

class segTree {
private:
    int size;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;

    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }

    void update(int pos, ll val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = val;
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    ll calc(int l, int r, int v, int tl, int tr){
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        ll m1 = calc(l, r, 2*v + 1, tl, tm);
        ll m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vector<ll>& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = a[tl];
           return;
        }
        int tm = (tr + tl) / 2;
        build(a, 2*v + 1, tl, tm);
        build(a, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size, 0LL);
        // build(0, 0, size);
    }

    void update(int pos, ll val){
        update(pos, val, 0, 0, size);
    }

    ll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    segTree st;
    st.init(n);
    st.build(a);

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int i; ll v; cin>>i>>v;
            st.update(i, v);
        }
        else{
            int l, r; cin>>l>>r;
            cout<<st.calc(l, r)<<endl;
        }
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