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
vector<vector<bool>> tree(40, vector<bool>(4*maxn));
const int inf = 1e9 + 1;

void build(vector<int>& a, int v, int tl, int tr, int index){
    if(tl == tr) tree[index][v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm, index);
        build(a, 2*v + 1, tm + 1, tr, index);
        tree[index][v] = tree[index][2*v] || tree[index][2*v + 1];
    }
}

// Las queries son [l, r]
bool query(int v, int tl, int tr, int l, int r, int index){
    if(l > r) return 0;
    if(tl == l && tr == r) return tree[index][v];

    int tm = (tl + tr) / 2;
    return query(2*v, tl, tm, l, min(tm, r), index) || 
        query(2*v + 1, tm + 1, tr, max(tm + 1, l), r, index);
}

void update(int v, int tl, int tr, int pos, int val, int index){
    if(tl == tr) tree[index][v] = val;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2*v, tl, tm, pos, val, index);
        else update(2*v + 1, tm + 1, tr, pos, val, index);
        tree[index][v] = tree[index][2*v] || tree[index][2*v + 1];
    }
}

void solver(){
    int n, m; cin>>n>>m;
    vector<int> ch(n);
    vector<vector<int>> a(40, vector<int>(n));
    for(int i = 0; i < n; i++){
        cin>>ch[i]; ch[i]--;
        a[ch[i]][i] = 1;
    }

    for(int i = 0; i < 40; i++) build(a[i], 1, 0, n-1, i);

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int l, r; cin>>l>>r; l--; r--;
            int ans = 0;
            for(int i = 0; i < 40; i++) ans += query(1, 0, n-1, l, r, i);
            cout<<ans<<endl;
        }
        else{
            int i, val; cin>>i>>val; i--; val--;
            update(1, 0, n-1, i, 0, ch[i]);
            update(1, 0, n-1, i, 1, val);
            ch[i] = val;
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