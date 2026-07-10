#include <bits/stdc++.h>
using namespace std;
int INF=-1e9;
#define int long long

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> vec(n+5);
    for(int i=1; i<=n; i++)cin>>vec[i];

    vector<int> dpa(n+5), dpb(n+5), pa(n+5), pb(n+5), upa(n+5), upb(n+5);
    pa[0] = 1;
    pb[n+1] = n;

    for(int i=1; i<=n; i++){
        dpa[i] = vec[i] + dpa[i-1];
        if(i-k >= 0) dpa[i] -= vec[i-k];

        if(dpa[i] > upa[i-1]){
            pa[i] = i;
            upa[i] = dpa[i];
        }else{
            pa[i] = pa[i-1];
            upa[i] = upa[i-1];
        }
    }

    for(int i=n; i>=1; i--){
        dpb[i] = vec[i] + dpb[i+1];
        if(i+k <=n) dpb[i] -= vec[i+k];

        if(dpb[i] >= upb[i+1]){
            pb[i] = i;
            upb[i] = dpb[i];
        }else{
            pb[i] = pb[i+1];
            upb[i] = upb[i+1];
        }
    } 

    int p1, p2;
    long long mx=0;
    for(int i=k; i<=n-k+1; i++){
        long long sum=0ll+upa[i-1]+upb[i];
        if(sum > mx){
            mx = sum;
            p1 = pa[i-1]-k+1;
            p2 = pb[i];
        }
    }
    cout<<p1<<" "<<p2<<"\n";
}

signed main() {
    solve();
    return 0;
}
