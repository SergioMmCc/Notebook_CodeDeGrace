#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<int, int> pii;

void solver() {
    int n, k; cin>>n>>k;
    long long ans = 0;
    int maxPossible = 0;
    vector<pii> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i].first;
    for(int i = 0; i < n; i++)
        cin>>a[i].second;
        
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        int med;
        if(a[i].second){
            if(i < n/2)med = a[n/2].first;
            else med = a[n/2 - 1].first;
            ans = max(ans, (long long)k + med + a[i].first);
        }
    }
    
    long long l = 1, r = 2e9;
    while(l < r){
        long long m = (1+l+r)/2, used = k;
        int bigger = 0;
        vector<long long> minor;
        for(int i = 0; i < n-1; i++){
            if(a[i].first >= m)bigger++;
            else if(a[i].second)minor.push_back((long long)m - a[i].first);
        }
        
        reverse(minor.begin(), minor.end());
        for(long long i : minor){
            if(i <= used){
                bigger++,
                used -= i;
            }
        }
        if(bigger >= (n+1) / 2)
            l = m;
        else
            r = m-1;
    }
    ans = max(ans, (long long)l + a[n-1].first);

    cout<<ans<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }
    
    return 0;
}