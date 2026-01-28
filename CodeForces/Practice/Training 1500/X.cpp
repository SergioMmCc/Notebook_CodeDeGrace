#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n, m, k; cin>>n>>m>>k;
    int len = n + m - 2;
    if(k < len || (k - len) % 2){ // Si k no alcanza o se necesitan ciclos impares
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;

    bool horizontal[n + 1][m], vertical[n][m + 1];

    // Inicializar los colores en 0 (blue)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){
            horizontal[i][j] = 0;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            vertical[i][j] = 0;
        }
    }

    if(k == n + m){ // Caso especial
        horizontal[2][1] = 1;
        for(int j = 2; j < m; j += 2){
            horizontal[1][j] = 1;
        }

        for(int i = horizontal[1][m - 1] + 1; i < n; i += 2){
            vertical[i][m] = 1;
        }
    }

    else{
        for(int i = 1; i <= n; i++){
            for(int j = 2; j < m; j += 2){
                horizontal[i][j] = 1;
            }
        }

        vertical[1][1] = vertical[1][2] = 1;
        for(int i = horizontal[1][m - 1] + 1; i < n; i += 2){
            vertical[i][m] = 1;
        }
    }

    // Imprimir respuesta 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){
            cout<<((j > 1) ? " " :  "");
            cout<<((horizontal[i][j]) ? "R" : "B");
        }
        cout<<endl;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            cout<<((j > 1) ? " " :  "");
            cout<<((vertical[i][j]) ? "R" : "B");
        }
        cout<<endl;
    }
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