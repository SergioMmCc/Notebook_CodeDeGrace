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

const int maxn = 1001;
char maze[maxn][maxn];
bool visited[maxn][maxn];
pii leader[maxn][maxn];
int ans[maxn][maxn];


vector<pii> movements(4);
void initializeMovements(){
    movements[0] = {0, -1};
    movements[1] = {0, 1};
    movements[2] = {-1, 0};
    movements[3] = {1, 0};
}

void BFS(int xs, int ys){
    visited[xs][ys] = 1;
    leader[xs][ys] = {xs, ys};
    queue<pii> q; q.push({xs, ys});

    while(!q.empty()){
        int xu = q.front().fi, yu = q.front().se; q.pop();

        for(int i = 0; i < 4; i++){
            int xv = xu + movements[i].fi, yv = yu + movements[i].se;

            if(maze[xv][yv] == '*'){
                ans[xs][ys]++;
                continue;
            }

            if(visited[xv][yv]) continue;
            visited[xv][yv] = 1;
            q.push({xv, yv});
            leader[xv][yv] = {xs, ys};
        }
    }
}

void solver(){
    int n, m, k; cin>>n>>m>>k;
    
    for(int i = 1; i <= n; i++){
        string save; cin>>save;
        for(int j = 0; j < m; j++){
            maze[i][j+1] = save[j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(maze[i][j] == '.' && !visited[i][j]) BFS(i, j);
        }
    }

    while(k--){
        int x, y; cin>>x>>y;
        cout<<ans[leader[x][y].fi][leader[x][y].se]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    initializeMovements();
    solver();

    return 0;
}