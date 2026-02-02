#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll = long long;

void solver(){
    int n;ll p, h, limit = 1;
    cin>>n>>p>>h; p--;
    limit <<= n;
    vector<int> steps(n+1);
    char ans[62];
    for(int i = 1; i <= n; i++){
        steps[i] = p % 2;
        p /= 2;
    }
    for(int i = 1; i <= n; i++){
        if((h % 2) == steps[i])
            ans[n-i] = 'L';
        else
            ans[n-i] = 'R';
        h = min(h, limit - h + 1);
        limit >>= 1;
    }
    for(int i = 0; i < n; i++)
        cout<<ans[i];
    cout<<endl;
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