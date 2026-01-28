#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;

// Las queries son [l, r]
int query(vector<int>& tree, int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return tree[v] % mod;

    int tm = (tl + tr) / 2;
    return (query(tree, 2*v, tl, tm, l, min(tm, r))
         + query(tree, 2*v + 1, tm + 1, tr, max(tm + 1, l), r)) % mod;
}

void update(vector<int>& tree, int v, int tl, int tr, int pos, int val){
    if(tl == tr) tree[v] = (tree[v] + val) % mod;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(tree, 2*v, tl, tm, pos, val);
        else update(tree, 2*v + 1, tm + 1, tr, pos, val);
        tree[v] = (tree[2*v] + tree[2*v + 1]) % mod;
    }
}

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<vector<int>> col(n+1, vector<int>(4*n+1, 0)), row(n+1, vector<int>(4*n+1, 0));
    update(col[0], 1, 0, n, 0, 1LL);
    update(row[0], 1, 0, n, 0, 1LL);

    stack<pair<int, pii>> upd;

    for(int i = 1; i <= n; i++){
        for(int k = 0; k <= a[i]; k++){
            upd.push({query(col[k], 1, 0, n, 0, a[i]), {a[i], k}});
        }
        for(int j = a[i] + 1; j <= n; j++){
            upd.push({query(row[j], 1, 0, n, 0, a[i]), {j, a[i]}});
        }

        while(!upd.empty()){
            int r = upd.top().se.fi, c = upd.top().se.se; ll val = upd.top().fi;
            upd.pop();
            update(col[c], 1, 0, n, r, val);
            update(row[r], 1, 0, n, c, val);
        }
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans = (ans + query(col[i], 1, 0, n, 0, n)) % mod;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}