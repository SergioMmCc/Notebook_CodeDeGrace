#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 200005;
int components;
vector<int> graph[maxn];
vector<int> leader(maxn);
vector<int> sets[maxn];
vector<bool> leaders(maxn, true);
vector<bool> visited(maxn);

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sets[i].push_back(i);
    }
}

void join(int u, int v){
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        if(sets[leaderV].size() > sets[leaderU].size())
            swap(leaderU, leaderV);
        
        for(int i = 0; i < sets[leaderV].size(); i++){
            int v = sets[leaderV][i];
            leader[v] = leaderU;
            sets[leaderU].push_back(v);
        }
        sets[leaderV].clear();
        leaders[leaderV] = 0;
        components--;
    }
}

void DFS(int s){
    visited[s] = 1;
    for(int v : graph[s]){
        if(!visited[v]){
            join(s, v);
            DFS(v);
        }
    }
}

void DFS2(int s){
    visited[s] = 1;
    for(int v : graph[s]){
        if(!visited[v]){
            cout<<s<<' '<<v<<endl;
            DFS2(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m, d; cin>>n>>m>>d;
    initDSU(n);
    for(int i = 0; i < m; i++){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visited[1] = 1;
    for(int u : graph[1])
        DFS(u);
    components--;
    if(components > d || graph[1].size() < d){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    for(int i = 2; i <= n; i++)visited[i] = 0;
    int used = 0;
    for(int u : graph[1]){
        if(leaders[u]){
            visited[u] = 1;
            used++;
            cout<<"1 "<<u<<endl;
        }
    }
    for(int u : graph[1]){
        if(used == d)break;
        if(!leaders[u]){
            visited[u] = 1;
            used++;
            cout<<"1 "<<u<<endl;
        }
    }
    for(int u : graph[1])
        DFS2(u);
    return 0;
}