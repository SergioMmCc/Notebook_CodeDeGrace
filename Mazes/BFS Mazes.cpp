#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

typedef pair<int, int> pii;
const int maxn = 1e3+5, inf = 2e9;

void BFS(int sx, int sy, int n, int m, string maze[], int d[][maxn], bool visited[][maxn]){
    d[sy][sx] = 0;
    visited[sy][sx] = 1;
    queue<pii> q;
    q.push({sy, sx});

    while(!q.empty()){
        pii u = q.front(); q.pop();
        int j = u.first, i = u.second;
        if(i - 1 >= 0 && !visited[j][i-1] && maze[j][i-1] != '#'){
            visited[j][i-1] = 1; 
            d[j][i-1] = d[j][i] + 1;
            q.push({j, i-1});
        }
        if(i + 1 < m && !visited[j][i+1] && maze[j][i+1] != '#'){
            visited[j][i+1] = 1; 
            d[j][i+1] = d[j][i] + 1;
            q.push({j, i+1});
        }
        if(j - 1 >= 0 && !visited[j-1][i] && maze[j-1][i] != '#'){
            visited[j-1][i] = 1; 
            d[j-1][i] = d[j][i] + 1;
            q.push({j-1, i});
        }
        if(j + 1 < n && !visited[j+1][i] && maze[j+1][i] != '#'){
            visited[j+1][i] = 1; 
            d[j+1][i] = d[j][i] + 1;
            q.push({j+1, i});
        }
    }
}

void solver(){
    string maze[maxn];
    int d[maxn][maxn];
    bool visited[maxn][maxn];
    int n, m, sx, sy; cin>>n>>m;
    for(int j = 0; j < n; j++) {
        string aux; cin>>aux;
        for(int i = 0; i < m; i++){
            if(aux[i] == '@'){
                sx = i;
                sy = j;
                aux[i] = '.';
            }
        }
        maze[j] = aux;
    }
    
    for(int j = 0; j <= n + 1; j++){
        for(int i = 0; i <= m + 1; i++){
            d[j][i] = inf;
            visited[j][i] = 0;
        }
    }
    
    BFS(sx, sy, n, m, maze, d, visited);
    
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++)
            cout<<d[j][i]<<'\t';
        cout<<endl;
    }

    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++)
            cout<<visited[j][i]<<'\t';
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    for(int i = 1; i <= t; i++){
        solver();
    }

    return 0;
}