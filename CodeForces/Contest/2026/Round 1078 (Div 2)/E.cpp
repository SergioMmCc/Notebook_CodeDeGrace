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

const ll inf = 1e17;

void solver(){
    int n, m; cin>>n>>m;
    vector<vl> a(n, vl(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }

    vector<vl> dp0(n, vl(m, -inf)); dp0[0][0] = a[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i) dp0[i][j] = dp0[i-1][j] + a[i][j];
            if(j) dp0[i][j] = max(dp0[i][j], dp0[i][j-1] + a[i][j]);
        }
    }

    vector<vl> dp1(n, vl(m, -inf)); dp1[n-1][m-1] = a[n-1][m-1];
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(i < n-1) dp1[i][j] = dp1[i+1][j] + a[i][j];
            if(j < m-1) dp1[i][j] = max(dp1[i][j], dp1[i][j+1] + a[i][j]);
        }
    }

    vector<vl> sum(n, vl(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum[i][j] = dp0[i][j] + dp1[i][j] - a[i][j];
        }
    }

    vector<vl> dp2(n, vl(m));
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            dp2[i][j] = sum[i][j];
            if(i < n-1) dp2[i][j] = max(dp2[i][j], dp2[i+1][j]);
            if(j) dp2[i][j] = max(dp2[i][j], dp2[i][j-1]);
        }
    }

    vector<vl> dp3(n, vl(m));
    for(int i = 0; i < n; i++){
        for(int j = m-1; j >= 0; j--){
            dp3[i][j] = sum[i][j];
            if(i) dp3[i][j] = max(dp3[i][j], dp3[i-1][j]);
            if(j < m-1) dp3[i][j] = max(dp3[i][j], dp3[i][j+1]);
        }
    }

    vector<vl> calc(n, vl(m, -inf));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            calc[i][j] = sum[i][j] - 2*a[i][j];
            if(i < n-1 && j) calc[i][j] = max(calc[i][j], dp2[i+1][j-1]);
            if(i && j < m-1) calc[i][j] = max(calc[i][j], dp3[i-1][j+1]);
        }
    }

    ll ans = inf;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = min(ans, calc[i][j]);
        }
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