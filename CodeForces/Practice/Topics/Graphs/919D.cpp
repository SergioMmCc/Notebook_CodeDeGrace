#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 3e5 + 1, letters = 27;
int dp[maxn][letters];
vector<vector<int>> inGraph(maxn), outGraph(maxn);
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
        for(int v : inGraph[u]){
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
    string word; cin>>word;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < letters; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        inGraph[u].pb(v);
        outGraph[v].pb(u);
        inDegree[v]++;
    }

    vector<int> orden;
    topoSort(n, orden);
    if(orden.sz < n){
        cout<<-1<<endl;
        return;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int v = orden[i];
        for(int j = 0; j < letters; j++){
            for(int u : outGraph[v]){
                dp[v][j] = max(dp[v][j], dp[u][j]);
            }
            if(j == word[v - 1] - 'a') dp[v][j]++;
            ans = max(ans, dp[v][j]);
        }
    }

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