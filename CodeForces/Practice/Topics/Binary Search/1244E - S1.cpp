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
    int n, k; cin>>n>>k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    int ans = a[n] - a[1];
    
    // Testear con L en a
    vector<int> ps(n+1);
    for(int i = 1; i <= n; i++) ps[i] = ps[i-1] + a[i];
    int carried = 0; // Cuanto he gastado ya
    for(int i = 1; i <= n; i++){
        carried += (a[i] - a[i-1]) * (i - 1);
        if(carried > k) break;
        int L = a[i], l = 0, r = a[n] - L;

        // BinarySearch para ubicar R
        while(l < r){
            int m = (l + r) / 2;
            vector<int>::iterator it = upper_bound(a.begin(), a.end(), m + L);
            int index = distance(a.begin(), it);

            int test = ps[n] - ps[index-1] - (n - index + 1) * (m + L);
            test += carried;
            if(test > k) l = m+1;
            else r = m;
        }

        ans = min(ans, r);
    }

    //Testear con R en a
    carried = 0;
    for(int i = n; i > 0; i--){
        if(i < n)carried += (a[i+1] - a[i]) * (n-i);
        if(carried > k) break;
        int R = a[i], l = 0, r = R - a[1];

        // BinarySearch para ubicar L
        while(l < r){
            int m = (l + r) / 2;
            vector<int>::iterator it = lower_bound(a.begin(), a.end(), R - m);
            int index = distance(a.begin(), it); index--;
            int test = index * (R - m) - ps[index];
            test += carried;
            if(test > k) l = m+1;
            else r = m;
        }

        ans = min(ans, r);
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