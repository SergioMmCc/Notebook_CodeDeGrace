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
typedef pair<pii, ll> piil;

const int maxn = 4e5 + 1;

// Implementacion con array 0-index
// Todas las operaciones se hacen inicialmente con v = 1, tl = 0, tr = n - 1
/*
    Tambien podemos calcular multiplicaciones (incluyendo multiplicacion modular y
    multiplicacion de matrices), operaciones bitwise como and (&), or (|) y xor (^),
    gcd y cualquier operacion que cumpla con la propiedad asociativa
*/ 
vector<ll> tree(4*maxn);

// Las queries son [l, r]
ll query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return tree[v];

    int tm = (tl + tr) / 2;
    return max(query(2*v, tl, tm, l, min(tm, r)),
        query(2*v + 1, tm + 1, tr, max(tm + 1, l), r));
}

void update(int v, int tl, int tr, int pos, ll val){
    if(tl == tr) tree[v] = max(tree[v], val);
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2*v, tl, tm, pos, val);
        else update(2*v + 1, tm + 1, tr, pos, val);
        tree[v] = max(tree[2*v], tree[2*v + 1]);
    }
}

struct comparador{
    bool operator() (piil a, piil b){
        if(a.fi.se == b.fi.se) return a.fi.fi < b.fi.fi;
        return a.fi.se < b.fi.se;
    }
};

void solver(){
    int n; cin>>n;
    vector<piil> a(n);
    vector<int> points;
    for(int i = 0; i < n; i++){
        cin>>a[i].fi.fi>>a[i].fi.se>>a[i].se;
        points.pb(a[i].fi.fi);
        points.pb(a[i].fi.se);
    }

    sort(points.begin(), points.end());
    int next = 0;
    map<int, int> comp;
    for(int x : points){
        if(comp.find(x) == comp.end()){
            comp[x] = next;
            next++;
        }
    }

    for(int i = 0; i < n; i++){
        a[i].fi.fi = comp[a[i].fi.fi];
        a[i].fi.se = comp[a[i].fi.se];
    }

    sort(a.begin(), a.end(), comparador());
    
    for(int i = 0; i < n; i++){
        int l = a[i].fi.fi, r = a[i].fi.se;
        ll val = a[i].se;

        ll add = query(1, 0, next-1, 0, l-1);
        update(1, 0, next-1, r, val + add);
    }

    cout<<query(1, 0, next-1, 0, next-1);
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