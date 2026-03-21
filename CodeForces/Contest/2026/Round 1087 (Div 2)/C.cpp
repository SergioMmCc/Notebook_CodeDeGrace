#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
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

int ask(int a, int b){
    cout<<"? "<<a<<' '<<b<<endl;
    int r; cin>>r;
    return r;
}

void ans(int a){
    cout<<"! "<<a<<endl;
}

void solver(){
    int n; cin>>n;
    for(int i = 5; i < 2*n; i += 2){
        int r = ask(i, i+1);
        if(r){
            ans(i);
            return;
        }
    }

    int r = ask(1, 3);
    if(r) ans(1);
    else{
        r = ask(1, 4);
        if(r) ans(1);
        else{
            r = ask(3, 4);
            if(r) ans(3);
            else ans(2);
        }
    }
}

int main(){
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