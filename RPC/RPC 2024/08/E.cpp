#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n; cin>>n;
    long long ans = 0;
    while(n--) {
        long long a, b;
        cin>>a>>b;
        long long aux = a * b * min(a, b);
        ans = max(ans, aux);
    }
    cout<<ans<<endl;
    
    return 0;
}