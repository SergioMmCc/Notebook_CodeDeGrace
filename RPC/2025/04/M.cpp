#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define int long long
typedef pair<int, int> pii;

bool check(int n, int m, int k, vector<int>& a){
    int count = 0;
    for(int i = 0; i < n; i++){
        count += (a[i] + m - 1) / m;
    }

    return count > k ? 0 : 1;
}

void solver(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 1, r = 1e18, ans = 1e18;
    while(l <= r){
        int m = (l + r) / 2;
        bool cond = check(n, m, k, a);
        if(cond){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    cout<<ans<<endl;
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