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
typedef pair<pii, int> piii;

void solver(){
    int n; cin>>n;
    vector<piii> p(n);
    map<int, int> a, b, c;
    for(int i = 0; i < n; i++){
        cin>>p[i].fi.fi>>p[i].fi.se>>p[i].se;
        a[p[i].fi.fi]++;
        b[p[i].fi.se]++;
        c[p[i].se]++;
    }

    vector<int> ans(n+2);
    for(int i = 0; i < n; i++){
        int index = max(a[p[i].fi.fi], max(b[p[i].fi.se], c[p[i].se]));
        ans[index + 1]++;
    }

    for(int i = 1; i <= n; i++){
        ans[i] += ans[i-1];
        cout<<ans[i]<<' ';
    }
    cout<<endl;
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