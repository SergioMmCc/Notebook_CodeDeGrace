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
    vi a(n), b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(all(b));
    int mid = b[n / 2];

    vector<vi> cond(n, vi(n));
    for(int i = 0; i < n; i++){
        int cnt = 0, mini = 0, maxi = 0;
        if(a[i] == mid) cnt = 1;
        else if(a[i] < mid) mini = 1;
        else maxi = 1;
        if(cnt) cond[i][i] = 1;
        for(int j = i+2; j < n; j += 2){
            if(a[j] == mid) cnt++;
            else if(a[j] < mid) mini++;
            else maxi++;
            if(a[j-1] == mid) cnt++;
            else if(a[j-1] < mid) mini++;
            else maxi++;
            
            if(cnt - abs(maxi - mini) > 0) cond[i][j] = 1;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++) cout<<cond[i][j]<<' ';
    //     cout<<endl;
    // }

    vi dp(n, 1);

    for(int i = 0; i < n; i++){
        if(cond[i][i]) dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(cond[0][j] && cond[j+1][i]){
                cond[0][i] = 1;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    cout<<dp[n-1]<<endl;
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