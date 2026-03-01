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

bool can(ll m, ll h, ll n, vl& b){
    ll aux = 0;
    ll mini = 1e9+1;
    ll maxi = 0;

    for(int i = 0; i < n; i++){
        if(i < m){
            aux += b[i];
            mini = min(mini, b[i]);
        }
        else maxi = max(maxi, b[i]);
    }

    if(maxi > mini) aux = aux + maxi - mini;
    
    return aux >= h;
}

void solver(){
    ll n, h, k; cin>>n>>h>>k;
    ll sum = 0;
    vl b(n);
    for(int i = 0; i < n; i++){
        cin>>b[i];
        sum += b[i];
    }

    ll r = (h + sum - 1) / sum;
    ll ans = (r - 1) * (k + n);
    h %= sum;
    if(!h){
        ans += n;
        cout<<ans<<endl;
        return;
    }

    ll i = 1, j = n;
    while(i < j){
        ll m = (i + j) / 2;
        if(can(m, h, n, b)) j = m;
        else i = m+1;
    }

    ans += j;
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