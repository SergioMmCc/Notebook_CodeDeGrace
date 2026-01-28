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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    int eql = 1, eqr = 1, l = 0, r = n-1;
    int ans = a[n-1] - a[0];
    while(k > 0 && l < r){
        if(eql <= eqr){
            if((a[l+1] - a[l]) * eql <= k){
                k -= (a[l+1] - a[l]) * eql;
                l++;
                eql++;
            }
            else{
                int laux = a[l] + k / eql;
                ans = a[r] - laux;
                cout<<ans<<endl;
                return;
            }
        }

        else{
            if((a[r] - a[r-1]) * eqr <= k){
                k -= (a[r] - a[r-1]) * eqr;
                r--;
                eqr++;
            }
            else{
                int raux = a[r] - k / eqr;
                ans = raux - a[l];
                cout<<ans<<endl;
                return;
            }
        }
    }

    ans = a[r] - a[l];
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