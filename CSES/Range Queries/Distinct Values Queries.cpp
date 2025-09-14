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
typedef pair<pii, int> piii;

const int maxn = 2e5 + 1;

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
    int n, q; cin>>n>>q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<piii> queries(q);
    for(int i = 0; i < q; i++){
        int l, r; cin>>l>>r; l--; r--;
        queries[i] = {{l, r}, i};
    }
    sort(queries.begin(), queries.end());

    vector<int> ans(q);
    map<int, int> last;

    int j = n;
    for(int i = q - 1; i >= 0; i--){
        int l = queries[i].fi.fi, r = queries[i].fi.se, idx = queries[i].se;
        while(j > l){
            j--;
            int num = a[j];
            if(last.find(num) != last.end()){
                int del = last[num];
                update(1, 0, n-1, del, 0);
            }
            last[num] = j;
            update(1, 0, n-1, j, 1);
        }

        ans[idx] = query(1, 0, n-1, l, r);
    }

    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
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