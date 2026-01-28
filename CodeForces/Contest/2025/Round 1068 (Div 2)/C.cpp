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
    int n; ll k; cin>>n>>k;
    set<ll> aux;
    vector<ll> a;
    for(int i = 0; i < n; i++){
        ll num; cin>>num;
        aux.insert(num);
    }
    for(ll x : aux) a.pb(x);
    n = sz(a);
    vector<bool> use(n);
    set<ll> b;

    for(int i = 0; i < n; i++){
        if(use[i]) continue;
        use[i] = 1;
        b.insert(a[i]);
        for(ll j = 2*a[i]; j <= k; j += a[i]){
            auto it = lb(all(a), j);
            if(it == a.end() || *it != j){
                cout<<-1<<endl;
                return;
            }
            int idx = it - a.begin();
            assert(idx >= 0);
            use[idx] = 1;
        }
    }

    cout<<sz(b)<<endl;
    for(ll x : b) cout<<x<<' ';
    cout<<endl;
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