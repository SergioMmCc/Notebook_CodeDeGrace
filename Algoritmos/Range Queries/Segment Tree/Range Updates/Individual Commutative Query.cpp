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
    - Las operaciones de las updates pueden ser cualquiera que cumpla con las propiedades
      conmutativa y asociativa (suma, multiplicacion, max, min, gcd, lcm), se debe tener
      cuidado con el valor inicial (ejemplo: suma en 0, multiplicacion en 1).
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

// Las updates son [l, r]
void update(int v, int tl, int tr, int l, int r, ll val){
    if(l > r) return;
    if(tl == l && tr == r){
        tree[v] = max(val, tree[v]);
        return;
    }

    int tm = (tl + tr) / 2;
    update(2*v, tl, tm, l, min(tm, r), val);
    update(2*v + 1, tm + 1, tr, max(tm + 1, l), r, val);
}

ll query(int v, int tl, int tr, int pos){
    ll ans = tree[v];
    
    if(tl == tr) return ans;

    int tm = (tl + tr) / 2;
    if(pos <= tm) ans = max(ans, query(2*v, tl, tm, pos));
    else ans = max(ans, query(2*v + 1, tm + 1, tr, pos));

    return ans;
}

void solver(){
    int n, m; cin>>n>>m;

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int l, r; ll val; cin>>l>>r>>val; r--;
            update(1, 0, n-1, l, r, val);
        }
        else{
            int i; cin>>i;
            cout<<query(1, 0, n-1, i)<<endl;
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