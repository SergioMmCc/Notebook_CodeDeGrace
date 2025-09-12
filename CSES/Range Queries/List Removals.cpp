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
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ordered_set = 
    tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    ordered_set nums;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        nums.insert({i, save});
    }

    for(int i = 0; i < n; i++){
        int del; cin>>del; del--;
        auto it = nums.find_by_order(del);
        if(i) cout<<' ';
        cout<<(*it).se;
        nums.erase(it);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}