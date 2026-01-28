#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, q; cin>>n>>q;

    vector<vector<int>> task(n+1);
    set<int> used;
    int count = 1;
    while(q--){
        int op, x; cin>>op>>x;
        if(op == 1){
            task[x].pb(count);
            used.insert(count);
            count++;
        }
        else if(op == 2){
            while(!task[x].empty()){
                int del = task[x].back();
                task[x].pop_back();
                if(used.find(del) != used.end()) used.erase(del);
            }
        }
        else while(!used.empty() && *used.begin() <= x) used.erase(used.begin());

        cout<<used.sz<<endl;
    }
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