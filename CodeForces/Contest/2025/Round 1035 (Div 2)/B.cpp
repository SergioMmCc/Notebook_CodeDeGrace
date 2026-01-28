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
    ld px, py, qx, qy; cin>>px>>py>>qx>>qy;
    ld mini = (px - qx) * (px - qx) + (py - qy) * (py - qy);
    mini = sqrt(mini);
    ld maxi = mini;

    vector<ld> d(n);
    for(int i = 0; i < n; i++) cin>>d[i];

    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());

    bool cond = 0;
    for(int i = 0; !cond && i < n; i++){
        if(d[i] <= maxi && d[i] >= mini) cond = 1;
        maxi += d[i];
        mini = abs(mini - d[i]);
    }

    cout<<(cond ? "Yes" : "No")<<endl;
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