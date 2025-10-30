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

void build(int v, int tl, int tr){
    if(tl == tr) tree[v] = {1, tl};
    else{
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v + 1, tm + 1, tr);
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
    int n; cin>>n;
    build(1, 0, n-1);
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        int k = a[i];
        int aux = query(1, 0, n-1, k+1);
        ans[i] = n - aux;
        update(1, 0, n-1, aux, 0);
    }

    for(int i = 0; i < n; i++) cout<<ans[i]<<' ';
    cout<<endl;
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