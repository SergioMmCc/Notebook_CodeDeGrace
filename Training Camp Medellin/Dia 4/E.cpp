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

vector<vl> ps(10, vl(1e6 + 1));
void preCalc(){
    vi aux(1e6+1);
    for(int i = 1; i <= 9; i++){
        aux[i] = i;
        ps[i][i] = 1;
    }
    for(int i = 10; i <= 1e6; i++){
        int num = 1, x = i;
        while(x){
            if(x % 10) num *= x % 10;
            x /= 10;
        }

        aux[i] = aux[num];
        ps[aux[i]][i]++;
    }

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 1e6; j++){
            ps[i][j] += ps[i][j-1];
        }
    }
}

void solver(){
    int l, r, d; cin>>l>>r>>d;
    cout<<ps[d][r] - ps[d][l-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    preCalc();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}