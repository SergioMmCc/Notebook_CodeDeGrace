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

const int maxi = 2e5 + 1;
const ll inf = 1e15;

void solver(){
    int n; ll y; cin>>n>>y;
    vector<int> a(n), cnt(maxi);
    int bigg = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        bigg = max(bigg, a[i]);
        cnt[a[i]]++;
    }

    if(bigg == 1){
        cout<<n<<endl;
        return;
    }

    vector<int> ps(bigg + 1);
    for(int i = 1; i <= bigg; i++) ps[i] = ps[i-1] + cnt[i];

    ll ans = -inf;
    for(int x = 2; x <= bigg; x++){
        int lim = (bigg + x - 1) / x;
        ll aux = 0;
        for(int p = 1; p <= lim; p++){
            ll supL = min(bigg, p*x), infL = min(bigg, p*x - x);
            ll sum = ps[supL] - ps[infL];
            aux += p*sum - (ll)max(0LL, sum - (ll)cnt[p]) * y;
        }

        ans = max(ans, aux);
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