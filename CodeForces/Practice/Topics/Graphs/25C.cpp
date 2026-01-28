#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    int d[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>d[i][j];
        }
    }

    int k; cin>>k;
    while(k--){
        int u, v, w; cin>>u>>v>>w;
        if(d[u][v] > w){
            d[u][v] = d[v][u] = w;
            for(int i = 1; i <= n; i++){
                d[u][i] = d[i][u] = min(d[i][u], d[i][v] + d[v][u]);
                d[v][i] = d[i][v] = min(d[i][v], d[i][u] + d[u][v]);
            }

            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    d[i][j] = min(d[i][j], min(d[i][u] + d[u][j], d[i][v] + d[v][j]));
                }
            }
        }

        ll total = 0;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                total += d[i][j];
            }
        }

        cout<<total<<' ';
    }

    cout<<endl;
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