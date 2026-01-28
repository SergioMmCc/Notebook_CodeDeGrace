#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 201;
const ll inf = 1e15;
ll matriz[maxn][maxn], dp[maxn][maxn];
ll table[maxn][maxn][maxn], tableClean[maxn][maxn][maxn], tableOrder[maxn][maxn][maxn];

void fillTable(ll n, ll m, ll k){
    for(int i = 1; i <= n; i++){
        for(int jl = 1; jl <= m; jl++){
            ll sum = 0; 
            for(int len = 1; len <= m; len++){
                int jr = jl + len - 1;
                if(jr > m) jr -= m;
                sum += matriz[i][jr];
                table[i][jl][len] = sum;
            }
        }

        for(int len = 1; len <= m; len++){
            ll minVal = inf; int minIndex = 0;
            for(int jl = 1; jl <= m; jl++){
                if(table[i][jl][len] < minVal){
                    minVal = table[i][jl][len];
                    minIndex = jl;
                }
            }

            tableClean[i][minIndex][len] = minVal;
            for(int jlAux = minIndex - 1, count = 1; count <= m; count++, jlAux--){
                if(!jlAux) jlAux = m;
                minVal = min(minVal + k, table[i][jlAux][len]);
                tableClean[i][jlAux][len] = minVal;
            }

            for(int jl = 1; jl <= m; jl++){
                int jr = jl + len - 1;
                if(jr > m) jr -= m;
                tableOrder[i][jl][jr] = tableClean[i][jl][len];
            }
        }
    }
}

ll calc(int n, int m, int i, int j){
    if(dp[i][j] != inf) return dp[i][j];

    if(i == 1) dp[i][j] = tableOrder[i][1][j];
    else{
        for(int k = j; k > 0; k--) dp[i][j] = min(dp[i][j], tableOrder[i][k][j] + calc(n, m, i - 1, k));
    }
    
    return dp[i][j];
}

void solver(){
    ll n, m, k; cin>>n>>m>>k;

    // Limpiar dp
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = inf;
        }
    }

    // Lectura de la matriz
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>matriz[i][j];
        }
    }

    fillTable(n, m, k);

    ll ans = inf;
    ans = calc(n, m, n, m);
    cout<<ans<<endl;
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