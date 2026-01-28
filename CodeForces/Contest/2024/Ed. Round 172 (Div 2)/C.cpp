#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    ll n, k; cin>>n>>k;
    ll count0 = 0, count1 = 0;
    string nums; cin>>nums;
    for(ll i = 0; i < n; i++){
        if(nums[i] == '0') count0++;
        else count1++;
    }
    
    vector<ll> dif(n);
    for(int i = 0; i < n; i++){
        if(nums[i] == '0') count0--;
        else count1--;
        // cout<<"i -> "<<i<<" count0 -> "<<count0<<" count1 -> "<<count1<<" dif -> "<<count1 - count0<<endl;
        dif[i] = count1 - count0;
    }

    // cout<<"Sin orden: "<<endl;
    // for(int i = n - 1; i >= 0; i--) cout<<i<<' '<<dif[i]<<endl;
    // cout<<endl;
    sort(dif.begin(), dif.end());
    // cout<<"Ordenado: "<<endl;
    // for(int i = n - 1; i >= 0; i--) cout<<i<<' '<<dif[i]<<endl;
    // cout<<endl;

    ll sum = 0;
    int ans = 1;
    for(int i = n - 1; i >= 0; i--){
        if(dif[i] <= 0) break;
        sum += dif[i];
        ans++;
        if(sum >= k) break;
    }

    if(sum < k) cout<<-1<<endl;
    else cout<<ans<<endl;
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