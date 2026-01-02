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
typedef pair<int, ll> pil;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, m; ll k; cin>>n>>m>>k;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin>>a[i];
    sort(all(a));

    vector<pil> f;
    for(int i = 0; i < n; i++){
        int x; ll y, z; cin>>x>>y>>z;
        k -= y;
        f.pb({x, z - y});
    }
    sort(all(f));

    int j = 0;
    multiset<ll> c;
    int ans = 0;
    for(int b : a){
        while(j < n && f[j].fi <= b){
            c.insert(f[j].se);
            j++;
        }
        if(!c.empty()){
            ans++;
            auto it = c.end(); --it;
            c.erase(it);
        }
    }

    for(; j < n; j++) c.insert(f[j].se);

    for(ll p : c){
        if(p <= k){
            ans++;
            k -= p;
        }
        else break;
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