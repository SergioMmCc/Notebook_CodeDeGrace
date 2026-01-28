#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

using ll = long long;

int binarySearch (vector<ll>& A, int i, int j, ll k) {
    int m;
    while (i <= j) {
        m = (i + j) >> 1;
        if (A[m] == k)
            return m;
        else if (k > A[m])
            i = m + 1;
        else
            j = m - 1;
    }
    return -i -1;
}

void solver() {
    int n;cin>>n;
    vector<ll> a(n+1), sum(2*n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++)
        sum[n+i] = sum[n+i-1] + a[i];
        
    ll ans = 0, total = sum[n];
    
    for(int i = 1; i <= n; i++){
        ll aux = a[i];
        int index = binarySearch(sum, i, 2*n, sum[i] + (total-aux)/2);
        if(index > 0)
            aux = min(sum[index], max(aux + sum[index] - sum[i], aux + sum[n+i-1] - sum[index+1]));
            
        else{
            index = -index - 1;
            ll test = max(sum[index - 1] - sum[i], sum[i + n - 1] - sum[index]);
            aux += test;
        }
        ans = max(ans, aux);
    }
    
    cout<<ans<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}