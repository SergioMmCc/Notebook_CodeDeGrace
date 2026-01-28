#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n;cin>>n;
    vector<int> freq(n+1, 0);
    for(int i = 0; i < n; i++){
        int save;cin>>save;
        freq[save]++;
    }
    int maxRep = -1;
    for(int i = 1;  i <= n; i++){
        maxRep = max(maxRep, freq[i]);
    }
    cout<<n-maxRep<<endl;
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