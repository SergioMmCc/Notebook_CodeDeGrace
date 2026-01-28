#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int x, n, m; cin>>x>>n>>m; // n -> piso, m -> techo
    m = min(m, 32);
    n = min(n, 32);

    int maxi = x;
    for(int i = 0; i < n; i++) maxi /= 2;
    for(int i = 0; i < m; i++) maxi = (maxi + 1) / 2;

    int mini = x;
    for(int i = 0; i < m; i++) mini = (mini + 1) / 2;
    for(int i = 0; i < n; i++) mini /= 2;

    cout<<mini<<' '<<maxi<<endl;
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