#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 502;
const ll ninf = -1e18;
int a[maxn][maxn];
ll s[maxn][maxn];

void solver(){
    int n, m; cin>>n>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            s[i][j] = (ll)a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    ll ans = ninf;
    for(int i = 2; i < n; i++){
        for(int j = 2; j < m; j++){
            ll last = s[i+1][j+1] - s[i+1][j-2] - s[i-2][j+1] + s[i-2][j-2];
            last -= (ll)a[i][j] + (ll)a[i][j-1];
            ans = max(ans, last);
            int len = 2;
            while(i - len > 0 && i + len <= n && j - len > 0 && j + len <= m){
                ll newN = s[i+len][j+len] - s[i+len][j-1-len] - s[i-1-len][j+len] + s[i-1-len][j-1-len];                
                newN -= last + (ll)a[i-len+1][j-len];
                ans = max(ans, newN);
                last = newN;
                len++;
            }
        }
    }

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