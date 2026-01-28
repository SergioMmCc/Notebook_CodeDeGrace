#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int xc, yc, k;cin>>xc>>yc>>k;
    if(k % 2 == 1)
        cout<<xc<<' '<<yc<<endl;
    k /= 2;
    for(int i = 1; i <= k; i++) {
        cout<<xc<<' '<<yc+i<<endl;
        cout<<xc<<' '<<yc-i<<endl;
    }
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