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
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

bool query(int x, int y){
    cout<<"? "<<x<<' '<<y<<endl;
    char xx; cin>>xx;
    return xx == 'x';
}

void ans(int a){
    cout<<"! "<<a<<endl;
}

void solver(){
    bool cond;
    int l = 1, r = 2;
    cond = query(l, r);
    if(cond){
        cond = query(0, 1);
        ans(cond ? 1 : 2);
        return;
    }

    while(!cond){
        l <<= 1, r <<= 1;
        cond = query(l, r);
    }

    while(l + 1 < r){
        int m = (l + r) / 2;
        cond = query(m, r);
        if(cond) l = m;
        else r = m;
    }

    ans(r);
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    string t;
    while(cin>>t && t == "start"){
        solver();
    }

    return 0;
}