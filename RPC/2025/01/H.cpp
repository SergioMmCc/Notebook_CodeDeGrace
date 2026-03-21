#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl '\n'
#define int long long
typedef pair<int, int> pii;

using ordered_set = 
    tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    ordered_set pos;
    set<pii> birds;

    for(int i = 0; i < n; i++){
        int nBirds; cin>>nBirds;
        for(int j = 0; j < nBirds; j++){
            int finish; cin>>finish;
            pos.insert({finish, i});
            birds.insert({i, finish});
        }
    }

    int ans = 0;
    for(pii bird : birds){
        int start = bird.first, finish = bird.second;
        ans += pos.order_of_key({finish, start});
        pos.erase({finish, start});
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}