#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    int totalCoins = 0, ans;
    bool cond = 0;
    for(int i = n - 1; !cond && i >= 0; i--){
        if(totalCoins + a[i] > k){
            ans = k - totalCoins;
            cond = 1;
        }
        else if(totalCoins + a[i] == k){
            ans = 0;
            cond = 1;
        }
        totalCoins += a[i];
    }

    if(totalCoins < k) ans = k - totalCoins;

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