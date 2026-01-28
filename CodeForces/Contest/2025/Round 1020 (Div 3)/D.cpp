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
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    vector<int> l(m, n), r(m, -1);
    for(int j = 0, i = 0; j < m; j++){
        while(i < n && a[i] < b[j]) i++;
        if(i < n){
            l[j] = i;
            i++;
        }
    }
    for(int j = m - 1, i = n - 1; j >= 0; j--){
        while(i >= 0 && a[i] < b[j]) i--;
        if(i >= 0){
            r[j] = i;
            i--;
        }
    }

    int ans = l[m-1] == n ? 2e9 : 0;
    for(int i = 0; i < m; i++){
        int mini = -1, maxi = n;
        if(i > 0) mini = l[i-1];
        if(i < m - 1) maxi = r[i+1];

        if(mini < maxi) ans = min(ans, b[i]);
    }

    cout<<(ans == 2e9 ? -1 : ans)<<endl;
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