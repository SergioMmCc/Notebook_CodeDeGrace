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
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
        }
    }

    int r, s; cin>>r>>s;
    int w = m - s + 1, h = n - r + 1;
    vector<vector<int>> comprimir(n, vector<int>(w));
    for(int i = 0; i < n; i++){
        deque<pii> q;
        for(int j = 0; j < s - 1; j++){
            while(!q.empty() && q.back().fi <= mat[i][j]) q.pop_back();
            q.pb({mat[i][j], j});
        }
        for(int j = s - 1, l = 0; j < m; j++, l++){
            while(!q.empty() && q.back().fi <= mat[i][j]) q.pop_back();
            q.pb({mat[i][j], j});
            comprimir[i][l] = q.front().fi;
            if(q.front().se == l) q.pop_front();
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < w; j++){
    //         cout<<comprimir[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    vector<vector<int>> ans(h, vector<int>(w));
    for(int j = 0; j < w; j++){
        deque<pii> q;
        for(int i = 0; i < r - 1; i++){
            while(!q.empty() && q.back().fi <= comprimir[i][j]) q.pop_back();
            q.pb({comprimir[i][j], i});
        }
        for(int i = r - 1, u = 0; i < n; i++, u++){
            while(!q.empty() && q.back().fi <= comprimir[i][j]) q.pop_back();
            q.pb({comprimir[i][j], i});
            ans[u][j] = q.front().fi;
            if(q.front().se == u) q.pop_front();
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(j) cout<<' ';
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}