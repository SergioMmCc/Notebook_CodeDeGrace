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

void solver(int n){
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    ll ans = 0;
    for(int l = 0; l < n; l++){
        ll cur = 0, best = -1e15;
        for(int r = l; r < n; r++){
            cur = max(a[r], cur + a[r]);
            best = max(best, cur);
            ans ^= best;
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
    int n;
    while(cin>>n){
        solver(n);
    }

    return 0;
}