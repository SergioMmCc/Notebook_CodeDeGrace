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
typedef pair<vector<int>, ll> pvl;

const int maxn = 1e5 + 1;

// Implementacion con array 0-index
// Todas las operaciones se hacen inicialmente con v = 1, tl = 0, tr = n - 1
/*
    Tambien podemos calcular multiplicaciones (incluyendo multiplicacion modular y
    multiplicacion de matrices), operaciones bitwise como and (&), or (|) y xor (^),
    gcd y cualquier operacion que cumpla con la propiedad asociativa
*/ 
vector<vector<int>> tree(4*maxn, vector<int>(40));
vector<ll> inv(4*maxn);
vector<int> emp(40);

pvl merge2(vector<int>& l, vector<int>& r){
    vector<int> ans(40);
    for(int i = 0; i < 40; i++) ans[i] = l[i] + r[i];

    ll c = 0;
    for(int i = 0; i < 39; i++){
        for(int j = i+1; j < 40; j++){
            c += (ll)l[j] * (ll)r[i];
        }
    }

    return {ans, c};
}

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) tree[v][a[tl]] = 1;
    else{
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        pvl ans = merge2(tree[2*v], tree[2*v + 1]);
        tree[v] = ans.fi;
        inv[v] = inv[2*v] + inv[2*v + 1] + ans.se;
    }
}

// Las queries son [l, r]
pvl query(int v, int tl, int tr, int l, int r){
    if(l > r) return {emp, 0LL};
    if(tl == l && tr == r) return {tree[v], inv[v]};

    int tm = (tl + tr) / 2;
    pvl a = query(2*v, tl, tm, l, min(tm, r));
    pvl b = query(2*v + 1, tm + 1, tr, max(tm + 1, l), r);
    pvl c = merge2(a.fi, b.fi);
    return {c.fi, a.se + b.se + c.se}; 
}

void update(int v, int tl, int tr, int pos, int last, int next){
    if(tl == tr){
        tree[v][last] = 0;
        tree[v][next] = 1;
    }
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2*v, tl, tm, pos, last, next);
        else update(2*v + 1, tm + 1, tr, pos, last, next);
        pvl ans = merge2(tree[2*v], tree[2*v + 1]);
        tree[v] = ans.fi;
        inv[v] = inv[2*v] + inv[2*v + 1] + ans.se;
    }
}

void solver(){
    int n, m; cin>>n>>m;
    vector<int> ch(n);
    for(int i = 0; i < n; i++){
        cin>>ch[i];
        ch[i]--;
    }

    build(ch, 1, 0, n-1);
    // for(int i = 0; i < 2*n; i++) cout<<"i -> "<<i<<" inv -> "<<inv[i]<<endl;

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int l, r; cin>>l>>r; l--; r--;
            int ans = 0;
            cout<<query(1, 0, n-1, l, r).se<<endl;
            // cout<<ans<<endl;
        }
        else{
            int i, val; cin>>i>>val; i--; val--;
            update(1, 0, n-1, i, ch[i], val);
            ch[i] = val;
            
            // for(int i = 0; i < 2*n; i++) cout<<"i -> "<<i<<" inv -> "<<inv[i]<<endl;
            // cout<<"merge -> "<<merge(3)<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}