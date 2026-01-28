#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

struct comp{
    bool operator()(pll a, pll b){
        return a.fi + a.se < b.fi + b.se;
    }
};

void solver(){
    int n; cin>>n;
    vector<pll> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i].fi>>a[i].se;
        ans += a[i].se - a[i].fi;
    }

    // cout<<"inicial sum -> "<<ans<<endl;
    sort(all(a), comp());
    // for(int i = 0; i < n; i++) cout<<a[i].fi<<' '<<a[i].se<<endl;

    if(n % 2 == 0){
        int mid = n / 2;
        for(int i = 0; i < n; i++){
            if(i < n / 2) ans -= a[i].fi;
            else ans += a[i].se;
        }
        cout<<ans<<endl;
        return;
    }

    int mid = n / 2;
    for(int i = 0; i < n; i++){
        if(i < mid) ans -= a[i].fi;
        else if(i > mid) ans += a[i].se;
    }

    ll maxx = ans;
    for(int i = 0; i < n; i++){
        if(i < mid) maxx = max(maxx, ans + a[i].fi - a[mid].fi);
        else if(i > mid) maxx = max(maxx, ans - a[i].se + a[mid].se);
    }
    cout<<maxx<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}