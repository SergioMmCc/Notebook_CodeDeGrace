#include "../template.h"

// 1-index.
// Complejidad: o(n^2).
const int maxn = 1001;
int a[maxn][maxn];
ll s[maxn][maxn];

void solver(){
    int n, m; cin>>n>>m;
    
    // La formula para calcular cada termino es:
    // S[i][j] = A[i][j] + S[i−1][j] + S[i][j−1] − S[i−1][j−1]
    for1(i,n){
        for1(j,m){
            cin>>a[i][j];
            s[i][j] = (ll)a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    // Para consultar cada rectangulo:
    // y2 >= y1, x2 >= x1.
    // rectangulo = S[y2​][x2​] − S[y1​−1][x2​] − S[y2​][x1​−1] + S[y1​−1][x1​−1]
    int q; cin>>q;
    while(q--){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        cout<<s[y2][x2] - s[y1-1][x2] - s[y2][x1-1] + s[y1-1][x1-1]<<endl;
    }
}
