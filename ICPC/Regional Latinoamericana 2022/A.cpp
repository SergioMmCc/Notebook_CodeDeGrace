#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll = long long;
using ld = long double;

typedef pair<int, int> pii;
vector<pii> ask(1005);
vector<int> graph[1005];

void BFS(int n, int source, int skip, vector<int>& visited){
    visited[source]++;
    vector<bool> visitedAux(n + 1);
    visitedAux[source] = 1;
    queue<int> q;
    q.push(source);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : graph[u]){
            if(v == skip)continue;
            if(!visitedAux[v]){
                visitedAux[v] = 1;
                visited[v]++;
                q.push(v);
            }
        }
    }
}

void solver(){
    queue<int> q;
    int n;cin>>n;
    for(int i = 1; i <= n ; i++){
        int x, y;cin>>x>>y;
        ask[i] = {x, y};
        graph[x].push_back(i); graph[y].push_back(i);
    }
   
    for(int i = 1; i <= n; i++){
        vector<int> visited(n+1);
        int x = ask[i].first, y = ask[i].second;
        BFS(n, i, -1, visited);
        BFS(n, x, i, visited);
        BFS(n, y, i, visited);
        bool cond = false;
        for(int j = 1; !cond && j <= n; j++){
            if(visited[j] == 3){
                cout<<'Y';
                cond = 1;
            }
        }
        if(!cond)cout<<'N';
    }
    cout<<endl;
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