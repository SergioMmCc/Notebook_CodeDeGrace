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

void update(int x, int y, vi& p, vi& inv, vii& ans){
    ans.pb({inv[x], inv[y]});
    p[inv[x]] = y;
    p[inv[y]] = x;
    swap(inv[x], inv[y]);
}

void solver(){
    int n; cin>>n;
    int m = n/2;
    vi p(n+1), inv(n+1);
    for(int i = 1; i <= n; i++){
        cin>>p[i];
        inv[p[i]] = i;
    }
    vii ans;
    for(int i = 1; i <= m; i++){
        if(inv[i] == i) continue;

        if(inv[i] <= m){
            update(i, p[n], p, inv, ans);
            update(i, p[i], p, inv, ans);
            continue;
        }

        if(inv[i] - i >= m){
            update(i, p[i], p, inv, ans);
            continue;
        }

        update(i, p[1], p, inv, ans);
        update(i, p[n], p, inv, ans);
        update(i, p[i], p, inv, ans);
        update(1, p[1], p, inv, ans);
    }

    for(int i = m+1; i <= n; i++){
        if(inv[i] == i) continue;

        update(i, p[1], p, inv, ans);
        update(i, p[i], p, inv, ans);
        update(1, p[1], p, inv, ans);
    }

    cout<<sz(ans)<<endl;
    for(pii x : ans) cout<<x.fi<<' '<<x.se<<endl;
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