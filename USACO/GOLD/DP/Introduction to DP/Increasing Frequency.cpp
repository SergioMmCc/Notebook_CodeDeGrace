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

struct Node{
    int seg, pref, suf, sum;
};

const int maxn = 5e5 + 1;
const int ninf = -1e9;
vector<Node> tree(4*maxn);
vector<vector<int>> arr(maxn);

Node op(Node a, Node b){
    Node ans;
    ans.seg = max(0, max(max(a.seg, b.seg), a.suf + b.pref));
    ans.pref = max(0, max(a.pref, a.sum + b.pref));
    ans.suf = max(0, max(b.suf, b.sum + a.suf));
    ans.sum = a.sum + b.sum;

    return ans;
}

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) tree[v] = {max(0, a[tl]), max(0, a[tl]), max(0, a[tl]), a[tl]};
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

int process(int i, int c){
    vector<int> a;
    auto idx = arr[i].begin();
    while(1){
        auto it = ub(all(arr[c]), *idx); // Primer elemento de la subsecuencia de c
        int jdx = it == arr[c].end() ? maxn : *it;
        auto it2 = ub(all(arr[i]), jdx); --it2; // Ultimo elemento de la subsecuencia de i
        a.pb(distance(idx, it2) + 1);

        if(it == arr[c].end()) break;

        auto it3 = ub(all(arr[i]), jdx); // Primer elemento de la subsecuencia de i
        if(it3 == arr[i].end()) break;
        int kdx = *it3;
        auto it4 = ub(all(arr[c]), kdx); --it4; // Ultimo elemento de la subsecuencia de c
        a.pb(-1 - distance(it, it4));

        if(it4 == arr[c].end()) break;

        idx = it3;
    }

    int n = sz(a);
    build(a, 1, 0, n-1);
    int ans = sz(arr[c]) + query(1, 0, n-1, 0, n-1).seg;
    return ans;
}

void solver(){
    int n, c; cin>>n>>c;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        arr[num].pb(i);
    }

    if(sz(arr[c]) == n){
        cout<<n<<endl;
        return;
    }

    if(!sz(arr[c])){
        int ans = 0;
        for(int i = 1; i < maxn; i++){
            ans = max(ans, sz(arr[i]));
        }
        cout<<ans<<endl;
        return;
    }

    int ans = sz(arr[c]);
    for(int i = 1; i < maxn; i++){
        if(!sz(arr[i]) || i == c) continue;
        ans = max(ans, process(i, c));
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}