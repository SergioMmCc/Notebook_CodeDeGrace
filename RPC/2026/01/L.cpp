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

    map<char, int> T;
    T['A'] = 1;
    T['B'] = 2;
    T['C'] = 3;
    T['D'] = 4;
    T['E'] = 5;
    T['F'] = 6;
    T['G'] = 7;
    T['H'] = 8;
    T['I'] = 9;
    T['J'] = 10;

    vector<pair<int, pii>> r(m);
    for(int i = 0; i < m; i++){
        char x, y;
        int o, a, b; cin>>o>>x>>y;
        a = T[x];
        b = T[y];

        r[i] = {o, {a, b}};
    }

    vi p(n);
    for(int i = 0; i < n; i++) p[i] = i+1;

    int ans = 0;
    do{
        vi aux(n+1);
        for(int i = 0; i < n; i++) aux[p[i]] = i;
        bool cond = 1;
        for(int i = 0; cond && i < m; i++){
            int o = r[i].fi, a = r[i].se.fi, b = r[i].se.se;

            if(o == 1) cond = aux[a] < aux[b];
            else if(o == 2) cond = aux[a] > aux[b];
            else cond = aux[a] != aux[b] + 1 && aux[a] != aux[b] - 1;
        }
        if(cond) ans++;
        
    } while(next_permutation(all(p)));

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