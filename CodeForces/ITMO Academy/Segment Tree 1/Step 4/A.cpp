#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const int maxn = 1e5 + 1;

// Implementacion con array 0-index
// Todas las operaciones se hacen inicialmente con v = 1, tl = 0, tr = n - 1
/*
    - Tambien podemos calcular multiplicaciones (incluyendo multiplicacion modular y
      multiplicacion de matrices), operaciones bitwise como and (&), or (|) y xor (^),
      gcd y cualquier operacion que cumpla con la propiedad asociativa
    - Si me piden sumar val en un rango [l, r] y perguntar por el valor de un elemento 
      en especifico, para update sumo val en l, resto val en r + 1, para query pregunto
      la suma [0, i].
*/ 
vector<ll> tree(4*maxn);

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) tree[v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
}

// Las queries son [l, r]
ll query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return tree[v];

    int tm = (tl + tr) / 2;
    return query(2*v, tl, tm, l, min(tm, r))
         + query(2*v + 1, tm + 1, tr, max(tm + 1, l), r);
}

void update(int v, int tl, int tr, int pos, ll val){
    if(tl == tr) tree[v] = val;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2*v, tl, tm, pos, val);
        else update(2*v + 1, tm + 1, tr, pos, val);
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
}

void solver(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i % 2) a[i] *= -1;
    }

    build(a, 1, 0, n-1);
    
    int m; cin>>m;
    while(m--){
        int op; cin>>op;
        if(!op){
            int i, v; cin>>i>>v; i--;
            if(i % 2) v *= -1;
            update(1, 0, n-1, i, v);
        }
        else{
            int l, r; cin>>l>>r; l--; r--;
            ll ans = query(1, 0, n-1, l, r);
            if(l % 2) ans *= -1;
            cout<<ans<<endl;
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