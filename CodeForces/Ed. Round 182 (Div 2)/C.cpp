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

bool check(vector<int>& a, vector<int>& b){
    for(int i = 0; i < sz(a); i++) if(a[i] >= b[i]) return 0;
    return 1;
}

vector<int> shift(vector<int>& a){
    int n = sz(a);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(i == n-1) ans[i] = a[0];
        else ans[i] = a[i+1];
    }
    return ans;
}

void solver(){
    int n; cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    for(int i = 0; i < n; i++) cin>>c[i];

    ll ans1 = 0;
    for(int i = 0; i < n; i++){
        if(check(a, b)) ans1++;
        b = shift(b);
    }
    // for(int i = 0; i < n; i++) cout<<ans1[i]<<' '; cout<<endl;

    ll ans2 = 0;
    for(int i = 0; i < n; i++){
        if(check(b, c)) ans2++;
        c = shift(c);
    }

    cout<<(ll)n * ans1 * ans2<<endl;
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