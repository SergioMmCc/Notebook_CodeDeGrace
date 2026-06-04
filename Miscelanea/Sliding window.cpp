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
void sw(vi& a, int k){
    int n = sz(a); // Se asume que n >= k
    deque<pii> dq;

    // Insertar los primeros k-1
    for(int i = 0; i < k-1; i++){
        // Elimino todos los mayores o iguales que puse antes
        while(!dq.empty() && dq.back().fi >= a[i]) dq.pop_back();
        dq.pb({a[i], i});
    }

    for(int i = k-1; i < n; i++){
        if(i - dq.front().se == k) dq.pop_front(); // Elimino el elemento que sale de la ventana

        // Elimino todos los mayores o iguales al nuevo elemento
        while(!dq.empty() && dq.back().fi >= a[i]) dq.pop_back(); 
        dq.pb({a[i], i});

        // Elemento menor en esta ventana
        cout<<dq.front().fi<<endl;
    }
}