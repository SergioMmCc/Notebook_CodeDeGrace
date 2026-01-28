#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

const int maxn = 1002, inf = 2e9;
char maze[maxn][maxn];
int d[maxn][maxn];
vector<pii> movements(4);

void initializeMovements(){
    movements[0] = {0, -1};
    movements[1] = {0, 1};
    movements[2] = {-1, 0};
    movements[3] = {1, 0};
}

int BFS(int x1, int y1, int x2, int y2, int n, int m, int k){
    d[y1][x1] = 0;
    queue<ppi> q; q.push({{y1, x1}, -1});
    set<ppi> viewed;
    while(!q.empty()){
        int uy = q.front().first.first, ux = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(i == dir) continue; // Si es la misma direccion por la que viene, sigo
            for(int j = 1; j <= k; j++){
                int dir = i;
                int vx = ux + movements[i].second * j, vy = uy + movements[i].first * j;
                if(vx < 0 || vx >= m || vy < 0 || vy >= n || maze[vy][vx] == '#') break;
                
                if(j == k) dir = -1;
                if(d[vy][vx] >= d[uy][ux] + 1){
                    if(viewed.find({{vy, vx}, dir}) != viewed.end()) continue;
                    viewed.insert({{vy, vx}, dir});
                    d[vy][vx] = d[uy][ux] + 1;
                    q.push({{vy, vx}, dir});
                }
                else break;
            }
        }
    }

    return d[y2][x2];
}

void solver(){
    int n, m, k; cin>>n>>m>>k;
    for(int i = 0; i < n; i++) cin>>maze[i];
    int x1, y1, x2, y2; cin>>y1>>x1>>y2>>x2; x1--; y1--; x2--; y2--;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            d[i][j] = inf;
        }
    }

    int ans = BFS(x1, y1, x2, y2, n, m, k);
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