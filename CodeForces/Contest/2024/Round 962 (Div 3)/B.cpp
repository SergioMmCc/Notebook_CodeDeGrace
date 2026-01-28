#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n, k;cin>>n>>k;
    char maze[1002][1002], ans[1002][1002];
    for(int i = 0; i < n; i++) {
        cin>>maze[i];
    }
    for(int i = 0, iIndex = 1; i < n; i+=k, iIndex++) {
        for(int j = 0, jIndex = 1; j < n; j+=k, jIndex++) {
            ans[iIndex][jIndex] = maze[i][j];
        }
    }
    
    for(int i = 1; i <= n/k; i++) {
        for(int j = 1; j <= n/k; j++) {
            cout<<ans[i][j];
        }
        cout<<endl;
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