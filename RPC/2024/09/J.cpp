#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

void solver(){
    int n;cin>>n;
    int ans = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    int chains = n;
    for(int i = 0; chains > 0 && i < n; i++){
        if(a[i] > chains){
            ans += chains;
            chains = 0;
        }
        else{
            ans += a[i];
            chains -= a[i] + 1;
        }
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