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

const ll inf = 1e9 + 1;

void solver(){
    int n; cin>>n;
    ll a[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
        }
    }

    int mid = (n + 1) / 2;

    ll uc = inf, dc = inf, lc = inf, rc = inf;
    for(int i = 1; i < mid; i++) uc = min(uc, a[i][mid]);
    for(int i = n; i > mid; i--) dc = min(dc, a[i][mid]);
    for(int j = 1; j < mid; j++) lc = min(lc, a[mid][j]);
    for(int j = n; j > mid; j--) rc = min(rc, a[mid][j]);

    ll ul = inf, ur = inf, dl = inf, dr = inf;
    for(int i = 1; i <= mid; i++){
        for(int j = 1; j <= mid; j++){
            ul = min(ul, a[i][j]);
        }
    }
    for(int i = 1; i <= mid; i++){
        for(int j = n; j >= mid; j--){
            ur = min(ur, a[i][j]);
        }
    }
    for(int i = n; i >= mid; i--){
        for(int j = 1; j <= mid; j++){
            dl = min(dl, a[i][j]);
        }
    }
    for(int i = n; i >= mid; i--){
        for(int j = n; j >= mid; j--){
            dr = min(dr, a[i][j]);
        }
    }

    ll ans = a[mid][mid];
    ans = min(ans, uc + dc);
    ans = min(ans, lc + rc);
    ans = min(ans, uc + dl + dr);
    ans = min(ans, dc + ul + ur);
    ans = min(ans, lc + ur + dr);
    ans = min(ans, rc + ul + dl);
    ans = min(ans, ul + ur + dl + dr);
    cout<<ans<<endl;
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