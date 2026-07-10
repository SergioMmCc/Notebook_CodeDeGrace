#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int ans=r-l;
        if(l == r && l == 1){
            ans = max(1, ans);
            
        }
        cout<<ans<<"\n";
    }
}
