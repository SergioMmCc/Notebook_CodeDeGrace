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

void balance(set<pii>& mini, set<pii>& maxi){
    if(sz(maxi) > sz(mini)){
        pii aux = (*maxi.begin());
        maxi.erase(aux);
        mini.insert(aux);
    }
    else if(sz(mini) > sz(maxi) + 1){
        pii aux = (*mini.rbegin());
        mini.erase(aux);
        maxi.insert(aux);
    }
}

void solver(){
    int q; cin>>q;
    set<pii> maxi, mini;
    for(int i = 0; i < q; i++){
        int op; cin>>op;
        if(op == 1){
            int val; cin>>val;
            
            if(mini.empty() || val <= (*mini.rbegin()).fi) mini.insert({val, i});
            else maxi.insert({val, i});

            balance(mini, maxi);
        }
        else if(op == 2){
            int val; cin>>val;
            auto it = mini.lb({val, 0});
            if(it != mini.end() && (*it).fi == val) mini.erase(it);
            else{
                it = maxi.lb({val, 0});
                if(it != maxi.end() && (*it).fi == val) maxi.erase(it);
            }

            balance(mini, maxi);
        }
        else{
            if(sz(maxi) == sz(mini)){
                if(mini.empty()) cout<<"Empty!"<<endl;
                else cout<<((*mini.rbegin()).fi + (*maxi.begin()).fi) / 2<<endl;
            }
            else cout<<(*mini.rbegin()).fi<<endl;
        }
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