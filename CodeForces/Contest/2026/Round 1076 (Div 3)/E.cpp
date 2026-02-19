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
    ll n; cin>>n;
    vl ans(n+1, n+1);
    for(int i = 0; i < n; i++){
        ll num; cin>>num;
        ans[num] = 1;
        // if(num == 1LL){
        //     ans[1] = 1;
        //     continue;
        // }

        // ll aux = num;
        // while(aux <= n){
        //     ans[aux] = 1;
        //     aux *= num;
        // }
    }

    for(ll i = 4; i <= n; i++){
        if(ans[i] == 1) continue;

        for(ll j = 2; j * j <= i; j++){
            if(i % j) continue;
            ans[i] = min(ans[j] + ans[i / j], ans[i]);
        }
        // ll r = sqrt(i);
        // if(r * r == i) ans[i] = min(ans[i], ans[r]);
    }

    for(int i = 1; i <= n; i++){
        if(i > 1) cout<<' ';
        cout<<(ans[i] > n ? -1 : ans[i]);
    }
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