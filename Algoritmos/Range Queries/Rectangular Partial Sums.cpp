#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1001;
int a[maxn][maxn];
ll s[maxn][maxn];

void solver(){
    int n, m; cin>>n>>m;
    
    // La formula para calcular cada termino es:
    // S[i][j] = A[i][j] + S[i−1][j] + S[i][j−1] − S[i−1][j−1]
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            s[i][j] = (ll)a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    // Para consultar cada rectangulo:
    // (y1, x1) es la esquina superior izquierda
    // (y2, x2) es la esquina inferior derecha
    // rectangulo = S[y2​][x2​] − S[y1​−1][x2​] − S[y2​][x1​−1] + S[y1​−1][x1​−1]
    int q; cin>>q;
    while(q--){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        cout<<s[y2][x2] - s[y1-1][x2] - s[y2][x1-1] + s[y1-1][x1-1]<<endl;
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