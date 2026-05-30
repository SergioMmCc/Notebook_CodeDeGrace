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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int strToInt(string s){
    int ans = 0, pot = 1;
    for(int i = sz(s) - 1; i >= 0; i--){
        ans += pot * (s[i] - '0');
        pot *= 10;
    }

    return ans;
}

void solver(){
    int n; cin>>n;
    int mx = 10;
    for(int i = 0; i < n; i++){
        string aux; cin>>aux;
        if(aux == "/"){
            cout<<mx<<endl;
            continue;
        }

        int val = strToInt(aux);
        cout<<val<<endl;
        val = val / 10 + 1;
        val *= 10;
        mx = max(mx, val);
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