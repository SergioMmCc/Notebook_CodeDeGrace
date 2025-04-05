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
const int maxn = 100001, ninf = -1e9;

// Esta implementacion es 0-index
/* 
    Para minimo simplemente cambiar los max por min y cambiar el ninf por inf
*/
vector<int> tree(2*maxn);
int n;

void buildTree(vector<int>& a){
    for(int i = 0; i < n; i++) tree[i + n] = a[i];
    for(int i = n - 1; i > 0; --i) tree[i] = max(tree[i << 1], tree[(i << 1) ^ 1]); //i << 1 -> i*2
    // Si i << 1 es el hijo izquierdo,(i << 1) ^ 1 es el hijo derecho y viceversa
}

void updateTree(int update, int value){
    tree[n + update] = value;
    update += n;
    for(int i = update; i > 1; i >>= 1) tree[i>>1] = max(tree[i], tree[i ^ 1]); //Si i es el hijo por izquierda de i/2, entonces i ^ 1 es el hijo por derecha, y viceversa
    //i >> i -> i/2
}

// La implementacion es [l, r)
int query(int l, int r){
    int ans = ninf;
    l += n; r += n; 
    while(l < r){
        if(l & 1) ans = max(ans, tree[l++]);
        if(r & 1) ans = max(ans, tree[--r]);
        l >>= 1; r >>= 1;
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int q; cin>>n>>q;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        a.pb(save);
    }
    buildTree(a);
    
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int x, w; cin>>x>>w;
            updateTree(x, w);
        }
        else{
            int l, r; cin>>l>>r;
            cout<<query(l, r)<<endl;
        }
    }

    return 0;
}