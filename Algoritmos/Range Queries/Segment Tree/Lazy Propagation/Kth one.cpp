#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define aint(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

// Segment Tree Lazy Propagation
// - Halla el Kth one en 0-index, es decir, si me piden el indice del 0th one, me estan pididiendo el indice 
//   del primer one. 
// - El array tamebien es 0-index, asi que si estuviera lleno de ones, se considera que el
//   0th one esta en la posicion 0.
// - Las updates son de invertir (los 0s pasan a ser 1s y viceversa).

class segTree {
private:
    int size;
    vector<bool> lazy;
    vector<int> tree;

    int updateOp(int a, int len){
        return len - a;
    }

    int calcOp(int a, int b){
        return a + b;
    }

    void applyUpdOp(int &a, int len){
        a = updateOp(a, len);
    }

    // O(1)
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1 || !lazy[v]) return;
        int tm = (tr + tl) / 2;
        lazy[2*v + 1] = !lazy[2*v + 1];
        lazy[2*v + 2] = !lazy[2*v + 2];
        applyUpdOp(tree[2*v + 1], tm - tl);
        applyUpdOp(tree[2*v + 2], tr - tm);
        lazy[v] = 0;
    }

    // O(lg(n))
    // [l, r)
    void update(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            lazy[v] = 1;
            applyUpdOp(tree[v], tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, 2*v + 1, tl, tm);
        update(l, r, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    int calc(int l, int r, int v, int tl, int tr, int idx){
        propagate(v, tl, tr);
        if(tr == tl + 1) return tl;

        int tm = (tl + tr) / 2;
        if(tree[2*v + 1] >= idx) return calc(l, r, 2*v + 1, tl, tm, idx);
        return calc(l, r, 2*v + 2, tm, tr, idx - tree[2*v + 1]);
    }

    // void build(int v, int tl, int tr){ // O(n)
    //     if(tr == tl + 1){
    //         tree[v] = 0;
    //         return;
    //     }
    //     int tm = (tr + tl) / 2;
    //     build(2*v + 1, tl, tm);
    //     build(2*v + 2, tm, tr);
    //     tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    // }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        lazy.assign(2*size, 0);
        tree.assign(2*size, 0);
        // build(0, 0, size);
    }

    void update(int l, int r){
        update(l, r, 0, 0, size);
    }

    int calc(int l, int r, int k){
        return calc(l, r, 0, 0, size, k);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    segTree st;
    st.init(n);
    while(m--){
        int op; cin>>op;
        if(op == 1){
            int l, r; cin>>l>>r;
            st.update(l, r);
        }
        else{
            int k; cin>>k; 
            k++; // Sumar para pasar de 0th one a 1st one
            cout<<st.calc(0, n, k)<<endl;
        }
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