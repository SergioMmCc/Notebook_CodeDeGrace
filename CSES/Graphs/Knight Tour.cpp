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
typedef pair<int, pii> piii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int n = 8;
vector<vector<vector<pii>>> moves(n + 1, vector<vector<pii>>(n + 1));
vector<pii> add(8);
void calcAdd(){
    add[0] = {-1, -2};
    add[1] = {-1, 2};
    add[2] = {1, -2};
    add[3] = {1, 2};
    add[4] = {-2, -1};
    add[5] = {-2, 1};
    add[6] = {2, -1};
    add[7] = {2, 1};
}
void calcMoves(){
    calcAdd();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(pii move : add){
                int auxi = i + move.fi, auxj = j + move.se;
                if(auxi > 0 && auxi <= n && auxj > 0 && auxj <= n) moves[i][j].pb({auxi, auxj});
            }
        }
    }
}

int calcValid(vector<vector<int>>& vis, pii pos){
    int count = 0;
    for(pii move : moves[pos.fi][pos.se]){
        if(!vis[move.fi][move.se]) count++;
    }
    return count;
}

bool bt(vector<vector<int>>& vis, pii last){
    if(vis[last.fi][last.se] == n * n) return 1;
    
    vector<piii> orden;
    for(pii move : moves[last.fi][last.se]){
        orden.pb({calcValid(vis, move), move});
    }
    sort(orden.begin(), orden.end());
    
    bool cond = 0;
    for(int i = 0; !cond && i < orden.sz; i++){
        int y = orden[i].se.fi, x = orden[i].se.se;
        if(vis[y][x]) continue;
        vis[y][x] = vis[last.fi][last.se] + 1;
        cond = bt(vis, {y, x});
        if(!cond) vis[y][x] = 0;
    }
    
    return cond;
}

void solver(){
    int x, y; cin>>x>>y;
    vector<vector<int>> vis(n+1, vector<int>(n+1)); vis[y][x] = 1;
    bt(vis, {y, x}); 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<vis[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calcMoves();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}