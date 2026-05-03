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
    int n; cin>>n;
    n *= 2;
    int z1 = 0, z2 = 0;
    vi a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(!a[i]){
            if(!z1) z1 = i;
            else z2 = i;
        }
    }

    int ans = 1;
    set<int> use;

    // Desde Z1
    for(int i = 1; i < n; i++) use.insert(i);
    for(int l = 1; l <= n; l++){
        if(z1 + l > n || z1 - l < 1) break;
        if(a[z1 - l] != a[z1 + l]) break;
        use.erase(a[z1-l]);
        ans = max(ans, *use.begin());
    }

    use.clear();

    // Desde Z2
    for(int i = 1; i < n; i++) use.insert(i);
    for(int l = 1; l <= n; l++){
        if(z2 + l > n || z2 - l < 1) break;
        if(a[z2 - l] != a[z2 + l]) break;
        use.erase(a[z2-l]);
        ans = max(ans, *use.begin());
    }

    use.clear();

    // Desde Z1 y Z2
    for(int i = 1; i < n; i++) use.insert(i);
    for(int l = 1; l <= n; l++){
        if(z1 + l > z2 - l) break;
        if(a[z1+l] != a[z2-l]){
            cout<<ans<<endl;
            return;
        }

        use.erase(a[z1+l]);
    }

    ans = max(ans, *use.begin());

    for(int l = 1; l <= n; l++){
        if(z1 - l < 1 || z2 + l > n){
            cout<<ans<<endl;
            return;
        }

        if(a[z1-l] != a[z2+l]){
            cout<<ans<<endl;
            return;
        }

        use.erase(a[z1-l]);
        ans = max(ans, *use.begin());
    }

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