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
vector<int> inDegree(maxn);

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
                q.push(v);
                orden.pb(v);
            }
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        inDegree[v]++;
    }

    vector<int> ans;
    topoSort(n, ans);
    if(ans.sz < n) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i = 0; i < ans.sz; i++){
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
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