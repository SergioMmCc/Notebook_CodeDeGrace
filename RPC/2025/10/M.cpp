#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

bool check(vector<int>& a, int d){
    int next = 0, last = 0;
    while(next < a.sz){
        int idx = a[next];
        if(idx < last) return 0;
        auto it = upper_bound(a.begin(), a.end(), idx + d - 1);
        --it;
        int i = it - a.begin();
        int r = a[i];
        int l = max(last, r - d + 1);
        last = l + 2*d;
        next = i+1;
    }

    return 1;
}

void solver(){
    int n, d; cin>>n>>d;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        a[save].pb(i);
    }

    int ans = -1;
    for(int i = 0; ans == -1 && i < n; i++){
        if(a[i].sz < 2 || check(a[i], d)) ans = i;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}