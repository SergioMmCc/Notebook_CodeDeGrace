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
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 1e9 + 7;

void solver(){
    int n; ll c; cin>>n>>c;
    string s; cin>>s;
    if(s[0] == '0' || s[n-1] == '0'){
        cout<<-1<<endl;
        return;
    }
    ll ans = 2, aux = 2;
    for(int i = 1; i < n-1; i++){
        if(s[i] == '1'){
            ans = (ans * 2LL) % mod;
            aux = (aux * 2LL) % c;
        }
        else{
            ans = (ans * (ll)i) % mod;
            aux = (aux * (ll)i) % c;
        }
    }

    cout<<(!aux ? -1 : ans)<<endl;
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