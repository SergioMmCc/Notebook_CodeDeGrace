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

bool process(int idx, int jdx, int n, int m, string& s, string& t){
    while(jdx < m){
        while(idx < n && s[idx] != t[jdx]) idx += 2;
        if(idx >= n){
            return 0;
        }
        jdx++;
        idx++;
    }

    return (n - idx) % 2 == 0;
}

void solver(){
    string s, t; cin>>s>>t;
    int n = sz(s), m = sz(t);
    int idx = 0, kdx = 1, jdx = 0;
    while(idx < n && s[idx] != t[0]) idx += 2;
    while(kdx < n && s[kdx] != t[0]) kdx += 2;
    if(idx < n && process(idx, jdx, n, m, s, t)) cout<<"YES"<<endl;
    else if(kdx < n && process(kdx, jdx, n, m, s, t)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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