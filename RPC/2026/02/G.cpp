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

int toNum(string s){
    int ans = 0;
    ans += 36000 * (int)(s[0] - '0');
    ans += 3600 * (int)(s[1] - '0');
    ans += 600 * (int)(s[3] - '0');
    ans += 60 * (int)(s[4] - '0');
    ans += 10 * (int)(s[6] - '0');
    ans += (int)(s[7] - '0');
    return ans;
}

void solver(){
    int n, m; cin>>n>>m;
    vi a(n);
    for(int i = 0; i < n; i++){
        string aux; cin>>aux;
        a[i] = toNum(aux);
    }
    vi b(m);
    for(int i = 0; i < m; i++){
        string aux; cin>>aux;
        b[i] = toNum(aux);
    }
    sort(all(b));

    int slap; cin>>slap;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        auto it = lb(all(b), a[i] + slap);
        if(it == b.end()) continue;
        ans = min(ans, *it - a[i]);
    }

    cout<<(ans == 1e9 ? -1 : ans)<<endl;
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