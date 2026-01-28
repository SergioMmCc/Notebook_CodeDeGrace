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
typedef pair<ll, ll> pll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll inf = 1e14;

void solver(){
    int n; cin>>n;
    vector<pll> a(n);
    vector<ll> d(n-1);
    vector<ll> sump(n), sumi(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].fi>>a[i].se;
        if(!i) continue;
        d[i-1] = abs(a[i].fi - a[i-1].fi) + abs(a[i].se - a[i-1].se);
        if(i > 1){
            sumi[i-1] = sumi[i-2];
            sump[i-1] = sump[i-2];
        }
        if(i & 1) sump[i-1] += d[i-1];
        else sumi[i-1] += d[i-1];
    }

    ll ans = d[0] - 1;
    for(int i = 1; i < n; i++){
        ll add = 0LL;
        // cout<<"i -> "<<i<<" sumi -> "<<sumi[i-1]<<" sump -> "<<sump[i-1]<<" ans -> "<<ans<<endl;
        if(i & 1){
            add = sump[i-1] - sumi[i-1];
            if(add - ans < 1){
                ans = add - 1;
            }
        }
        else{
            add = sumi[i-1] - sump[i-1];
            if(add + ans < 1){
                cout<<-1<<endl;
                return;
            }
        }

        if(ans < 1){
            cout<<-1<<endl;
            return;
        }

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