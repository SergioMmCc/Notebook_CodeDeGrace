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

int base(int n, int b){
    int ans = 0;
    int aux = n;
    int pot = 1;
    while(aux){
        if(aux % 10 >= b) return 0;
        ans += pot * (aux % 10);
        aux /= 10;
        pot *= b;
    }

    return ans;
}

void solver(){
    int x, y, s; cin>>x>>y>>s;
    for(int i = 2; i <= 10; i++){
        for(int j = 2; j <= 10; j++){
            int a = base(x, i), b = base(y, j);
            if(a && b && a + b == s){
                cout<<i<<' '<<j<<endl;
                return;
            }
        }
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