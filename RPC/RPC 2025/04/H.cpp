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
    int n, m; cin>>n>>m;
    if(m > n){
        cout<<10 * n<<endl;
        return;
    }
    
    int ans = 10 * m;
    n -= m;
    ans += 10 * (n / 3);
    n %= 3;
    if(n == 2) ans += 3;
    else if(n == 1) ans += 1;
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