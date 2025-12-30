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
    string s; cin>>s;
    for(int i = 0; i <= n - 4; i++){
        string aux = "";
        for(int j = i; j < i + 4; j++){
            aux += s[j];
        }
        if(aux == "2026"){
            cout<<0<<endl;
            return;
        }
    }
    for(int i = 0; i <= n - 4; i++){
        string aux = "";
        for(int j = i; j < i + 4; j++){
            aux += s[j];
        }
        if(aux == "2025"){
            cout<<1<<endl;
            return;
        }
    }

    cout<<0<<endl;
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