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
#define int long long

void solver(){
    int n; string s; cin>>n>>s;
    vector<int> ps(n+1);
    for(int i = 0; i < n; i++){
        ps[i+1] = ps[i];
        if(s[i] == '0') ps[i+1]--;
        else ps[i+1]++;
    }

    int ans = (n * (n + 1) * (n + 1)) / 2 - (n * (n + 1) * (2*n + 1)) / 6;

    int add = 0;
    sort(ps.begin(), ps.end());
    for(int i = 0; i <= n; i++){
        add += ps[i] * (2*i - n);
    }

    ans += add;
    ans /= 2;
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}