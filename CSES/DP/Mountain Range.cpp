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
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

struct node{ // Change
    int val;
};

class segTree {
private:
    int size;
    vector<node> tree;

    node neutro = {INT32_MAX - 1}; // Change

    node calcOp(node a, node b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        if(a.val >= b.val) return a;
        return b;
    }

    void update(int pos, int val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = {val}; // Change
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    node calc(int l, int r, int v, int tl, int tr){ // Change si walking on segment tree
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v]; // si walking on seg tree -> tr - tl == 1

        int tm = (tl + tr) / 2;
        node m1 = calc(l, r, 2*v + 1, tl, tm);
        node m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vi& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = {a[tl]}; // Change
           return;
        }
        int tm = (tr + tl) / 2;
        build(a, 2*v + 1, tl, tm);
        build(a, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size, {0LL});
        // build(0, 0, size);
    }

    node calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vi& a){
        build(a, 0, 0, size);
    }
};

int go(int lev, int idx, vi&dp, vector<vi>& ocur, vi& pl, vi& pr, segTree& st){
    if(dp[idx] != -1) return dp[idx];
    dp[idx] = 1;
    if(!lev) return dp[idx];

    int gl = st.calc(pl[idx]+1, idx).val, gr = st.calc(idx+1, pr[idx]).val;
    if(gl < lev){
        auto it = ub(all(ocur[gl]), pl[idx]);
        int j = distance(ocur[gl].begin(), it);
        for(; j < sz(ocur[gl]); j++){
            if(ocur[gl][j] >= idx) break;
            dp[idx] = max(dp[idx], 1 + go(gl, ocur[gl][j], dp, ocur, pl, pr, st));
        }
    }

    if(gr < lev){
        auto it = ub(all(ocur[gr]), idx);
        int j = distance(ocur[gr].begin(), it);
        for(; j < sz(ocur[gr]); j++){
            if(ocur[gr][j] >= pr[idx]) break;
            dp[idx] = max(dp[idx], 1 + go(gr, ocur[gr][j], dp, ocur, pl, pr, st));
        }
    }

    return dp[idx];
}

void solver(){
    int n; cin>>n;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    vi aux = a;
    sort(all(aux));

    // Comprimir, guardar las ocurrencias de cada valor y agregar paredes en los extremos
    int next = 0;
    map<int, int> T;
    for(int i = 1; i <= n; i++){
        if(T.find(aux[i]) != T.end()) continue;
        T[aux[i]] = next;
        next++;
    }
    vector<vi> ocur(next);
    for(int i = 1; i <= n; i++){
        a[i] = T[a[i]];
        ocur[a[i]].pb(i);
    }
    a[0] = next;
    a.pb(next);
    segTree st; st.init(n+1);
    st.build(a);

    // Hallar los limites de cada valor
    vi pl(n+2), pr(n+2, n+1);
    set<int> lim; lim.insert(0); lim.insert(n+1);
    for(int i = next-1; i >= 0; i--){
        for(int j : ocur[i]) lim.insert(j);
        for(int j : ocur[i]){
            auto it = lim.ub(j);
            pr[j] = *it;
            --it; --it;
            pl[j] = *it;
        }
    }

    vi dp(n+2, -1);
    cout<<go(next, 0, dp, ocur, pl, pr, st) - 1<<endl;
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