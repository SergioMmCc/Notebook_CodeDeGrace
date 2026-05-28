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
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

ll euc(pll a, pll b){
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

void solver(){
    int n; cin>>n;
    vll a(n);
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;

    pli comp = {0, 0};
    for(int i = 1; i < n; i++){
        ll dis = euc(a[0], a[i]);
        if(dis > comp.fi) comp = {dis, i};
    }

    vector<pli> ord;
    for(int i = 0; i < n; i++){
        if(i == comp.se) continue;
        ord.pb({euc(a[comp.se], a[i]), i});
    }

    sort(all(ord));

    ld ans = 0.0;
    int last = comp.se;
    for(int i = 0; i < n-1; i++){
        ans += sqrt(euc(a[last], a[ord[i].se]));
        last = ord[i].se;
    }

    cout<<fixed<<setprecision(8)<<ans<<endl;
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