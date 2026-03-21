#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define int long long
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

void solver(){
    int n, m; cin>>n>>m;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    vector<piii> seg(n-1);
    for(int i = 0; i < n - 1; i++) seg[i] = {{a[i+1].se - a[i].fi, a[i+1].fi - a[i].se}, i};
    sort(seg.begin(), seg.end());

    set<pii> p;
    for(int i = 0; i < m; i++){
        int save; cin>>save;
        p.insert({save, i+1});
    }

    vector<int> ans(n-1);
    bool cond = 1;
    for(int i = 0; cond && i < n-1; i++){
        int l = seg[i].fi.se, r = seg[i].fi.fi, index = seg[i].se;

        auto it = p.upper_bound({l, 0});
        if(it == p.end() || (*it).fi > r) cond = 0;
        else{
            ans[index] = (*it).se;
            p.erase(it);
        }
    }

    if(!cond) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        for(int i = 0; i < n - 1; i++){
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}