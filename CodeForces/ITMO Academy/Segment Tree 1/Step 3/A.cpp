#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb pushback
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const int maxn = 1e5 + 1;
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
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        save--;

        cout<<query(1, 0, n-1, save+1, n-1)<<' ';
        update(1, 0, n-1, save, 1);
    }
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