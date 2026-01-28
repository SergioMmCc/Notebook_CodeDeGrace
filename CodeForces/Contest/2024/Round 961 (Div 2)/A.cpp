#include<bits/stdc++.h>
using namespace std;

void solver() {
    int n, k, ans = 0;
    cin>>n>>k;
    if(k == 0) {
        cout << ans << "\n";
        return;
    }
    k -= n; ans++;
    for(int i = 1; k > 0; i++) {
        k -= n-i; ans++;
        if(k > 0) {
            k -= n-i;
            ans++;
        }
    }
    cout << ans << "\n";
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