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
    int n, m, k; cin>>n>>m>>k;
    if(m >= 2*n - 2){
        cout<<n<<endl;
        return;
    }
    
    if(k > n/2) k = n - k + 1;

    int ans = min(n-k, (m + 1) / 2);
    for(int i = k-1; i >= 1; i--){
        int l = k - i;
        if(m < 2*l - 1) break;

        int left = m - 2*l + 1;
        if(left <= l){
            ans = max(ans, min(n-1, l + left));
            // cout<<" i-> "<<i<<" ans -> "<<ans<<endl;
            continue;
        }

        int add = 2*l;
        left -= l;
        add += left / 2;
        add = min(add, n-1);

        ans = max(ans, add);
        // cout<<" i-> "<<i<<" ans -> "<<ans<<endl;
    }

    cout<<ans+1<<endl;
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