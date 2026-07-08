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

void solver(){
    string s; cin>>s;
    int n = sz(s);
    string aux1 = "heavy", aux2 = "metal";
    vi pos1, pos2;
    for(int i = 0; i < n-4; i++){
        string comp = "";
        comp += s[i]; comp += s[i+1]; comp += s[i+2]; comp += s[i+3]; comp += s[i+4];
        if(comp == aux1) pos1.pb(i);
        else if(comp == aux2) pos2.pb(i);
    }

    ll ans = 0;
    for(int x : pos1){
        auto it = ub(all(pos2), x);
        ans += (ll)distance(it, pos2.end());
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