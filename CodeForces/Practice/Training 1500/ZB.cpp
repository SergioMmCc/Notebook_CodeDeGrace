#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    vector<ll> a(n+1), prefixSum(n+1);
    int pos;
    if(n % 2) pos = n - 1;
    else pos = n;

    for(int i = 1; i <= n; i++){
        prefixSum[i] = prefixSum[i-1];
        cin>>a[i];
        if(a[i] >= 0){
            prefixSum[i] += a[i];
            if(i % 2 && pos > i) pos = i - 1;
        }
    }

    ll right = prefixSum[n] - prefixSum[pos];

    ll left = 0;
    for(int i = pos; i > 0; i--){
        if(i % 2) left = max(left, prefixSum[pos] - prefixSum[i-1] + a[i]);
        else left = max(left, prefixSum[pos] - prefixSum[i]);
    }

    cout<<left + right<<endl;
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