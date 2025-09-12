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
    int n, q; cin>>n>>q;
    ordered_set emp;
    vector<int> sal(n);
    for(int i = 0; i < n; i++){
        cin>>sal[i];
        emp.insert({sal[i], i});
    }

    while(q--){
        char op; int a, b; cin>>op>>a>>b;
        if(op == '!'){
            a--;
            emp.erase({sal[a], a});
            sal[a] = b;
            emp.insert({sal[a], a});
        }
        else{
            int num = emp.order_of_key({b+1, 0}) - emp.order_of_key({a, -1});
            cout<<num<<endl;
        }
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