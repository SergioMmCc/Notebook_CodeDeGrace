// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int math(int m, int k){
    if(m < 0) return 0;
    return max(0, (m+k)/(k+1));
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<char> vec(n+k+2, '0');
    for(int i=1; i<=n; i++)cin>>vec[i];
    vec[n+k+1] = '1';
    int m = n+k+2;

    int d=0, l=0, ans=0;
    for(int r=1; r<=m; r++){
        while(l <= m && l <= d){
            l++;
            if(vec[l] == '1') d = l + k;
        }

        if(l > n) break;

        if(l < r){
            if(vec[r] == '1'){
                r = r - k - 1;
                ans += math(r-l+1, k);
                //cout<<l<<" - "<<r<<" ***\n";
                r = r + k + 1;
                d = max(d, r+k);
            }
        }else{
            r = l;
        }
    }

    cout<<ans<<"\n";
}

int main() {
	int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
