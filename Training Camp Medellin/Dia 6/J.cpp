#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int INF=1E9, MOD=1E9+7;

vector<pair<int,int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int n, m; 

bool limits(int x, int y){
    return (x >= 0 && x < m && y >= 0 && y < n);
}

char col[2] = {'R', 'W'};

void solve(){
    cin>>n>>m;
    vector<vector<char>> vec(n, vector<char>(m));
    bool emp = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>vec[i][j];
            emp |= (vec[i][j] != '.');
        }
    }

    if(!emp){
        vec[0][0] = col[0];
    }

    for(int t=0; t<=n+m+50; t++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vec[i][j] != '.'){
                    for(auto [dx, dy]: moves){
                        int x = j + dx, y = i + dy;
                        if(!limits(x, y)) continue;
                        if(vec[y][x] == vec[i][j]){
                            cout<<"NO\n";
                            return;
                        }else{
                            vec[y][x] = col[(vec[i][j] == col[0])];
                        }
                    }
                }
            }
        }
    }

    cout<<"YES\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
}

int main() {
    //ios::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}