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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

ll binom[61][61];
void calcBinom(){
    for(int i = 0; i < 61; i++) binom[i][i] = binom[i][0] = 1LL;
    for(int i = 1; i < 61; i++){
        for(int j = 1; j < i; j++){
            binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
        }
    }
}

void solver(int n, int k){
    vector<int> perm(n);
    for(int i = 0; i < k; i++) cin>>perm[i];

    ll l = 0;
    int last = 1;
    for(int i = 0; i < k; i++){
        for(int j = last; j <= n; j++){
            if(j == perm[i]){
                last = j + 1;
                break;
            }
            l += binom[n - j][k - i - 1];
        }
    }

    cout<<l<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    calcBinom();
    int n, k;
    while(cin>>n>>k){
        solver(n, k);
    }

    return 0;
}