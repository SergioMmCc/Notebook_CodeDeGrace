#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 55;
char maze[maxn][maxn];
bool visited[maxn][maxn];
typedef pair<int, int> pii;
vector<pii> movements(4);

void initializeMovements(){
    movements[0] = {-1, 0};
    movements[1] = {1, 0};
    movements[2] = {0, -1};
    movements[3] = {0, 1};
}

bool close(int i, int j, int n, int m){
    for(int k = 0; k < 4; k++){
        int xf = j + movements[k].first;
        int yf = i + movements[k].second;

        if(xf < 0 || yf < 0 || yf >= n || xf >= m || maze[yf][xf] == 'B') continue;
        if(maze[yf][xf] == 'G') return 0;
        maze[yf][xf] = '#';
    }

    return 1;
}

void BFS(int n, int m){
    queue<pii> q;
    q.push({n-1, m-1});
    visited[n-1][m-1] = 1;

    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int xf = j + movements[k].first;
            int yf = i + movements[k].second;

            if(xf < 0 || yf < 0 || yf >= n || xf >= m || visited[yf][xf] || maze[yf][xf] == '#') continue;
            visited[yf][xf] = 1;
            q.push({yf, xf});
        }
    }
}

void solver(){
    // Read
    int n, m; cin>>n>>m;
    for(int i = 0; i < n; i++){
        string save; cin>>save;
        for(int j = 0; j < m; j++){
            maze[i][j] = save[j];
        }
    }

    // Encerrar las celdas 'B'
    bool cond = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 'B'){
                cond = close(i, j, n, m);
                if(!cond){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }

    // BFS a la celda "n-1, m-1"
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = 0;
        }
    }
    if(maze[n - 1][m - 1] == '#'){
        for(int i = 0; cond && i < n; i++){
            for(int j = 0; cond && j < m; j++){
                if(maze[i][j] == 'G') cond = 0;
            }
        }
    }
    else{
        BFS(n, m);
        for(int i = 0; cond && i < n; i++){
            for(int j = 0; cond && j < m; j++){
                if(maze[i][j] == 'G' && !visited[i][j]) cond = 0;
            }
        }
    }

    if(cond) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    initializeMovements();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}