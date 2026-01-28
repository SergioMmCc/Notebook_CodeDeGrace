#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
const int maxn = 1002, inf = 1e8;
char maze[maxn][maxn];
int d[3][maxn][maxn];
vector<pii> movements(4);

void initializeMovements(){
    movements[0] = {0, -1};
    movements[1] = {0, 1};
    movements[2] = {-1, 0};
    movements[3] = {1, 0};
}

void BFS(int y, int x, int n, int m, int s){
    int ans = inf;
    d[s][y][x] = 0;
    deque<pii> q; q.push_front({y, x});
    while(!q.empty()){
        int uy = q.front().first, ux = q.front().second; q.pop_front();
        for(int i = 0; i < 4; i++){
            int add = 0;
            int vy = uy + movements[i].first, vx = ux + movements[i].second;
            if(vy < 0 || vy >= n || vx < 0 || vx >= m || maze[vy][vx] == '#') continue;
            if(maze[vy][vx] == '.') add = 1;
            if(d[s][vy][vx] > d[s][uy][ux] + add){
                d[s][vy][vx] = d[s][uy][ux] + add;
                if(!add) q.push_front({vy, vx});
                else q.push_back({vy, vx});
            }
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>maze[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            d[0][i][j] = d[1][i][j] = d[2][i][j] = inf;
        }
    }

    bool cond = 0;
    for(int i = 0; !cond && i < n; i++){
        for(int j = 0; !cond && j < m; j++){
            if(maze[i][j] == '1'){
                BFS(i, j, n, m, 0);
                cond = 1;
            }
        }
    }

    cond = 0;
    for(int i = 0; !cond && i < n; i++){
        for(int j = 0; !cond && j < m; j++){
            if(maze[i][j] == '2'){
                BFS(i, j, n, m, 1);
                cond = 1;
            }
        }
    }

    cond = 0;
    for(int i = 0; !cond && i < n; i++){
        for(int j = 0; !cond && j < m; j++){
            if(maze[i][j] == '3'){
                BFS(i, j, n, m, 2);
                cond = 1;
            }
        }
    }

    int ans = inf;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int sum = d[0][i][j] + d[1][i][j] + d[2][i][j];
            if(maze[i][j] == '.') sum -= 2;
            ans = min(ans, sum);
        }
    }

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