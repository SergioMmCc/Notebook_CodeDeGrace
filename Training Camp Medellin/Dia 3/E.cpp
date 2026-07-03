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

const ll mod = 1e9 + 7;
vl sum(64);
void preCalc(){
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            sum[i & j]++;
        }
    }
}

int chToInt(char c){
    int idx = (int)c;
    if(idx >= '0' && idx <= '9') return idx - '0';
    if(idx >= 'A' && idx <= 'Z') return idx + 10 - 'A';
    if(idx >= 'a' && idx <= 'z') return idx + 36 - 'a';
    if(c == '-') return 62;
    return 63;
}

void solver(){
    string s; cin>>s;
    ll ans = 1;
    for(int i = 0; i < sz(s); i++){
        ans = (ans * sum[chToInt(s[i])]) % mod;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    preCalc();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}