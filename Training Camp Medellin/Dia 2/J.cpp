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

vi coin(vi& a, vi& b, vb& av, vb& bv){
    vi ans;
    if(sz(a) < sz(b)) {for(int x : a) if(bv[x]) ans.pb(x);}
    else {for(int x : b) if(av[x]) ans.pb(x);}

    return ans;
}

void solver(){
    int n, m; cin>>n>>m;
    vector<vi> ing(n+1), oug(n+1);
    vector<vb> inv(n+1, vb(n+1)), ouv(n+1, vb(n+1));
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        oug[u].pb(v); ouv[u][v] = 1;
        ing[v].pb(u); inv[v][u] = 1;
    }

    for(int i = 1; i <= n; i++){
        sort(all(ing[i]));
        sort(all(oug[i]));
    }

    ll ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            vi cing = coin(ing[i], ing[j], inv[i], inv[j]), coug = coin(oug[i], oug[j], ouv[i], ouv[j]);
            ll cnt = 0;
            int a = 0, b = 0;
            while(a < sz(cing) && b < sz(coug)){
                if(cing[a] == coug[b]){
                    cnt++;
                    a++;
                    b++;
                }
                else if(cing[a] < coug[b]) a++;
                else b++;
            }

            ans += (ll)sz(cing) * (ll)sz(coug) - cnt;
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