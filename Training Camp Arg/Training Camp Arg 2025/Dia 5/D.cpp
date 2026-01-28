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
const int maxn = 200001, ninf = -1e9;

// Esta implementacion es 0-index
/* 
    Para minimo simplemente cambiar los max por min y cambiar el ninf por inf
*/
vector<pii> tree(4*maxn);
int n;

void buildTree(){
    for(int i = 0; i < n; i++) tree[i + n] = {0, -1};
    for(int i = n - 1; i > 0; --i) tree[i] = {0, -1}; //i << 1 -> i*2
    // Si i << 1 es el hijo izquierdo,(i << 1) ^ 1 es el hijo derecho y viceversa
}

void updateTree(int update, int value){
    tree[n + update] = {value, update};
    update += n;
    for(int i = update; i > 1; i >>= 1){
        if(tree[i].fi == tree[i ^ 1].fi) tree[i>>1] = min(tree[i], tree[i ^ 1]);
        else tree[i>>1] = max(tree[i], tree[i ^ 1]);
     } //Si i es el hijo por izquierda de i/2, entonces i ^ 1 es el hijo por derecha, y viceversa
    //i >> i -> i/2
}

// La implementacion es [l, r)
pii query(int l, int r){
    pii ans = {ninf, -1};
    l += n; r += n; 
    while(l < r){
        if(l & 1){
            if(ans.fi == tree[l].fi) ans = min(ans, tree[l]);
            else ans = max(ans, tree[l]);
            l++;
        }
        if(r & 1){
            r--;
            if(ans.fi == tree[r].fi) ans = min(ans, tree[r]);
            else ans = max(ans, tree[r]);
        }
        l >>= 1; r >>= 1;
    }
    return ans;
    // return max(ans, {0, -1});
}

void solver(){
    cin>>n;
    buildTree();
    vector<int> freq(n+1, -1);
    vector<pii> ranges;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        if(freq[num] != -1) ranges.pb({freq[num], i});
        freq[num] = i;
    }

    int ans = 0;
    for(pii ran : ranges){
        // cout<<ran.fi<<' '<<ran.se<<endl;
        int l = ran.fi, r = ran.se;
        pii maxi = query(0, l + 1);
        int aux = maxi.fi + r - l + 1;
        if(maxi.se == l) aux--;
        // cout<<"maxi.fi -> "<<maxi.fi<<" maxi.se -> "<<maxi.se<<" aux -> "<<aux<<endl;
        updateTree(r, aux);
        ans = max(ans, aux);
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}