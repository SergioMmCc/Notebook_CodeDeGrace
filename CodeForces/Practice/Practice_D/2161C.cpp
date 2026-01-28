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

void solver(){
    int n; ll x; cin>>n>>x;
    ll sum = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }

    int take = sum / x;
    ll ans = 0;
    sort(all(a));
    for(int i = n-1; take > 0; i--, take--) ans += a[i];
    cout<<ans<<endl;

    int i = 0, j = n-1;
    vector<ll> ord;
    ll s = 0;
    while(i <= j){
        if(s + a[j] >= x){
            ord.pb(a[j]);
            s += a[j];
            s %= x;
            j--;
        }
        else{
            ord.pb(a[i]);
            s += a[i];
            i++;
        }
    }

    for(int i = 0; i < n; i++) cout<<ord[i]<<' '; cout<<endl;
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