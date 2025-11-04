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

void solver(){
    int n, m; cin>>n>>m;
    vector<string> z(n);
    for(int i = 0; i < n; i++) cin>>z[i];

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<(int)z[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    int maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(z[i][j] != '+') continue;

            int larg = n + m;

            // Arriba
            int count = 0;
            for(int u = i - 1, v = j; u >= 0; u--){
                if(z[u][v] != '|') break;
                count++;
            }
            larg = min(larg, count);
            // cout<<"arriba -> "<<larg<<endl;

            // Abajo
            count = 0;
            for(int u = i + 1, v = j; u < n; u++){
                if(z[u][v] != '|') break;
                count++;
            }
            larg = min(larg, count);
            // cout<<"abajo -> "<<larg<<endl;

            // Izquierda
            count = 0;
            for(int u = i, v = j - 1; v >= 0; v--){
                if(z[u][v] != '-') break;
                count++;
            }
            larg = min(larg, count);
            // cout<<"izquierda -> "<<larg<<endl;

            // Derecha
            count = 0;
            for(int u = i, v = j + 1; v < m; v++){
                if(z[u][v] != '-') break;
                count++;
            }
            larg = min(larg, count);
            // cout<<"derecha -> "<<larg<<endl;

            // Diag izq upp
            count = 0;
            for(int u = i - 1, v = j - 1; u >= 0 && v >= 0; u--, v--){
                if((int)z[u][v] != 92) break;
                count++;
            }
            larg = min(larg, count);
            // cout<<"izq upp -> "<<larg<<endl;

            // Diag der down
            count = 0;
            for(int u = i + 1, v = j + 1; u < n && v < m; u++, v++){
                if((int)z[u][v] != 92) break;
                count++;
            }
            larg = min(larg, count);
            // cout<<"der dow -> "<<larg<<endl;

            // Diag izq down
            count = 0;
            for(int u = i + 1, v = j - 1; u < n && v >= 0; u++, v--){
                if((int)z[u][v] != 47) break;
                count++;
            }
            larg = min(larg, count);
            // cout<<"izq dow -> "<<larg<<endl;

            // Diag der upp
            count = 0;
            for(int u = i - 1, v = j + 1; u >= 0 && v < m; u--, v++){
                if((int)z[u][v] != 47) break;
                count++;
            }
            larg = min(larg, count);

            maxi = max(maxi, larg);
            // cout<<"larg -> "<<larg<<endl;
        }
    }

    cout<<maxi<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}