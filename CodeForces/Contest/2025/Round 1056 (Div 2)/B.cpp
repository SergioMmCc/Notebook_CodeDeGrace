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

void solver(){
    int n, k; cin>>n>>k;
    int n2 = n*n;
    k = n2 - k;
    if(k == 1){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    vector<string> ans(n, "");
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            if(cnt < k){
                if(i) ans[i] += "U";
                else if(j == n - 1 || cnt == k - 1) ans[i] += "L";
                else ans[i] += "R";
                cnt++;
            }
            else ans[i] += "D";
        }
    }

    for(int i = 0; i < n; i++) cout<<ans[i]<<endl;
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