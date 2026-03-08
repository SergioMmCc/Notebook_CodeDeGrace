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

const ll inf = 1e11;

bool can(ll m, vl& a, int n, int k){
    ll aux = a[0];
    if(a[0] > m) return 0;

    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(a[i] > m) return 0;
        if(aux + a[i] + 1 <= m){
            aux += a[i] + 1;
        }
        else{
            cnt++;
            aux = a[i];
        }
    }

    return cnt <= k;
}

void solver(){
    int n, k; cin>>n>>k;
    vl a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll lo = 1, hi = inf;
    while(lo < hi){
        ll m = (lo + hi) / 2;
        if(can(m, a, n, k)) hi = m;
        else lo = m + 1;
    }

    cout<<lo<<endl;
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