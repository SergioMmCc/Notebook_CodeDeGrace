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

struct Node{
    ll seg, pref, suf, sum; // El resultado del segmento con mayor suma se guarda en seg
};

const int maxn = 1e5 + 1;
const ll ninf = -1e18;
vector<Node> tree(4*maxn);

Node op(Node a, Node b){
    Node ans;
    ans.seg = max(0LL, max(max(a.seg, b.seg), a.suf + b.pref));
    ans.pref = max(0LL, max(a.pref, a.sum + b.pref));
    ans.suf = max(0LL, max(b.suf, b.sum + a.suf));
    ans.sum = a.sum + b.sum;

    return ans;
}

void build(vector<ll>& a, int v, int tl, int tr){
    if(tl == tr) tree[v] = {max(0LL, a[tl]), max(0LL, a[tl]), max(0LL, a[tl]), a[tl]};
    else{
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        tree[v] = op(tree[2*v], tree[2*v + 1]);
    }
}

// Las queries son [l, r]
Node query(int v, int tl, int tr, int l, int r){
    if(l > r) return {0, 0, 0, ninf};
    if(tl == l && tr == r) return tree[v];

    int tm = (tl + tr) / 2;
    Node a = query(2*v, tl, tm, l, min(tm, r));
    Node b = query(2*v + 1, tm + 1, tr, max(tm + 1, l), r);

    return op(a, b);
}

void update(int v, int tl, int tr, int pos, ll val){
    if(tl == tr) tree[v] = {max(0LL, val), max(0LL, val), max(0LL, val), val};
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2*v, tl, tm, pos, val);
        else update(2*v + 1, tm + 1, tr, pos, val);
        tree[v] = op(tree[2*v], tree[2*v + 1]);
    }
}

void solver(){
    int n, m; cin>>n>>m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    build(a, 1, 0, n - 1);

    Node ans = query(1, 0, n - 1, 0, n - 1);
    cout<<max(0LL, ans.seg)<<endl;

    while(m--){
        int idx; ll val; cin>>idx>>val;
        update(1, 0, n - 1, idx, val);
        ans = query(1, 0, n - 1, 0, n - 1);
        cout<<ans.seg<<endl;
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