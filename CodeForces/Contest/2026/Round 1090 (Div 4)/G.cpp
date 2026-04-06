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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 676767677;

void solver(){
    int n, m; cin>>n>>m;
    vi a(n+1);
    vector<vi> b(m);

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[a[i]].pb(i);
    }

    vll ans(n+1, {1, 1});

    vb act(n+2);
    for(int x : b[0]){
        act[x] = 1;
    }

    vi cnt(m);
    cnt[0] = sz(b[0]);

    for(int i = 1; i < m; i++){
        cnt[i] = cnt[i-1] + sz(b[i]);
        // cout<<"i -> "<<i<<" cnt -> "<<cnt[i]<<endl;
        for(int x : b[i]){
            if(!act[x-1] && !act[x+1]){
                // cout<<"here"<<endl;
                cout<<0<<endl;
                return;
            }
            if((x > 1 && a[x-1] < i-1) || (x < n && a[x+1] < i-1)){
                ans[x].fi = (ll)cnt[i-2] + 1;
            }
            ans[x].se = (ll)cnt[i-1];
        }

        for(int x : b[i]) act[x] = 1;
    }

    // for(int i = 1; i <= n; i++){
    //     cout<<"i -> "<<i<<" ans.fi -> "<<ans[i].fi<<" ans.se -> "<<ans[i].se<<endl;
    // }

    ll aux = 1;
    for(int i = 1; i <= n; i++){
        ll mul = ans[i].se - ans[i].fi + 1;
        // cout<<"i -> "<<i<<" mul -> "<<mul<<endl;
        aux *= mul;
        aux %= mod;
    }
    // cout<<"here2"<<endl;

    cout<<aux<<endl;
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