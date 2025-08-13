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
vector<pii> tree(4*maxn);

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) tree[v] = {a[tl], tl};
    else{
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        tree[v] = {tree[2*v].fi + tree[2*v + 1].fi, 0};
    }
}

// Las queries son [l, r]
int query(int v, int tl, int tr, int k){
    if(tl == tr) return tree[v].se;

    int tm = (tl + tr) / 2;
    if(tree[2*v].fi >= k) return query(2*v, tl, tm, k);
    return query(2*v + 1, tm + 1, tr, k - tree[2*v].fi);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr) tree[v] = {val, pos};
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2*v, tl, tm, pos, val);
        else update(2*v + 1, tm + 1, tr, pos, val);
        tree[v] = {tree[2*v].fi + tree[2*v + 1].fi, 0};
    }
}

void solver(){
    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    build(a, 1, 0, n-1);

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int i; cin>>i;
            a[i] = 1 ^ a[i];
            update(1, 0, n-1, i, a[i]);
        }
        else{
            int k; cin>>k; k++;
            cout<<query(1, 0, n-1, k)<<endl;
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