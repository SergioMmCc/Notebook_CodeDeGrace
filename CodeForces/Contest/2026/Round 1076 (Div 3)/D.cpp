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
    int n; cin>>n;
    vi a(n+1);
    vl b(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        b[i] += b[i-1];
    }

    sort(all(a));

    ll ans = 0;
    for(int x : a){
        auto it = lb(all(a), x);
        int s = n + 1 - (it - a.begin()); // Cantidad de espadas <= x

        auto it2 = ub(all(b), (ll)s);
        int tot = it2 - b.begin() - 1;

        ans = max(ans, (ll)tot * (ll)x);
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