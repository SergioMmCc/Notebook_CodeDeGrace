#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n;cin>>n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int save; cin>>save;
        if(i % 2 == 1)
            ans = max(ans, save);
    }
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