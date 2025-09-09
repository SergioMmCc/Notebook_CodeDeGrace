#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    vector<ll> freq(n);
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        freq[(num + i + 1) % n]++;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += freq[i] * freq[i];
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}