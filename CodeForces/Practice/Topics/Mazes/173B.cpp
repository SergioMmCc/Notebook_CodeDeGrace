#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

const int maxn = 1002, inf = 1e5;
char maze[maxn][maxn];
bool visited[4][maxn][maxn];
int d[maxn][maxn];
vector<pii> movements(4);

void initializeMovements(){
    movements[0] = {0, -1};
    movements[1] = {-1, 0};
    movements[2] = {0, 1};
    movements[3] = {1, 0};
}

int BFS(int n, int m){
    d[n-1][m] = -1;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= m; k++){
                visited[i][j][k] = 0;
            }
        }
    }
    visited[0][n-1][m] = 1;
    queue<ppi> q; q.push({{n-1, m}, -1});
    while(!q.empty()){
        int uy = q.front().first.first, ux = q.front().first.second;
        int w = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            for(int j = 1; ; j++){
                int vx = ux + movements[i].second * j, vy = uy + movements[i].first * j;
                if(vx < 0 || vx >= m || vy < 0 || vy >= n || visited[i][vy][vx]) break;
                visited[i][vy][vx] = 1;
                
                if(!vy && !vx && i){
                    if(maze[0][0] != '#') continue;
                    d[0][0] = min(d[0][0], w + 2);
                }
                else d[vy][vx] = min(d[vy][vx], w + 1);
                if(maze[vy][vx] == '#') q.push({{vy, vx}, d[vy][vx]});
            }
        }
    }

    return d[0][0];
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>maze[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            d[i][j] = inf;
        }
    }

    int ans = BFS(n, m);
    cout<<(ans == inf ? -1 : ans)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    initializeMovements();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}