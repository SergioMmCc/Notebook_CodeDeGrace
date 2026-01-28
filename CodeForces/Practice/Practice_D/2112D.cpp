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

const int maxn = 2e5 + 2;
vector<vector<int>> tree(maxn);
vector<bool> bip(maxn);

void BFS(int s, int n){
    bip[tree[s][0]] = 1;
    vector<bool> visited(n+1);
    visited[s] = 1; visited[tree[s][0]] = 1; visited[tree[s][1]] = 1;
    queue<int> q; q.push(tree[s][0]); q.push(tree[s][1]);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(visited[v]) continue;

            visited[v] = 1;
            bip[v] = !bip[u];
            q.push(v);
        }
    }
}

void solver(){
    int n; cin>>n;
    vector<pii> edges;
    for(int i = 1; i <= n; i++){
        tree[i].clear();
        bip[i] = 0;
    }
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        edges.pb({u, v});
        tree[u].pb(v);
        tree[v].pb(u);
    }

    int s = 0;
    for(int i = 1; !s && i <= n; i++){
        if(tree[i].sz == 2) s = i;
    }

    if(!s){
        cout<<"NO"<<endl;
        return;
    }

    BFS(s, n);

    cout<<"YES"<<endl;
    for(pii edge : edges){
        if(edge.fi == s){
            if(bip[edge.se]) cout<<s<<' '<<edge.se<<endl;
            else cout<<edge.se<<' '<<s<<endl;
        }
        else if(edge.se == s){
            if(bip[edge.fi]) cout<<s<<' '<<edge.fi<<endl;
            else cout<<edge.fi<<' '<<s<<endl;
        }

        else{
            if(bip[edge.fi]) cout<<edge.se<<' '<<edge.fi<<endl;
            else cout<<edge.fi<<' '<<edge.se<<endl;
        }
    }
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