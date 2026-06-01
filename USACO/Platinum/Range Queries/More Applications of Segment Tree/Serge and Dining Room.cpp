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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

class segTree {
private:
    int size;
    vector<int> lazy;
    vector<int> tree;

    int neutro = INT32_MAX - 1;

    int updateOp(int a, int b, int len){
        if(b == neutro) return a;
        if(a == neutro) return b;
        return a + b;
    }

    int calcOp(int a, int b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return max(a, b);
    }

    void applyUpdOp(int &a, int b, int len){
        a = updateOp(a, b, len);
    }

    // O(1)
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
        // Para Update de invertir (cambiar 0s por 1s y viceversa), usar:
        // lazy[2*v + 1] = !lazy[2*v + 1];
        // lazy[2*v + 2] = !lazy[2*v + 2];
        applyUpdOp(lazy[2*v + 1], lazy[v], 1);
        applyUpdOp(tree[2*v + 1], lazy[v], tm - tl);
        applyUpdOp(lazy[2*v + 2], lazy[v], 1);
        applyUpdOp(tree[2*v + 2], lazy[v], tr - tm);
        lazy[v] = neutro;
    }

    // O(lg(n))
    // [l, r)
    void update(int l, int r, int val, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            applyUpdOp(lazy[v], val, 1);
            applyUpdOp(tree[v], val, tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, val, 2*v + 1, tl, tm);
        update(l, r, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    int calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return neutro;
        if(tr - tl == 1) return tl;

        int tm = (tl + tr) / 2;
        if(tree[2*v + 2] > 0) return calc(l, r, 2*v + 2, tm, tr);
        if(tree[2*v + 1] > 0) return calc(l, r, 2*v + 1, tl, tm);
        return neutro;
    }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        lazy.assign(2*size, neutro);
        tree.assign(2*size, 0LL);
    }

    void update(int l, int r, int val){
        update(l, r, val, 0, 0, size);
    }

    int calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};

const int maxn = 1e6;

void solver(){
    segTree st; st.init(maxn + 1);
    int n, m; cin>>n>>m;
    vi a(n);
    vi b(m);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        st.update(1, a[i]+1, 1);
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
        st.update(1, b[i]+1, -1);
    }

    int q; cin>>q;
    while(q--){
        int op, idx, val; cin>>op>>idx>>val; idx--;
        if(op == 1){
            st.update(1, a[idx]+1, -1);
            st.update(1, val+1, 1);
            a[idx] = val;
        }
        else{
            st.update(1, b[idx]+1, 1);
            st.update(1, val+1, -1);
            b[idx] = val;
        }

        int ans = st.calc(0, maxn+1);
        cout<<(ans > maxn ? -1 : ans)<<endl;
    }
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