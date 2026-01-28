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

void solver(){
    ll n, m, s; cin>>n>>m>>s;
    if(s == 1){
        cout<<n*m<<endl;
        return;
    }

    ll rows = n % s; if(!rows) rows += s;
    ll cols = m % s; if(!cols) cols += s;
    
    ll ans = rows * cols * ((n + s - 1) / s) * ((m + s - 1) / s);
    cout<<ans<<endl;
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