
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

    int ans = -1;
    for(int i = 0; ans == -1 && i < n; i++){
        bool cond = 1;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            if((abs(a[i] - a[j])) % k == 0){
                cond = 0;
                break;
            }
        }

        if(cond) ans = i + 1;
    }

    if(ans != -1) cout<<"YES"<<endl<<ans<<endl;
    else cout<<"NO"<<endl;
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