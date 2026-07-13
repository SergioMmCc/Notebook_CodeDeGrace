#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define db(x) cerr<< #x<<" "<<x<<endl
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
#define print(arr) for(auto val : arr){ cout << val << " "; } cout << '\n';

void solver(){
    string s; cin>>s;
    int n = sz(s);
    int l = 0, r = n-1;
    string aux1 = "", aux2 = "";
    int cnt = 0, lim = n / 2;
    while(l <= r && cnt < lim){
        if(l == r){
            cnt++;
            aux1 += s[l];
            continue;
        }

        if(s[l] != s[r]){
            if(s[l + 1] == s[r]) l++;
            else if(s[l] == s[r-1]) r--;
            else l++, r--;
        }

        if(l == r){
            aux1 += s[l];
            cnt++;
            l++;
            r--;
            continue;
        }
        aux1 += s[l];
        aux2 += s[r];
        cnt += 2;
        l++;
        r--;
    }

    reverse(all(aux2));
    cout<<aux1<<aux2<<endl;
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