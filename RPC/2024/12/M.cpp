#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define ps push_back
#define sz size()

#define int long long
int const inf = 1e18;

void solver(){
    int n; cin>>n;
    vector<int> a(n);
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i] -= i;
        totalSum += a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int ans = inf;
    int upSum = 0, downSum = totalSum;
    for(int i = 0; i < n; i++){
        downSum -= a[i];

        int aux = upSum - a[i] * i - downSum + a[i] * (n - i - 1);
        ans = min(ans, aux);

        // Al final de la iteracion
        upSum += a[i];
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}