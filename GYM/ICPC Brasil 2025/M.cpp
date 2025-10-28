#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define int long long
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 2e9;

void solver(){
    int n, k; cin>>n>>k;
    vector<int> a(n+2);
    for(int i = 1; i <= n; i++) cin>>a[i];
    vector<int> minr(n+2, inf);
    for(int i = n; i > 0; i--) minr[i] = min(minr[i+1], a[i]);
    vector<int> minl(n+2, inf);
    for(int i = 1; i <= n; i++) minl[i] = min(minl[i-1], a[i]);

    int ans = 0;
    deque<pii> dq;
    for(int i = 1; i <= n; i++){
        while(!dq.empty() && a[i] + k <= dq.front().fi + dq.front().se - i) dq.pop_front();
        if(!dq.empty() && dq.front().se <= i - k) dq.pop_front();
        dq.push_back({a[i] + k, i});

        int ml = inf;
        if(i - k > 0) ml = minl[i - k];

        ans = max(ans, min(ml, min(dq.front().fi + dq.front().se - i, minr[i+1])));
    }

    cout<<ans<<endl;
}

signed main(){
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