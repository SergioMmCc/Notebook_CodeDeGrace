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

void ans(vii& edj){
    cout<<"! "<<sz(edj)<<endl;
    for(pii e : edj) cout<<e.fi<<' '<<e.se<<endl;
}

vi ask(int k){
    cout<<"? "<<k<<endl;
    int q; cin>>q;
    vi a(q);
    for(int i = 0; i < q; i++) cin>>a[i];
    return a;
}

void solver(){
    int n; cin>>n;

    // Cuantos caminos empiezan en i
    vi fin(n+1);
    for(int i = 1; i <= n; i++){
        int l = fin[i-1] + 1, r = (1 << 30);
        while(l < r){
            int k = (l + r + 1) / 2;
            vi aux = ask(k);
            if(aux.empty() || aux[0] != i){
                r = k-1;
            }
            else l = k;
        }

        fin[i] = l;
    }

    // for(int i = 1; i <= n; i++) cout<<"i -> "<<i<<" fin[i] -> "<<fin[i]<<endl;

    // Hallar las aristas que empiezan en i
    vii edj;
    for(int i = 1; i <= n; i++){
        if(fin[i] == fin[i-1] + 1) continue; // Ninguna arista empieza en i
        
        int k = fin[i-1] + 2;
        while(k <= fin[i]){
            vi aux = ask(k);

            assert(sz(aux) > 1);

            int v = aux[1];
            edj.pb({i, aux[1]});
            k += fin[v] - fin[v-1];
        }
    }

    ans(edj);
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