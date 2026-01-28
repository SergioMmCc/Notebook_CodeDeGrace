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
    int n; cin>>n;
    int total = 2e9;
    while(n--){
        int a, b, c, d, e; cin>>a>>b>>c>>d>>e;
        int aux = 0;
        int x = min(a, b);
        aux += x;
        a -= x; b -= x;

        x = min(d, e);
        aux += x;
        d -= x; e -= x;

        x = min(a, min(c, e));
        aux += x;
        a -= x; c -= x; e -= x;

        x = min(d, min(c, b));
        aux += x;
        
        total = min(aux, total);
    }

    cout<<total<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}