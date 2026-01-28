#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n; cin>>n;
    vector<int> ans(n+1);
    for(int i = 0; i < n-1; i++) 
        cin>>ans[i+1];
    cin>>ans[0];
    cout<<ans[0];
    for(int i = 1; i < n; i++) 
        cout<<' '<<ans[i];
    cout<<endl;
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