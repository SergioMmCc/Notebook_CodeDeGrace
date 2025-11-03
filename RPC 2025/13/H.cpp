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

void solver(){
    int n; cin>>n;
    vector<int> freq(51);
    for(int i = 0; i < 50*n; i++){
        int num; cin>>num;
        freq[num]++;
    }

    vector<int> ans;
    for(int i = 1; i <= 50; i++){
        if(freq[i] > 2*n){
            ans.pb(i);
        }
    }

    if(ans.empty()){
        cout<<-1<<endl;
        return;
    }
    for(int i = 0; i < ans.sz; i++){
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
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}