#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
#define int long long

void solver(){
    int x, y; cin>>x>>y;
    int k;
    if(y > 0) k = y + abs(x);
    else{
        k = -y + 1;
        int aux = (-4*y + 3) / 2;
        if(abs(x) > aux) k += abs(x) - aux;
    }
    
    int ans = 4 * (k - 1) * (k - 1); // Cuantos puntos habian antes de ese nivel
    int yaux = -k + 1, xaux = 2*k - 2; // Primer punto del nivel k
    
    // Si esta en la parte inferior
    if(yaux == y){
        if(x == 2*k - 1) ans = 4 * k * k;
        ans += xaux - x + 1;
        cout<<ans<<endl;
        return;
    }
    
    // Si esta en la diagonal izquierda
    ans += 4*k - 2;
    xaux -= 4*k - 3;
    if(x - xaux == y - yaux){
        ans += x - xaux;
        cout<<ans<<endl;
        return;
    }
    
    // Si esta en la diagonal derecha
    xaux += 2*k - 1;
    yaux += 2*k - 1;
    ans += 2*k - 1;
    ans += x - xaux;
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}