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
    int n, k; cin>>n>>k;
    vii a(n);
    for(int i = 0; i < n; i++) cin>>a[i].se>>a[i].fi;
    sort(all(a));
    for(int i = 0; i < n; i++) swap(a[i].fi, a[i].se);

    multiset<int> last;
    for(int i = 0; i < k; i++) last.insert(1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = last.ub(a[i].fi);
        if(it == last.begin()) continue;
        ans++;
        --it;
        last.erase(it);
        last.insert(a[i].se);
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