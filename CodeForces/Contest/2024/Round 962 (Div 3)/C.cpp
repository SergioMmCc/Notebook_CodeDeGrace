#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n, q, l, r;cin>>n>>q;
    vector<vector<int>> freq1(28, vector<int>(n+2, 0)), freq2(28, vector<int>(n+2, 0));
    
    string a, b;
    cin>>a>>b;

    for(int i = 0; i < n; i++) {
        int a1 = a[i] - 'a', b1 = b[i] - 'a';
        for(int j = 0; j <= 26; j++) 
            freq1[j][i+1] = freq1[j][i];
        freq1[a1][i+1]++;
        
        for(int j = 0; j <= 26; j++) 
            freq2[j][i+1] = freq2[j][i];
        freq2[b1][i+1]++;
    }
    
    while(q--) {
        int ans = 0;
        cin>>l>>r;
        for(int i = 0; i <= 26; i++) 
            ans += abs(freq1[i][r]-freq1[i][l-1] - (freq2[i][r]-freq2[i][l-1]));
        ans >>= 1;
        cout<<ans<<endl;
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