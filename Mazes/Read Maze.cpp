#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

const int maxn = 1e3+5;
string maze[maxn];

void solver(){
    int n, m; cin>>n>>m; // n rows, m columns
    
    /* En este caso, queremos que el laberinto sea 0-index
    por lo tanto, llenaremos los bordes con "-" */
    string add;
    for(int i = 0; i <= m + 1; i++)add += '-';
    maze[0] = add;
    for(int j = 1; j <= n; j++) {
        string aux; cin>>aux;
        maze[j] = "-" + aux + "-";
    }
    maze[n+1] = add;

    /* En este caso el laberinto sera 0-index y tendra una source identificada como '@' */
    for(int j = 0; j < n; j++) {
        string aux; cin>>aux;
        for(int i = 0; i < m; i++){
            if(aux[i] == '@'){
                sx = i;
                sy = j;
                aux[i] = '.';
            }
        }
        maze[j] = aux;
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