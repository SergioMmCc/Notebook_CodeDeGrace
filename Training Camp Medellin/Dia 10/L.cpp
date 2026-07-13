#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
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

int ask(int l, int r){
    cout<<"? "<<l<<' '<<r<<endl;
    int res; cin>>res;
    return res;
}

void ans(int k){
    cout<<"! "<<k<<endl;
}


void solver(){
    int n; cin>>n;
    int r1 = ask(1, n/4), r2 = ask(n/4 + 1, n/2), r3 = ask(n/2 + 1, 3*(n/4));

    if(r1 + r2 + r3 > 1){ // k < n/4
        int l = 0, r = n/4;
        if(!r1){
            l = r;
            r = n/2;
        }
        
        int lo = 1, hi = n/4;
        while(lo < hi){
            int m = (lo + hi) / 2;
            if(ask(1 + l, l + m)) hi = m;
            else lo = m + 1;
        }

        ans(lo);
        return;
    }

    int l, r;
    if(r1) l = 0;
    else if(r2) l = n/4;
    else if(r3) l = n/2;
    else l = 3*(n/4);

    int lo = n/4, hi = n;
    while(lo < hi){
        int m = (lo + hi) / 2;
        int aux1 = l+1, aux2 = l + m;
        if(aux2 > n){
            aux2 = n;
            aux1 = n - m + 1; // +1
        }

        if(!ask(aux1, aux2)) hi = m;
        else lo = m+1;
    }

    ans(lo);
}


signed main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}