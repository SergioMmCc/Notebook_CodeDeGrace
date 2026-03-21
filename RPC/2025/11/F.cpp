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

vector<pii> moves(4);
void calcMoves(){
    moves[0] = {1, 0};
    moves[1] = {0, 1};
    moves[2] = {-1, 0};
    moves[3] = {0, -1};
}

bool check(int m, vector<vector<int>>& d, int r, int c){
    if(d[0][0] < m) return 0;
    queue<pii> q; q.push({0, 0});
    vector<vector<bool>> vis(r, vector<bool>(c));
    while(!q.empty()){
        int uy = q.front().fi, ux = q.front().se; q.pop();
        for(pii move : moves){
            int vy = uy + move.fi, vx = ux + move.se;
            if(vy < 0 || vy >= r || vx < 0 || vx >= c || vis[vy][vx] || d[vy][vx] < m) continue;
            vis[vy][vx] = 1;
            q.push({vy, vx});
        }
    }

    return vis[r-1][c-1];
}

void solver(){
    int r, c; cin>>r>>c;
    vector<string> maze(r);
    for(int i = 0; i < r; i++) cin>>maze[i];

    vector<vector<int>> d(r, vector<int>(c));
    vector<vector<bool>> vis(r, vector<bool>(c));
    queue<pii> q;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(maze[i][j] == 'W'){
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        int uy = q.front().fi, ux = q.front().se; q.pop();
        for(pii move : moves){
            int vy = uy + move.fi, vx = ux + move.se;
            if(vy < 0 || vy >= r || vx < 0 || vx >= c || vis[vy][vx]) continue;
            vis[vy][vx] = 1;
            d[vy][vx] = d[uy][ux] + 1;
            q.push({vy, vx});
        }
    }

    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j++){
    //         cout<<d[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    int i = 0, j = 3000, ans = 0;
    while(i <= j){
        int m = (i + j) / 2;
        bool cond = check(m, d, r, c);
        if(cond){
            i = m + 1;
            ans = m;
        }
        else j = m - 1;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    calcMoves();
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}