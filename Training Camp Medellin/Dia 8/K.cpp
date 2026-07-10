#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr<<#x<<" "<<x<<endl
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
    int n; cin>>n;
    vl a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(!(i & 1)) a[i] *= -1LL;
    }
    if(n == 1){
        cout<<0<<endl;
        return;
    }
    if(n & 1){
        a.pop_back();
        n--;
    }
    if(n == 2){
        cout<<min(a[1], -a[2])<<endl;
        return;
    }

    vector<vl> dp1(n+1, vl(n+1)), dp2(n+1, vl(n+1));
    for(int i = 1; i < n; i += 2){
        dp1[i][i+1] = a[i];
        ll cnt = a[i] + a[i+1];
        for(int j = i+2; j <= n; j++){
            if(j & 1) dp1[i][j+1] = min(cnt, dp1[i][j-1]);
            cnt += a[j];
        }
    }
    for(int j = n; j > 1; j -= 2){
        dp2[j-1][j] = a[j];
        ll cnt = a[j] + a[j-1];
        for(int i = j-2; i >= 1; i--){
            if(!(i & 1)) dp2[i-1][j] = max(dp2[i+1][j], cnt);
            cnt += a[i];
        }
    }

    ll ans = 0;
    for(int i = 1; i < n; i += 2){
        for(int j = i+1; j <= n; j += 2){
            ll aux = min(dp1[i][j], -dp2[i][j]);
            if(j != i+1) aux++;
            ans += max(0LL, aux);
        }
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