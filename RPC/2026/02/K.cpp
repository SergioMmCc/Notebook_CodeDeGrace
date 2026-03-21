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
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<bool, pii> pbii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pbii> vbii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    string s; cin>>s;
    int n = sz(s);
    vi mnapp(26, n), mxapp(26, -1);
    for(int i = 0; i < n; i++) mxapp[s[i] - 'a'] = i;
    for(int i = n-1; i >= 0; i--) mnapp[s[i] - 'a'] = i;

    vector<vb> dp1(n, vb(n)), dp2(n, vb(n));
    vector<vii> add(n, vii(n));

    for(int i = 0; i < n; i++){
        dp1[i][i] = dp2[i][i] = 1;
        if(i){
            if(s[i-1] == s[i]) dp1[i-1][i] = dp2[i-1][i] = 1;
            else{
                int a = s[i-1] - 'a', b = s[i] - 'a';
                add[i-1][i] = {a, b};
            }
        }
    }

    for(int len = 2; len < n; len++){
        for(int i = 0; i + len < n; i++){
            int j = i+len;
            if(s[i] == s[j]){
                dp1[i][j] = dp1[i+1][j-1];
                dp2[i][j] = dp2[i+1][j-1];
                add[i][j] = add[i+1][j-1];
            }
            else{
                int a = s[i] - 'a', b = s[j] - 'a';
                if(dp1[i+1][j-1]){
                    if(((len & 1) == 0) && (s[i + len/2] - 'a' == a || s[i + len/2] - 'a' == b)){
                        dp2[i][j] = 1;
                        add[i][j] = {a, b};
                    }
                    else if(mnapp[a] < i || mnapp[b] < i || mxapp[a] > j || mxapp[b] > j){
                        add[i][j] = {a, b};
                    }
                }
                else{
                    if((a == add[i+1][j-1].fi && b == add[i+1][j-1].se) || (b == add[i+1][j-1].fi && a == add[i+1][j-1].se)){
                        dp2[i][j] = 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(dp1[i][j] || dp2[i][j]) ans = max(ans, j-i+1);
            else if(add[i][j].fi != add[i][j].se){
                int a = add[i][j].fi, b = add[i][j].se;
                if(mnapp[a] < i || mnapp[b] < i || mxapp[a] > j || mxapp[b] > j){
                    ans = max(ans, j-i+1);
                }
            }
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