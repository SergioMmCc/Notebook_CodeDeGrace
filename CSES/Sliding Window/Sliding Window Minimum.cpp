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

// Para un sliding window de minimos. Complejidad O(n)
ll sw(int n, int k, ll x, ll a, ll b, ll c){
    deque<pii> dq;
    ll last = x;
    ll ans = 0;

    // Insertar los primeros k-1
    for(int i = 0; i < k-1; i++){
        while(!dq.empty() && dq.back().fi >= last) dq.pop_back();
        dq.pb({last, i});

        last = (((a * last) % c) + b) % c;
    }

    for(int i = k-1; i < n; i++){
        if(i - dq.front().se == k) dq.pop_front(); // Elimino el elemento que sale de la ventana

        // Elimino todos los mayores o iguales al nuevo elemento
        while(!dq.empty() && dq.back().fi >= last) dq.pop_back(); 
        dq.pb({last, i});

        // Elemento menor en esta ventana
        ans ^= dq.front().fi;

        last = (((a * last) % c) + b) % c;
    }

    return ans;
}

void solver(){
    int n, k; cin>>n>>k;
    ll x, a, b, c; cin>>x>>a>>b>>c;
    x %= c;
    a %= c;
    b %= c;
    cout<<sw(n, k, x, a, b, c)<<endl;
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