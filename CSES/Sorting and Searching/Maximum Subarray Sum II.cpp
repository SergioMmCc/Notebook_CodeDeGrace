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
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pli> vli;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, a, b; cin>>n>>a>>b;
    vl ps(n+1);
    for(int i = 1; i <= n; i++){
        ll num; cin>>num;
        ps[i] = ps[i-1] + num;
    }

    ll ans = -1e16;
    deque<pli> dq;
    for(int i = a; i <= n; i++){
        ll add = ps[i-a];

        if(!dq.empty() && dq.front().se == i - b - 1) dq.pop_front();

        while(!dq.empty() && dq.back().fi >= add) dq.pop_back(); 
        dq.pb({add, i-a});

        ans = max(ans, ps[i] - dq.front().fi);
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