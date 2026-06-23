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

vi factors(int n){
    vi f;
    for(int x = 2; x*x <= n; x++){
        while(n % x == 0){
            f.pb(x);
            n /= x;
        }
    }

    if(n > 1) f.pb(n);
    return f;
}

void solver(){
    int n; cin>>n;
    if(n == 1){
        cout<<1<<endl;
        return;
    }

    vi fact = factors(n);
    int ans = 1;
    int last = fact[0], cnt = 1;
    for(int i = 1; i < sz(fact); i++){
        if(fact[i] != last){
            ans *= cnt + 1;
            last = fact[i];
            cnt = 1;
        }
        else cnt++;
    }
    ans *= cnt + 1;

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