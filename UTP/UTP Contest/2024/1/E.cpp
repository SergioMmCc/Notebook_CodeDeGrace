#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long

void solver(){
    int n, k; cin>>n>>k;
    map<int, int> freq;
    int maxRep = 0, nRep = 0;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        save %= k;
        if(!save) continue;
        save = k - save;
        freq[save]++;
        int rep = freq[save];
        if(rep > maxRep){
            maxRep = rep;
            nRep = save;
        }
        else if(rep == maxRep) nRep = max(nRep, save);
    }
    
    if(!maxRep) cout<<0<<endl;
    else cout<<k * (maxRep - 1) + nRep + 1<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}