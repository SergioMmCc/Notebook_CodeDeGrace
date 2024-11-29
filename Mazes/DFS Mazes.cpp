#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 1005;
typedef pair<int, int> pii;
int tiempo;

void DFS_visit(int n, int m, string maze[], int d[][maxn], int f[][maxn], bool visited[][maxn], pii padre[][maxn], int j, int i){
    visited[j][i] = 1;
    tiempo++;
    d[j][i] = tiempo;
    
    if(i > 0 && maze[j][i-1] == '.' && !visited[j][i-1]){
        padre[j][i-1] = {j, i};
        DFS_visit(n, m, maze, d, f, visited, padre, j, i-1);
    }
    if(i < m - 1 && maze[j][i+1] == '.' && !visited[j][i+1]){
        padre[j][i+1] = {j, i};
        DFS_visit(n, m, maze, d, f, visited, padre, j, i+1);
    }
    if(j > 0 && maze[j-1][i] == '.' && !visited[j-1][i]){
        padre[j-1][i] = {j, i};
        DFS_visit(n, m, maze, d, f, visited, padre, j-1, i);
    }
    if(j < n - 1 && maze[j+1][i] == '.' && !visited[j+1][i]){
        padre[j+1][i] = {j, i};
        DFS_visit(n, m, maze, d, f, visited, padre, j+1, i);
    }
    
    tiempo++;
    f[j][i] = tiempo;
}

void DFS(int n, int m, string maze[], int d[][maxn], int f[][maxn], bool visited[][maxn], pii padre[][maxn]){
    tiempo = 0;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            visited[j][i] = 0;
            padre[j][i] = {-1, -1};
        }
    }
    
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            if(maze[j][i] == '.' && !visited[j][i])
                DFS_visit(n, m, maze, d, f, visited, padre, j, i);
        }
    }
}

void solver(){
    string maze[maxn];
    bool visited[maxn][maxn];
    pii padre[maxn][maxn];
    int d[maxn][maxn], f[maxn][maxn];
    int m, n;
    cin>>m>>n;
    for(int j = 0; j < n; j++){
        string aux; cin>>aux;
        maze[j] = aux;
    }
    
    DFS(n, m, maze, d, f, visited, padre);
    
    int q; cin>>q;
    while(q--){
        int y, x;cin>>y>>x;
        x--;y--;
        while(padre[y][x].first != -1 && padre[y][x].second != -1){
            int auxX = x, auxY = y;
            x = padre[auxY][auxX].second;
            y = padre[auxY][auxX].first;
        }
        
        int ans = (f[y][x] - d[y][x] + 1) / 2;
        cout<<ans<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    for(int i = 1; i <= t; i++){
        cout<<"Case "<<i<<':'<<endl;
        solver();
    }
    
    return 0;
}