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
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

vector<pii> nMove(8);
void calc(){
    nMove[0] = {-2, -1};
    nMove[1] = {-2, 1};
    nMove[2] = {2, -1};
    nMove[3] = {2, 1};
    nMove[4] = {-1, -2};
    nMove[5] = {-1, 2};
    nMove[6] = {1, -2};
    nMove[7] = {1, 2};
}

void solver(){
    int n, m; cin>>n>>m;
    vector<vector<bool>> vis(n+1, vector<bool> (n+1));
    for(int i = 0; i < m; i++){
        char a; int x, y; cin>>a>>x>>y;
        if(a == 'N'){
            vis[y][x] = 1;
            for(pii m : nMove){
                int u = y + m.fi, v = x + m.se;
                if(u > 0 && v > 0 && u <= n && v <= n) vis[u][v] = 1;
            }
        }
        else if(a == 'R'){
            for(int u = 1; u <= n; u++){
                vis[u][x] = 1;
                vis[y][u] = 1;
            }
        }
        else{
            for(int u = 1; u <= n; u++){
                vis[u][x] = 1;
                vis[y][u] = 1;
            }

            for(int u = y, v = x; u && v; u--, v--){
                vis[u][v] = 1;
            }
            for(int u = y, v = x; u <= n && v; u++, v--){
                vis[u][v] = 1;
            }
            for(int u = y, v = x; u <= n && v <= n; u++, v++){
                vis[u][v] = 1;
            }
            for(int u = y, v = x; u && v <= n; u--, v++){
                vis[u][v] = 1;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(vis[i][j]) ans++;
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calc();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}