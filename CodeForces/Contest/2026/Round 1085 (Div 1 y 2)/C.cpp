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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; ll h; cin>>n>>h;
    vl a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n == 1){
        cout<<h - a[1]<<endl;
        return;
    }

    vector<vl> l(n+1, vl(n+1)), r(n+1, vl(n+1));
    for(int i = 1; i <= n; i++){
        ll maxx = a[i];
        l[i][i] = h - maxx;
        for(int j = i-1; j > 0; j--){
            maxx = max(maxx, a[j]);
            l[i][j] = l[i][j+1] + h - maxx;
        }
    }

    for(int i = 1; i <= n; i++){
        ll maxx = a[i];
        r[i][i] = h - maxx;
        for(int j = i+1; j <= n; j++){
            maxx = max(maxx, a[j]);
            r[i][j] = r[i][j-1] + h - maxx;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll add1 = 0;
        for(int j = 1; j <= i; j++){
            add1 = max(add1, l[j][1] + r[j][i] - h + a[j]);
        }
        ll add2 = 0;
        for(int k = i+1; k <= n; k++){
            add2 = max(add2, l[k][i+1] + r[k][n] - h + a[k]);
        }

        ans = max(ans, add1 + add2);
    }
    for(int i = 1; i <= n; i++){
        ans = max(ans, l[i][1] + r[i][n] - h + a[i]);
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