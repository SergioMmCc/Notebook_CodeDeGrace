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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int comp(int n){
    int ans = 0;
    int pot2 = 1;
    while(n > 1){
        if(!(n & 1)) ans += pot2;
        pot2 *= 2;
        n >>= 1;
    }

    return ans;
}

void solver(){
    int l; ll r; cin>>l>>r;
    cout<<r * (r + 1LL)<<endl;
    vector<int> ans(r+1);

    for(int i = r; i > 0; i--){
        if(ans[i]) continue;
        int c = comp(i);
        ans[i] = c;
        ans[c] = i;
    }

    for(int i = 0; i <= r; i++){
        if(i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
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