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

const int maxn = 1e5 + 2;
vector<ll> tree(4*maxn);

void build(int v, int tl, int tr){
    if(tl == tr) tree[v] = 0;
    else{
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v + 1, tm + 1, tr);
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
    if(tl == tr) tree[v] += val;
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
    for(int i = 0; i < n; i++) cin>>a[i];
    vector<ll> inv(n);
    for(int i = n - 1; i >= 0; i--){
        ll q = query(1, 0, n, 0, a[i]-1);
        inv[i] = q;
        update(1, 0, n, a[i], 1);
    }

    build(1, 0, n);
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ll q = query(1, 0, n, 0, a[i]-1);
        update(1, 0, n, a[i], inv[i]);
        ans += q;
    }

    cout<<ans<<endl;
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