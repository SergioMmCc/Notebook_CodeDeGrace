#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 2e5 + 2;


int BFS1(int s, int n, const vector<vector<int>>& tree){
    vector<bool>visited(n+1); visited[s] = 1;
    queue<int> q; q.push(s);
    vector<int> distance(n+1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(visited[v]) continue;
            visited[v] = 1;
            distance[v] = distance[u] + 1;
            q.push(v);
        }
    }

    int ans = 0, maxDistance = -1;
    for(int i = 1; i <= n; i++){
        if(distance[i] > maxDistance){
            maxDistance = distance[i];
            ans = i;
        }
    }

    return ans;
}

int BFS2(int s, int n, const vector<vector<int>>& tree){
    vector<bool>visited(n+1); visited[s] = 1;
    queue<int> q; q.push(s);
    vector<int> distance(n+1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(visited[v]) continue;
            visited[v] = 1;
            distance[v] = distance[u] + 1;
            q.push(v);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, distance[i]);
    return ans;
}

void solver(){
    int n; cin>>n;
    vector<vector<int>> tree1(n + 1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree1[u].pb(v);
        tree1[v].pb(u);
    }
    int largest = BFS1(1, n, tree1);
    int aux1 = BFS2(largest, n, tree1);

    int m; cin>>m;
    vector<vector<int>> tree2(m + 1);
    for(int i = 1; i < m; i++){
        int u, v; cin>>u>>v;
        tree2[u].pb(v);
        tree2[v].pb(u);
    }
    largest = BFS1(1, m, tree2);
    int aux2 = BFS2(largest, m, tree2);
    int ans = (aux1 + 1) / 2 + (aux2 + 1) / 2 + 1;
    ans = max(ans, max(aux1, aux2));
    cout<<ans<<endl;
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