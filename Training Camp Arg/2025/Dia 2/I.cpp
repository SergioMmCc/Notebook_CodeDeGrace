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

const int maxn = 2e5 + 1;
vector<vector<pii>> tree(maxn);

bool BFS(int n, vector<int>& prio){
    vector<bool> visited(n+1); visited[1] = 1;
    int index = 1;
    queue<int> q; q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(prio[u] != index) return 0;
        index++;
        // cout<<"u -> "<<u<<" prio[u] -> "<<prio[u]<<" index -> "<<index<<endl;
        for(pii adj : tree[u]){
            int v = adj.se;
            if(visited[v]) continue;
            visited[v] = 1;
            q.push(v);
        }
    }

    return 1;
}

void solver(){
    int n; cin>>n;
    vector<pii> edge;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        edge.pb({u, v});
    }

    vector<int> prio(n+1);
    for(int i = 1; i <= n; i++){
        int num; cin>>num;
        prio[num] = i;
    }

    for(int i = 0; i < n - 1; i++){
        int u = edge[i].fi, v = edge[i].se;
        tree[u].pb({prio[v], v});
        tree[v].pb({prio[u], u});
    }

    for(int i = 1; i <= n; i++) sort(tree[i].begin(), tree[i].end());

    cout<<(BFS(n, prio) ? "Yes" : "No")<<endl;
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