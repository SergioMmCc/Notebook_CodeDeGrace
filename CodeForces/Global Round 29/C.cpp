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

bool check(string s){
    int n = s.sz;
    if(n == 1 || n % 2 == 0) return 1;
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') count++;
    }

    if(count == n / 2 + 1 && count % 2 == 0) return 0;
    return 1;
}

void solver(){
    int n; string s; cin>>n>>s;
    string aux = "";
    bool cond = 1;
    for(int i = 0; cond && i < n; i++){
        aux += s[i];
        if(s[i] == '1' && (i == n - 1 || s[i+1] == '1')){
            cond = check(aux);
            aux = "";
        }
    }

    cout<<(cond ? "YES" : "NO")<<endl;
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