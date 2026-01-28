#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, ll> pll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vector<pll> a(n);
    for(int i = 0; i < n; i++){
        ll h; cin>>h;
        a[i] = {h, i};
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    set<ll> idx;
    idx.insert(a[0].se);
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ll index = a[i].se;
        auto it1 = idx.upper_bound(index);
        auto it2 = idx.upper_bound(index); --it2;

        if(it1 != idx.end() && it2 != idx.end()){
            ans += min(abs(index - *it1), abs(index - *it2));
        }
        else if(it1 != idx.end()) ans += abs(index - *it1);
        else ans += abs(index - *it2);

        idx.insert(index);
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}