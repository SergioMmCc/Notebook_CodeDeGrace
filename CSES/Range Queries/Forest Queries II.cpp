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

struct node{ // Change
    ll val;
};

class segTree2D {
private:
    int size_n, size_m; // tree[n][m], n es 'y', m es 'x'
    vector<vector<node>> tree;

    node neutro = {LLONG_MAX - 1}; // Change

    node calcOp(node a, node b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans = {a.val + b.val};
        return ans;
    }


    // O(lg(n)*lg(m))
    void update_x(int y, int x, ll val, int yv, int ytl, int ytr, int xv, int xtl, int xtr){
        if(xtr - xtl == 1){
            if(ytr - ytl == 1) tree[yv][xv] = {val};
            else tree[yv][xv] = calcOp(tree[2*yv + 1][xv], tree[2*yv + 2][xv]);
        }
        else{
            int xtm = (xtl + xtr) / 2;
            if(x < xtm) update_x(y, x, val, yv, ytl, ytr, 2*xv + 1, xtl, xtm);
            else update_x(y, x, val, yv, ytl, ytr, 2*xv + 2, xtm, xtr);

            tree[yv][xv] = calcOp(tree[yv][2*xv + 1], tree[yv][2*xv + 2]);
        }
    }

    void update_y(int y, int x, ll val, int yv, int ytl, int ytr){
        if(ytr - ytl != 1){
            int ytm = (ytl + ytr) / 2;
            if(y < ytm) update_y(y, x, val, 2*yv + 1, ytl, ytm);
            else update_y(y, x, val, 2*yv + 2, ytm, ytr);
        }

        update_x(y, x, val, yv, ytl, ytr, 0, 0, size_m);
    }


    // O(lg(n)*lg(m))
    // [yl, yr), [xl, xr)
    node calc_x(int xl, int xr, int yv, int xv, int xtl, int xtr){
        if(xtl >= xr || xl >= xtr) return neutro;
        if(xtl >= xl && xtr <= xr) return tree[yv][xv];

        int xtm = (xtl + xtr) / 2;
        node m1 = calc_x(xl, xr, yv, 2*xv + 1, xtl, xtm);
        node m2 = calc_x(xl, xr, yv, 2*xv + 2, xtm, xtr);
        return calcOp(m1, m2);
    }

    node calc_y(int yl, int yr, int xl, int xr, int yv, int ytl, int ytr){
        if(ytl >= yr || yl >= ytr) return neutro;
        if(ytl >= yl && ytr <= yr) return calc_x(xl, xr, yv, 0, 0, size_m);

        int ytm = (ytl + ytr) / 2;
        node m1 = calc_y(yl, yr, xl, xr, 2*yv + 1, ytl, ytm);
        node m2 = calc_y(yl, yr, xl, xr, 2*yv + 2, ytm, ytr);
        return calcOp(m1, m2);
    }


    void build_x(vector<vector<node>>& a, int yv, int ytl, int ytr, int xv, int xtl, int xtr){
        if(xtr - xtl == 1){
            if(ytr - ytl == 1){
                if(ytl < sz(a) && xtl < sz(a[ytl])) tree[yv][xv] = {a[ytl][xtl]};
            }
            else tree[yv][xv] = calcOp(tree[2*yv + 1][xv], tree[2*yv + 2][xv]);
        }
        else{
            int xtm = (xtl + xtr) / 2;
            build_x(a, yv, ytl, ytr, 2*xv + 1, xtl, xtm);
            build_x(a, yv, ytl, ytr, 2*xv + 2, xtm, xtr);

            tree[yv][xv] = calcOp(tree[yv][2*xv + 1], tree[yv][2*xv + 2]);
        }
    }

    void build_y(vector<vector<node>>& a, int yv, int ytl, int ytr){ // O(n)
        if(ytr - ytl != 1){
            int ytm = (ytr + ytl) / 2;
            build_y(a, 2*yv + 1, ytl, ytm);
            build_y(a, 2*yv + 2, ytm, ytr);
        }
        
        build_x(a, yv, ytl, ytr, 0, 0, size_m);
    }


public:
    void init(int n, int m){
        size_n = 1, size_m = 1;
        while(size_n < n) size_n *= 2;
        while(size_m < m) size_m *= 2;
        tree.assign(2*size_n, vector<node>(2*size_m, {0}));
        // build(a, 0, 0, size_n);
    }

    void update(int y, int x, ll val){
        update_y(y, x, val, 0, 0, size_n);
    }

    node calc(int yl, int yr, int xl, int xr){
        return calc_y(yl, yr, xl, xr, 0, 0, size_n);
    }

    void build(vector<vector<node>>& a){
        build_y(a, 0, 0, size_n);
    }
};

void solver(){
    int n, q; cin>>n>>q;
    vector<vector<node>> a(n, vector<node>(n));
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        for(int j = 0; j < n; j++){
            a[i][j].val = s[j] == '*' ? 1 : 0;
        }
    }
    segTree2D st;
    st.init(n, n);
    st.build(a);

    while(q--){
        int op; cin>>op;
        if(op == 1){ // Update
            int y, x; cin>>y>>x; x--; y--;
            a[y][x].val = a[y][x].val == 1 ? 0 : 1;
            st.update(y, x, a[y][x].val);
        }
        else{ // Calc
            int y1, x1, y2, x2; cin>>y1>>x1>>y2>>x2; y1--; x1--;
            cout<<st.calc(y1, y2, x1, x2).val<<endl;
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}