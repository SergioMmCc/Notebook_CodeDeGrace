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
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vi a(n+1);
    vii mins(n+2, {1e6 + 1, 0}), minp(n+2, {1e6 + 1, 0}), maxs(n+2, {-1e6 - 1, 0}), maxp(n+2, {-1e6 - 1, 0});
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        minp[i] = min(minp[i-1], {a[i], i});
        maxp[i] = max(maxp[i-1], {a[i], i});
    }

    for(int i = n; i >= 1; i--){
        mins[i] = min(mins[i+1], {a[i], i});
        maxs[i] = max(maxs[i+1], {a[i], i});
    }

    for(int i = 2; i < n; i++){
        if(minp[i-1].fi < a[i] && mins[i+1].fi < a[i]){
            cout<<3<<endl<<minp[i-1].se<<' '<<i<<' '<<mins[i+1].se<<endl;
            return;
        }
        if(maxp[i-1].fi > a[i] && maxs[i+1].fi > a[i]){
            cout<<3<<endl<<maxp[i-1].se<<' '<<i<<' '<<maxs[i+1].se<<endl;
            return;
        }
    }

    cout<<0<<endl;
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