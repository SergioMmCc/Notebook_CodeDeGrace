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
    string s; cin>>s;
    int n = sz(s);

    int ans = 0;
    for(int i = 0; i < (n + 1) / 2; i++){
        if(s[i] == '0' && s[n-i-1] != '0') ans++;
        if(s[i] == '1' && s[n-i-1] != '1') ans++;
        if(s[i] == '2' && s[n-i-1] != '2') ans++;
        if(s[i] == '3' && s[n-i-1] != 'E') ans++;
        if(s[i] == 'E' && s[n-i-1] != '3') ans++;
        if(s[i] == '5' && s[n-i-1] != '5') ans++;
        if(s[i] == '6' && s[n-i-1] != '9') ans++;
        if(s[i] == '9' && s[n-i-1] != '6') ans++;
        if(s[i] == '8' && s[n-i-1] != '8') ans++;

        if(s[i] == '4' || s[i] == '7' || s[i] == 'A' || s[i] == 'F' || s[i] == 'b' || s[i] == 'd' || s[i] == 'C'){
            if(s[n-i-1] == '4' || s[n-i-1] == '7' || s[n-i-1] == 'A' || s[n-i-1] == 'F' || s[n-i-1] == 'b' || s[n-i-1] == 'd' || s[n-i-1] == 'C') ans += 2;
            else ans++;
        }
    }

    cout<<ans<<endl;
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