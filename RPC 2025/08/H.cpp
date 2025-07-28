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

const int maxn = 300001, inf = 1e9 + 1;

// Esta implementacion es 0-index
// Para maximo simplemente cambiar los min por max y cambiar el inf por ninf
/*
    Para cada inidice inicialmente se pone su valor y se dice que la cantidad de
    minimos es 1, lo mismo con las update. Cuando queremos calcular el resto del
    arbol verificamos si los dos hijos tienen el mismo minimo y en ese caso
    sumamos sus frecuencias, de lo contrario elegimos el menor. Similar con las
    update pero en ese caso las comparaciones se van haciendo con los padres.
    Finalmente para las query se inicia ans con un valor infinito y frecuencia 0
    y sehacen las comparaciones con l y r de manera similar a como hacemos con
    la creacion del arbol y las updates.
*/

vector<pii> tree(4*maxn);
int n;

void buildTree(vector<pii>& a){
    for(int i = 0; i < n; i++) tree[i + n] = a[i];
    for(int i = n - 1; i > 0; --i){
        if(tree[i << 1].fi == tree[(i << 1) ^ 1].fi) tree[i] = {tree[i << 1].fi, tree[i << 1].se + tree[(i << 1) ^ 1].se};
        else tree[i] = min(tree[i << 1], tree[(i << 1) ^ 1]);
    }
}

void updateTree(int update, int value){
    tree[n + update] = {value, 1};
    update += n;
    for(int i = update; i > 1; i >>= 1){
        if(tree[i].fi == tree[i ^ 1].fi) tree[i>>1] = {tree[i].fi, tree[i].se + tree[i ^ 1].se};
        else tree[i>>1] = min(tree[i], tree[i ^ 1]);
    }
}

// La implementacion es [l, r)
void query(){
    int l = 0, r = n;
    pii ans = {inf, 0};
    l += n; r += n; 
    while(l < r){
        if(l & 1){
            if(ans.fi == tree[l].fi) ans.se += tree[l].se;
            else ans = min(ans, tree[l]);
            l++;
        }
        if(r & 1){
            r--;
            if(ans.fi == tree[r].fi) ans.se += tree[r].se;
            else ans = min(ans, tree[r]);
        }
        l >>= 1; r >>= 1;
    }
    
    // cout<<"menor -> "<<ans.fi<<" freq -> "<<ans.se<<endl;
    cout<<(ans.fi == 0 && ans.se == 1 ? "DA" : "NE")<<endl;
}

void solver(){
    cin>>n;
    map<pii, int> pa;
    vector<pii> inDegree(n+1, {0, 1});
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v; u--; v--;
        inDegree[v].fi++;
        int dir = 0;
        if(u > v){
            swap(u, v);
            dir = 1;
        }
        pa[{u, v}] = dir;
    }

    buildTree(inDegree);
    query();

    int q; cin>>q;
    while(q--){
        int u, v; cin>>u>>v; u--; v--;
        if(u > v) swap(u, v);
        if(pa[{u, v}] == 1){
            inDegree[u].fi--;
            inDegree[v].fi++;
            pa[{u, v}] = 0;
        }
        else{
            inDegree[u].fi++;
            inDegree[v].fi--;
            pa[{u, v}] = 1;
        }

        updateTree(u, inDegree[u].fi);
        updateTree(v, inDegree[v].fi);

        query();
    }
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