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

vector<string> mat(2500);

bool check(int k, int n, int m, int count){
    vector<vector<bool>> vis(n, vector<bool>(m));
    int aux = 0;
    bool cond = 1;
    for(int i = 0; cond && i + k <= n; i++){
        for(int j = 0; cond && j + k <= m; j++){
            if(mat[i][j] == '.' || vis[i][j]) continue;

            // Revisar
            for(int y = i; cond && y < i + k; y++){
                for(int x = j; cond && x < j + k; x++){
                    if(vis[y][x] || mat[y][x] == '.')
                        cond = 0;

                    else{
                        aux++;
                        vis[y][x] = 1;
                    }
                }
            }
        }
    }

    // if(k == 5) cout<<"aux -> "<<aux<<endl;
    return cond && aux == count;
}

void solver(){
    int n, m; cin>>n>>m;
    int count = 0;
    for(int i = 0; i < n; i++){
        cin>>mat[i];
        for(int j = 0; j < m; j++){
            if(mat[i][j] == '#') count++;
        }
    }

    vector<int> div;
    for(int i = count; i; i--){
        if(count % i == 0){
            int r = sqrt(i);
            if(r * r == i){
                div.pb(r);
                // cout<<r<<endl;
            }
        }
    }

    for(int i : div){
        if(check(i, n, m, count)){
            cout<<i<<endl;
            return;
        }
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