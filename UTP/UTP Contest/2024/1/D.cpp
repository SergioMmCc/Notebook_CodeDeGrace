#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    ll ans = 0;
    map<int, ll> freq;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        freq[save - i]++;
    }

    for(const auto& pair : freq){
        ans += (pair.second * (pair.second - 1)) / 2; 
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}