#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    string s; cin>>s;
    vi a;
    for(int i = 0; i < sz(s); i++){
        if(s[i] == ',') continue;
        bool cond = s[i] == '-';
        if(cond) i++;
        int num = 0;
        while(i < sz(s) && (int)s[i] >= '0' && (int)s[i] <= '9'){
            num *= 10;
            num += s[i] - '0';
            i++;
        }

        if(!num) continue;
        // if(cond) num *= -1;
        a.pb(num);
    }

    // n = sz(a);
    // for(int i = 0; i < n; i++) cout<<a[i]<<endl;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[j] % a[i] != 0 && a[i] % a[j] != 0){
                cout<<"NOT FRIENDS"<<endl;
                return;
            }
        }
    }

    cout<<"FRIENDS"<<endl;
}

signed main(){
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