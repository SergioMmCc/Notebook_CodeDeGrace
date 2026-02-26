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

void solver(){
    int n, m; cin>>n>>m;
    set<int> a;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        a.insert(num);
    }

    vi b(m);
    for(int i = 0; i < m; i++) cin>>b[i];

    vi mark(n+m+1);
    for(int x : a) for(int aux = x; aux <= n+m; aux += x) mark[aux]++;

    int al = 0, bo = 0, co = 0;
    for(int x : b){
        if(!mark[x]) bo++;
        else if(mark[x] == sz(a)) al++;
        else co++;
    }

    if(co & 1) bo--;
    cout<<(al > bo ? "Alice" : "Bob")<<endl;
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