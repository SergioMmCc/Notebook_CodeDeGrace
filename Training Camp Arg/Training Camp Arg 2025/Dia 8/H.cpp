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

const int maxn = 3e5 + 1;
vector<vector<int>> tree(maxn);
vector<pii> ans;

int DFS(int u, int pa){
    queue<int> add;
    for(int v : tree[u]){
        if(v == pa) continue;
        add.push(DFS(v, u));
    }

    while(add.sz > 1){
        int x = add.front(); add.pop();
        int y = add.front(); add.pop();
        ans.pb({x, y});
    }

    if(add.empty()){
        // cout<<"Add me -> "<<u<<endl;
        return u;
    }

    // cout<<"Add that -> "<<add.front()<<endl;
    return add.front();
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++) tree[i].clear();
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    int root = 0;
    for(int i = 1; !root && i <= n; i++){
        if(tree[i].sz % 2 == 0) root = i;
    }

    if(!root){
        cout<<-1<<endl;
        return;
    }

    DFS(root, -1);
    cout<<ans.sz<<endl;
    for(pii edge : ans) cout<<edge.fi<<' '<<edge.se<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        ans.clear();
        solver();
    }

    return 0;
}