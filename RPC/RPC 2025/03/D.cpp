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

const int maxn = 4e5 + 7, ninf = -1e9;
vector<int> tree(4 * maxn);

void buildTree(vector<int>& a, int n){
    for(int i = 0; i < n; i++) tree[i + n] = a[i];
    for(int i = n - 1; i > 0; --i) tree[i] = max(tree[i << 1], tree[(i << 1) ^ 1]); //i << 1 -> i*2
    // Si i << 1 es el hijo izquierdo,(i << 1) ^ 1 es el hijo derecho y viceversa
}

void updateTree(int update, int value, int n){
    tree[n + update] = value;
    update += n;
    for(int i = update; i > 1; i >>= 1) tree[i>>1] = max(tree[i], tree[i ^ 1]); //Si i es el hijo por izquierda de i/2, entonces i ^ 1 es el hijo por derecha, y viceversa
    //i >> i -> i/2
}

// La implementacion es [l, r)
int query(int l, int r, int n){
    int ans = ninf;
    l += n; r += n; 
    while(l < r){
        if(l & 1) ans = max(ans, tree[l++]);
        if(r & 1) ans = max(ans, tree[--r]);
        l >>= 1; r >>= 1;
    }
    
    return ans;
}

void solver(){
    int n, m; cin>>n>>m;
    vector<pii> a(n+1), b(m+1);
    map<int, int> comp;
    int nextP = 1;
    set<int> points;

    // Compresion
    for(int i = 1; i <= n; i++){
        int l, r; cin>>l>>r;
        a[i] = {l, r};
        points.insert(l); points.insert(r);
    }

    for(int i = 1; i <= m; i++){
        int l, r; cin>>l>>r;
        b[i] = {l, r};
        points.insert(l); points.insert(r);
    }

    for(int point : points){
        if(comp.find(point) == comp.end()){
            comp[point] = nextP;
            nextP += 2;
        }
    }

    for(int i = 1; i <= n; i++){
        int l = a[i].fi, r = a[i].se;
        a[i] = {comp[l], comp[r]};
    }

    for(int i = 1; i <= m; i++){
        int l = b[i].fi, r = b[i].se;
        b[i] = {comp[l], comp[r]};
    }

    // Contar por segmento
    vector<int> s(nextP), t(nextP), accS(nextP), accT(nextP), sh(nextP);
    for(int i = 1; i <= n; i++){
        int l = a[i].fi, r = a[i].se;
        s[l]++;
        s[r+1]--;
    }
    for(int i = 1; i <= m; i++){
        int l = b[i].fi, r = b[i].se;
        t[l]++;
        t[r+1]--;
    }

    for(int i = 1; i < nextP; i++){
        accT[i] = accT[i-1] + t[i];
        accS[i] = accS[i-1] + s[i];
        if(accT[i] == 0) continue;                    
        sh[i - 1] = (accS[i] + accT[i] - 1) / accT[i];
    }

    // Imprimir para ver si esta bien
    // for(int i = 1; i < nextP; i++){
    //     cout<<accS[i]<<' '<<accT[i]<<' '<<sh[i]<<endl;
    // }

    buildTree(sh, nextP);
    
    for(int i = 1; i <= m; i++){
        if(i > 1) cout<<' ';
        int l = b[i].fi - 1, r = b[i].se;
        cout<<query(l, r, nextP);
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