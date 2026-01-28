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
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll inf = 2e9;

void solver(){
    int n; ll k; cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(all(a));

    ll l = -inf, r = inf, ans = -inf;
    while(l <= r){
        ll m = (r + l) / 2;
        ll cnt = 0;
        int j = n - 1;
        for(int i = 0; cnt < k && i < n; i++){
            while(j >= 0 && a[i] + a[j] >= m) j--;
            cnt += (ll)j + 1LL;
        }

        if(cnt >= k) r = m - 1;
        else{
            ans = m;
            l = m + 1;
        }
    }

    cout<<ans<<endl;
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