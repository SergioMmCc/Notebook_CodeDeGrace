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

const int maxn = 3e5 + 10, inf = 1e9;
vector<vector<int>> tree(maxn);

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

class segTree {
private:
    int size;
    vector<ld> tree;

    ld neutro = -1.0;

    ld calcOp(ld a, ld b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }

    void update(int pos, ld val, int v, int tl, int tr){ // O(lg(n))
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
    ld calc(int l, int r, int v, int tl, int tr){
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        ld m1 = calc(l, r, 2*v + 1, tl, tm);
        ld m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size, 0.0);
        // build(0, 0, size);
    }

    void update(int pos, ld val){
        update(pos, val, 0, 0, size);
    }

    ld calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v; u--; v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vector<pii> ran(n);
    int cnt = 0;
    DFS(ran, 0, -1, cnt);

    segTree st;
    st.init(n);

    int q; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int u, w; cin>>u>>w; u--;
            ld val = log2((ld)w);
            st.update(ran[u].fi, val);
        }
        else{
            int u, v; cin>>u>>v; u--; v--;
            ld l = st.calc(ran[u].fi, ran[u].se); ld r = st.calc(ran[v].fi, ran[v].se);
            if(l - r >= log2(inf)) cout<<inf<<endl;
            else cout<<fixed<<setprecision(12)<<pow(2.0, l - r)<<endl;
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