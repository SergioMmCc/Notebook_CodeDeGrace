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

const int maxn = 4e5 + 1;
vector<vector<int>> tree(maxn);

class segTree {
private:
    int size;
    vector<int> tree;

    int neutro = -1;

    int calcOp(int a, int b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return max(a, b);
    }

    void update(int pos, int val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = val;
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    int calc(int l, int r, int v, int tl, int tr){
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        int m1 = calc(l, r, 2*v + 1, tl, tm);
        int m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vector<int>& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = a[tl];
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
        tree.assign(2*size, 0);
        // build(0, 0, size);
    }

    void update(int pos, int val){
        update(pos, val, 0, 0, size);
    }

    int calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vector<int>& a){
        build(a, 0, 0, size);
    }
};

void DFS(vector<pii>& ran, int u, int pa, int &cnt){
    // Se dice que el rango de u inicia en cnt. Ademas ese sera su indice en el array que se contruira.
    ran[u].fi = cnt;
    cnt++; // Se suma 1 para guardar que se ha visitado un nuevo nodo
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS(ran, v, u, cnt); // Se visita el subarbol que tiene u como raiz
    }

    // Despues de visitar los nodos que pertenecen al subarbol de u, podemos decir en que indice termina el rango de u
    ran[u].se = cnt;
}

void solver(){
    int n; cin>>n;
    vector<int> val(n+1);
    vector<vector<int>> vals(n+1);
    int maxx = 0;
    for(int i = 1; i <= n; i++){
        tree[i].clear();
        int x; cin>>x;
        val[i] = x;
        vals[x].pb(i);
        maxx = max(maxx, x);
    }

    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vector<pii> ran(n+1);
    int cnt = 0;
    DFS(ran, 1, 0, cnt);
    vector<int> call(n);
    for(int i = 1; i <= n; i++) call[ran[i].fi] = val[i];

    segTree st;
    st.init(n);
    st.build(call);

    int cur = maxx-1;
    while(cur > 0){
        for(int idx : vals[cur]){
            if(idx == 1) continue;
            int aux = max(st.calc(0, ran[idx].fi), st.calc(ran[idx].se, n));
            if(aux > cur){
                cout<<idx<<endl;
                return;
            }
        }

        cur--;
    }

    cout<<0<<endl;
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