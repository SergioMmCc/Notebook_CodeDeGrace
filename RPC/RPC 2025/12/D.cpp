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
    string s; cin>>s;
    vector<int> a(27);
    for(int i = 0; i < s.sz; i++){
        a[s[i] - 'a']++;
    }

    bool cond = 1, use = 0;
    for(int i = 0; i < 27; i++){
        if(a[i] % 2){
            if(!use) use = 1;
            else{
                cout<<"no"<<endl;
                return;
            }
        }
    }

    cout<<"yes"<<endl;
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