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

// Same solution for D1 and D2

int cnt = 0;

bool ask(set<int>& s){
    if(sz(s) <= 2) return 1;

    cnt++;
    assert(cnt <= 33);

    cout<<"? "<<sz(s);
    for(int x : s) cout<<' '<<x;
    cout<<endl;

    int re; cin>>re;
    return (re & 1) == (sz(s) & 1);
}

void ans(int x, int y, int z){
    cout<<"! "<<z<<' '<<y<<' '<<x<<endl;
}

set<int> merge(set<int>& a, set<int>& b){
    set<int> ret;
    for(int x : a) ret.insert(x);
    for(int x : b) ret.insert(x);

    return ret;
}

void solver(){
    int n; cin>>n;


    set<int> s;
    // Find primero
    int lo = 1, hi = 2*n + 1;
    while(lo < hi){
        int m = (lo + hi) / 2;
        set<int> add;
        for(int i = lo; i <= m; i++) add.insert(i);
        set<int> aux = merge(s, add);
        if(ask(aux)){ // Afuera hay
            s = aux;
            lo = m+1;
        }
        else{
            hi = m;
        }
    }

    int x = lo;

    s.clear();
    s.insert(x);

    // Find segundo
    lo = 1, hi = x-1;
        while(lo < hi){
        int m = (lo + hi) / 2;
        set<int> add;
        for(int i = lo; i <= m; i++) add.insert(i);
        set<int> aux = merge(s, add);
        if(ask(aux)){ // Afuera hay
            s = aux;
            lo = m+1;
        }
        else{
            hi = m;
        }
    }

    int y = lo;

    s.clear();
    s.insert(y); s.insert(x);

    lo = 1, hi = y-1;
        while(lo < hi){
        int m = (lo + hi) / 2;
        set<int> add;
        for(int i = lo; i <= m; i++) add.insert(i);
        set<int> aux = merge(s, add);
        if(ask(aux)){ // Afuera hay
            s = aux;
            lo = m+1;
        }
        else{
            hi = m;
        }
    }

    int z = lo;

    ans(x, y, z);
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        cnt = 0;
        solver();
    }

    return 0;
}