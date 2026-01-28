#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2e5 + 1;
vector<vector<int>> graph(maxn);
vector<int> inDegree(maxn), level(maxn);

void topoSort(int n, vector<int>& orden){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!inDegree[i]){ 
            q.push(i);
            orden.pb(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            inDegree[v]--; 
            if(!inDegree[v]){ 
                level[v] = level[u] + 1;
                q.push(v);
                orden.pb(v);
            }
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 1; i <= n; i++){
        graph[i].clear();
        level[i] = 0;
        inDegree[i] = 0;
    }
    vector<pii> edges, pending;
    for(int i = 0; i < m; i++){
        int type, u, v; cin>>type>>u>>v;
        if(type){
            graph[u].pb(v);
            inDegree[v]++;
            edges.pb({u, v});
        }
        else pending.pb({u, v});
    }

    vector<int> ans;
    topoSort(n, ans);
    if(ans.sz < n){
        cout<<"NO"<<endl;
        return;
    }
    
    cout<<"YES"<<endl;
    for(int i = 0; i < pending.sz; i++){
        int u = pending[i].first, v = pending[i].second;
        if(u > v) swap(u, v);
        if(level[u] > level[v]) swap(u, v);
        edges.pb({u, v});
    }

    for(int i = 0; i < m; i++) cout<<edges[i].first<<' '<<edges[i].second<<endl;
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