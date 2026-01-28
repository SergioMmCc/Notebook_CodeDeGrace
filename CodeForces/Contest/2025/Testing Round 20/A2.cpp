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

const int maxi = 1e9;

void solver(){
    string op; cin>>op;
    if(op == "first"){
        int n; cin>>n;
        string encode = "";
        for(int i = 0; i < n; i++){
            int num; cin>>num;
            if(num == maxi){
                encode += "yz";
                continue;
            }
            string add = "";
            while(num > 0){
                add += char('a' + (num % 10));
                num /= 10;
            }

            reverse(all(add));
            add += 'z';
            encode += add;
        }

        cout<<encode<<endl;
    }
    else{
        string s; cin>>s;
        vector<int> ans;
        int i = 0;
        while(i < sz(s)){
            int add = 0;
            if(s[i] == 'y'){
                ans.pb(maxi);
                i += 2;
                continue;
            }
            while(s[i] != 'z'){
                add *= 10;
                add += s[i] - 'a';
                i++;
            }

            ans.pb(add);
            i++;
        }

        cout<<sz(ans)<<endl;
        for(int i = 0; i < sz(ans); i++){
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
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