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
    Tambien podemos calcular multiplicaciones (incluyendo multiplicacion modular y
    multiplicacion de matrices), operaciones bitwise como and (&), or (|) y xor (^),
    gcd y cualquier operacion que cumpla con la propiedad asociativa
*/ 
vector<int> tree(4*maxn);
const int inf = 1e9 + 1;
int n;

void build(int v, int tl, int tr){
    if(tl == tr) tree[v] = inf;
    else{
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v + 1, tm + 1, tr);
        tree[v] = min(tree[2*v], tree[2*v + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr) tree[v] = val;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2*v, tl, tm, pos, val);
        else update(2*v + 1, tm + 1, tr, pos, val);
        tree[v] = min(tree[2*v], tree[2*v + 1]);
    }
}

// Las queries son [l, r]
int query(int v, int tl, int tr, int l, int r, int p){
    if(l > r) return 0;
    if(tl == tr){
        if(tree[v] <= p){
            update(1, 0, n-1, tl, inf);
            return 1;
        }
        return 0;
    }

    int tm = (tl + tr) / 2;
    if(tree[v] > p) return 0;
    int ans = query(2*v, tl, tm, l, min(tm, r), p)
        + query(2*v + 1, tm + 1, tr, max(tm + 1, l), r, p);
    return ans;
}

void solver(){
    int m; cin>>n>>m;

    build(1, 0, n-1);

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int i, v; cin>>i>>v;
            update(1, 0, n-1, i, v);
        }
        else{
            int l, r, p; cin>>l>>r>>p;
            cout<<query(1, 0, n-1, l, r-1, p)<<endl;
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