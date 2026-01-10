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
    int n; cin>>n;
    vector<bool> use(n+1);
    map<int, int> comp = {{0, 2}, {1, 3}, {2, 5}, {3, 7}, {4, 11}, {5, 13}};
    vector<vector<int>> calc(6);
    for(int i = 0; i < 6; i++){
        int num = comp[i];
        for(int j = num; j <= n; j += num){
            if(!use[j]){
                calc[i].pb(j);
                use[j] = 1;
            }
        }
    }
    
    vector<int> ans;
    int i = 1, j = 0, k = 0;
    for(; i <= n; i++){
        if(use[i]) continue;
        ans.pb(i);
        if(k < sz(calc[j])) ans.pb(calc[j][k]);
        else{
            j++;
            while(j < 6 && calc[j].empty()) j++;
            if(j < 6){
                ans.pb(calc[j][0]);
                k = 1;
            }
        }
        if(j < 6 && k + 1 < sz(calc[j])){
            ans.pb(calc[j][k+1]);
            k += 2;
        }
        else{
            j++;
            while(j < 6 && sz(calc[j]) < 2){
                if(calc[j].empty()){
                    j++;
                    continue;
                }
                ans.pb(calc[j][0]);
                j++;
            }

            if(j < 6){
                ans.pb(calc[j][0]);
                ans.pb(calc[j][1]);
                k = 2;
            }
        }
    }

    if(i > n){
        for(; j < 6; j++){
            for(; k < sz(calc[j]); k++){
                ans.pb(calc[j][k]);
            }
            k = 0;
        }
    }

    for(int x : ans) cout<<x<<' ';
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