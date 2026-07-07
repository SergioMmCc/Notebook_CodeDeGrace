#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
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

vi ask(int a, int n){
    cout<<"? "<<a<<endl;
    vi dis(n+1);
    for(int i = 1; i <= n; i++) cin>>dis[i];
    return dis;
}

void ans(vii& edj){
    cout<<"!"<<endl;
    for(pii e : edj) cout<<e.fi<<' '<<e.se<<endl;
}

void solver(){
    int n; cin>>n;

    vi st = ask(1, n);
    vi par, imp;
    vii edj;
    for(int i = 2; i <= n; i++){
        if(st[i] & 1) imp.pb(i);
        else par.pb(i);

        if(st[i] == 1) edj.pb({1, i});
    }

    if(sz(par) < sz(imp)) swap(par, imp);
    for(int u : imp){
        vi aux = ask(u, n);
        for(int i = 2; i <= n; i++) if(aux[i] == 1) edj.pb({u, i});
    }

    assert(sz(edj) == n-1);
    ans(edj);
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}