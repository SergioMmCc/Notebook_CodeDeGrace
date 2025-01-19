#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2002, inf = 2e9;
char maze[maxn][maxn];
int d[maxn][maxn];
vector<pii> movements(4);

void initializeMovements(){
    movements[0] = {0, -1};
    movements[1] = {0, 1};
    movements[2] = {-1, 0};
    movements[3] = {1, 0};
}

void BFS(int r, int c, int n, int m){
    d[r][c] = 0;
    deque<pii> q; q.push_front({r, c});
    while(!q.empty()){
        int ux = q.front().second, uy = q.front().first; q.pop_front();
        for(int i = 0; i < 4; i++){
            int vx = ux + movements[i].second, vy = uy + movements[i].first;
            if(vx < 0 || vx >= m || vy < 0 || vy >= n || maze[vy][vx] == '*') continue;
            int add = 0;
            // if(condicion) add++;
            if(d[vy][vx] > d[uy][ux] + add){
                d[vy][vx] = d[uy][ux] + add;
                if(!add) q.push_front({vy, vx});
                else q.push_back({vy, vx});
            }
        }
    }
}

void solver(){
    int n, m, r, c, x, y; cin>>n>>m>>r>>c>>x>>y; r--; c--;
    for(int i = 0; i < n; i++) cin>>maze[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            d[i][j] = inf;
        }
    }

    BFS(r, c, n, m);
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