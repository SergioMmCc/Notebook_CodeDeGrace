#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 100005;
vector<vector<int>> tree(maxn);

ld BFS(vector<ld>& prob, int n){
    ld ans = 0;
    vector<bool> visited(n+1); visited[1] = 1;
    vector<int> distance(n+1); distance[1] = 0;
    queue<int> q; q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(visited[v]) continue;
            if(u == 1) prob[v] = 1.0 / (ld)tree[u].sz;
            else prob[v] = prob[u] / ((ld)tree[u].sz - 1);
            visited[v] = 1;
            distance[v] = 1 + distance[u];
            q.push(v);
            if(tree[v].sz == 1) ans += (ld)distance[v] * prob[v];
        }
    }

    return ans;
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vector<ld> prob(n+1, 1.0);
    cout<<fixed<<setprecision(10)<<BFS(prob, n)<<endl;
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