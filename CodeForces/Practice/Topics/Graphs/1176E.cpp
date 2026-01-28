#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2e5 + 2;
vector<vector<int>> graph(maxn);
vector<int> color(maxn);
vector<int> group1, group2;

void DFS(int u){
    for(auto v : graph[u]) {
        if(color[v]) continue;
        color[v] = 3 - color[u];
        color[v] == 1 ? group1.pb(v) : group2.pb(v);
        DFS(v);
    }
}

void solver(){
    int n, m; cin>>n>>m;
    group1.clear(); group2.clear();
    for(int i = 1; i <= n; i++){
        color[i] = 0;
        graph[i].clear();
    }
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    group1.pb(1);
    color[1] = 1;
    DFS(1);

    if(group1.sz < group2.sz){
        cout<<group1.sz<<endl;
        for(int u : group1) cout<<u<<' ';
    }
    else{
        cout<<group2.sz<<endl;
        for(int u : group2) cout<<u<<' ';
    }

    cout<<endl;
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