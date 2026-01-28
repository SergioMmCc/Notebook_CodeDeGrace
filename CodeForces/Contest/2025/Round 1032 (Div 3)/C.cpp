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

void solver(){
    int n, m; cin>>n>>m;
    int table[n+1][m+1];

    int maxi = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>table[i][j];
            maxi = max(maxi, table[i][j]);
        }
    }

    vector<pii> pos;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(table[i][j] == maxi) pos.pb({i, j});
        }
    }

    bool cond = 1;
    int col = pos[0].se, row = -1;
    // Probar columna
    for(int i = 1; cond && i < pos.sz; i++){
        if(pos[i].se == col) continue;
        if(row == -1) row = pos[i].fi;
        else if(row != pos[i].fi) cond = 0;
    }

    if(cond){
        cout<<maxi-1<<endl;
        return;
    }

    cond = 1;
    col = -1; row = pos[0].fi;
    // Probar fila
    for(int i = 1; cond && i < pos.sz; i++){
        if(pos[i].fi == row) continue;
        if(col == -1) col = pos[i].se;
        else if(col != pos[i].se) cond = 0;
    }

    cout<<(cond ? maxi - 1 : maxi)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}