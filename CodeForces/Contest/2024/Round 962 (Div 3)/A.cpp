#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n, ans;cin>>n;
    if(n % 4 == 0) {
        ans = n / 4;
    }
    else
        ans = n/4 + 1;
    
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