#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    ll n; cin>>n;
    ll count1 = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll save; cin>>save;
        sum += save;
        if(save == 1) count1++;
    }

    if(n == 1 || (count1 && (sum - n + count1) / count1 < 2)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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