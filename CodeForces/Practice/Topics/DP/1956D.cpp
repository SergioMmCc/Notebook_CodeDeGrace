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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void process(int l, int r, vii& ans){
    if(l == r){
        ans.pb({l, r});
        return;
    }

    process(l, r-1, ans);
    ans.pb({l, r-1});
    process(l+1, r, ans);
}

void solver(){
    int n; cin>>n;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<vii> dp(n+1, vii(n+1));
    for(int i = 1; i <= n; i++){
        dp[i][i] = {1, 0};
        if(a[i] > 1) dp[i][1] = {a[i], i};
    }

    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len-1 <= n; i++){
            int j = i+len-1;

            dp[i][j] = {len*len, 0};
            for(int k = i; k <= j; k++){
                int aux = a[k];
                if(k > i) aux += dp[i][k-1].fi;
                if(k < j) aux += dp[k+1][j].fi;
                if(aux > dp[i][j].fi) dp[i][j] = {aux, k};
            }
        }
    }

    vb mark(n+1);
    stack<piii> st;
    if(dp[1][n].se) st.push({{1, n}, dp[1][n].se});
    while(!st.empty()){
        int i = st.top().fi.fi, j = st.top().fi.se, mid = st.top().se; st.pop();
        mark[mid] = 1;

        if(mid > i && dp[i][mid-1].se) st.push({{i, mid-1}, dp[i][mid-1].se});
        if(mid < j && dp[mid+1][j].se) st.push({{mid+1, j}, dp[mid+1][j].se});
    }
    
    vii ran;
    int l = 0;
    for(int i = 1; i <= n; i++){
        if(l && mark[i]){
            ran.pb({l, i-1});
            l = 0;
        }
        if(!l && !mark[i]) l = i;
    }
    if(l) ran.pb({l, n});

    vii ans;
    for(pii x : ran){
        bool zero = 0;
        for(int i = x.fi; !zero && i <= x.se; i++){
            if(!a[i]) zero = 1;
        }

        if(zero) ans.pb(x);

        process(x.fi, x.se, ans);
        ans.pb(x);
    }

    cout<<dp[1][n].fi<<' '<<sz(ans)<<endl;
    for(pii x : ans) cout<<x.fi<<' '<<x.se<<endl;
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