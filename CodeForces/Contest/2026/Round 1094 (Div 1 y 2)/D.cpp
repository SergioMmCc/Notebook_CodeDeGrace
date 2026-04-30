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
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pli> vli;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vl a(n+1);
    vli ps(n); ps[0] = {0, 1};
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(i < n) ps[i] = {ps[i-1].fi + a[i], i+1};
    }

    sort(all(ps));
    reverse(all(ps));
    vi ans(n+1);
    for(int i = 0; i < n; i++) ans[ps[i].se] = i+1;
    for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';
    cout<<endl;
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