#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

typedef pair<int, int> pii;
const int maxn = 1e3+5, inf = 2e9;
string maze[maxn];
int d[maxn][maxn];
bool visited[maxn][maxn];
queue<pii> q;

void BFS(int n, int m){
    while(!q.empty()){
        pii u = q.front(); q.pop();
        int j = u.first, i = u.second;
        if(i - 1 >= 0 && !visited[j][i-1]){
            visited[j][i-1] = 1; 
            d[j][i-1] = d[j][i] + 1;
            q.push({j, i-1});
        }
        if(i + 1 <= m+1 && !visited[j][i+1]){
            visited[j][i+1] = 1; 
            d[j][i+1] = d[j][i] + 1;
            q.push({j, i+1});
        }
        if(j - 1 >= 0 && !visited[j-1][i]){
            visited[j-1][i] = 1; 
            d[j-1][i] = d[j][i] + 1;
            q.push({j-1, i});
        }
        if(j + 1 <= n+1 && !visited[j+1][i]){
            visited[j+1][i] = 1; 
            d[j+1][i] = d[j][i] + 1;
            q.push({j+1, i});
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    string add;
    for(int i = 0; i <= m + 1; i++)add += '-';
    maze[0] = add;
    for(int j = 1; j <= n; j++) {
        string aux; cin>>aux;
        maze[j] = "-" + aux + "-";
    }
    maze[n+1] = add;
    for(int j = 0; j <= n + 1; j++){
        for(int i = 0; i <= m + 1; i++){
            if(maze[j][i] == '-'){d[j][i] = 0; visited[j][i] = 1; q.push({j, i});}
            else d[j][i] = inf;
        }
    }
    
    BFS(n, m);

    int ans = 0;
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= m; i++)
            ans = max(ans, d[j][i]);
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