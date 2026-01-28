#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1e5 + 1;
vector<vector<int>> tree(maxn);
vector<int> d(maxn);
vector<bool> visited(maxn);

void BFS(int en){
    visited[en] = 1;
    d[en] = 0;
    queue<int> q; q.push(en); stack<int> st; st.push(en);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(visited[v]) continue;
            visited[v] = 1;
            d[v] = d[u] + 1;
            q.push(v);
            st.push(v);
        }
    }

    while(!st.empty()){
        int u = st.top(); st.pop();
        cout<<u<<' ';
    }
    cout<<endl;
}

void solver(){
    int n, st, en; cin>>n>>st>>en;
    for(int i = 1; i <= n; i++){
        tree[i].clear();
        d[i] = 0;
        visited[i] = 0;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    BFS(en);
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