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

struct Matriz{
    int a[2][2];
};

const int maxn = 2e5 + 1;
Matriz iden;
void calcIden(){
    iden.a[0][0] = iden.a[1][1] = 1;
}
int mod;
Matriz tree[4*maxn];

Matriz mult(Matriz a, Matriz b){
    Matriz ans;
    ans.a[0][0] = (a.a[0][0] * b.a[0][0] + a.a[0][1] * b.a[1][0]) % mod;
    ans.a[0][1] = (a.a[0][0] * b.a[0][1] + a.a[0][1] * b.a[1][1]) % mod;
    ans.a[1][0] = (a.a[1][0] * b.a[0][0] + a.a[1][1] * b.a[1][0]) % mod;
    ans.a[1][1] = (a.a[1][0] * b.a[0][1] + a.a[1][1] * b.a[1][1]) % mod;
    return ans;
}


void build(Matriz a[], int v, int tl, int tr){
    if(tl == tr) tree[v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        tree[v] = mult(tree[2*v], tree[2*v + 1]);
    }
}

// Las queries son [l, r]
Matriz query(int v, int tl, int tr, int l, int r){
    if(l > r) return iden;
    if(tl == l && tr == r) return tree[v];

    int tm = (tl + tr) / 2;
    Matriz a = query(2*v, tl, tm, l, min(tm, r));
    Matriz b = query(2*v + 1, tm + 1, tr, max(tm + 1, l), r);
    return mult(a, b);
}

void solver(){
    int n, m; cin>>mod>>n>>m;
    Matriz a[n];
    for(int i = 0; i < n; i++) cin>>a[i].a[0][0]>>a[i].a[0][1]>>a[i].a[1][0]>>a[i].a[1][1];

    build(a, 1, 0, n-1);

    while(m--){
        int l, r; cin>>l>>r; l--; r--;
        Matriz ans = query(1, 0, n-1, l, r);
        cout<<ans.a[0][0]<<' '<<ans.a[0][1]<<endl<<ans.a[1][0]<<' '<<ans.a[1][1]<<endl<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    calcIden();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}