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

ll dp1[53][25][25][25][4][4];
ll dp2[27][25][25][25][4][4];
void init(){
    for(int i = 0; i < 53; i++){
        for(int j = 0; j < 25; j++){
            for(int k = 0; k < 25; k++){
                for(int l = 0; l < 25; l++){
                    for(int m = 0; m < 4; m++){
                        for(int n = 0; n < 4; n++){
                            dp1[i][j][k][l][m][n] = -1;
                            if(i < 27) dp2[i][j][k][l][m][n] = -1;
                        }
                    }
                }
            }
        }
    }
}

ll go1(int idx, int c1, int c2, int c3, int last, int last2, int n, int d){
    if(c1 >= 25 || c2 >= 25 || c3 >= 25) return 0;
    if(dp1[idx][c1][c2][c3][last][last2] != -1) return dp1[idx][c1][c2][c3][last][last2];
    if(idx == n){
        int mini = min(c1, min(c2, c3));
        int maxi = max(c1, max(c2, c3));
        dp1[idx][c1][c2][c3][last][last2] = maxi - mini <= d ?  1 : 0;
    }

    else{
        dp1[idx][c1][c2][c3][last][last2] = 0;
        if(last != 1) dp1[idx][c1][c2][c3][last][last2] += go1(idx+1, c1+1, c2, c3, 1, last, n, d);
        if(last != 3) dp1[idx][c1][c2][c3][last][last2] += go1(idx+1, c1, c2, c3+1, 3, last, n, d);
        if(last != 2 || last2 != 2) dp1[idx][c1][c2][c3][last][last2] += go1(idx+1, c1, c2+1, c3, 2, last, n, d);
    }

    return dp1[idx][c1][c2][c3][last][last2];
}

ll go2(int idx, int c1, int c2, int c3, int last, int last2, int n, int d){
    if(c1 >= 25 || c2 >= 25 || c3 >= 25) return 0;
    if(dp2[idx][c1][c2][c3][last][last2] != -1) return dp2[idx][c1][c2][c3][last][last2];
    if(idx == ((n + 1) / 2)){
        int mini = min(c1, min(c2, c3));
        int maxi = max(c1, max(c2, c3));
        dp2[idx][c1][c2][c3][last][last2] = maxi - mini <= d ?  1 : 0;
    }

    else{
        dp2[idx][c1][c2][c3][last][last2] = 0;
        int add = (n & 1) && (n / 2 == idx) ? 1 : 2;
        if(last != 1 && ((n & 1) || idx != n/2 - 1)) dp2[idx][c1][c2][c3][last][last2] += go2(idx+1, c1+add, c2, c3, 1, last, n, d);
        if(last != 3 && ((n & 1) || idx != n/2 - 1)) dp2[idx][c1][c2][c3][last][last2] += go2(idx+1, c1, c2, c3+add, 3, last, n, d);
        if(last != 2 || (last2 != 2 && add == 2 && ((n & 1) || idx != n/2 - 1))) dp2[idx][c1][c2][c3][last][last2] += go2(idx+1, c1, c2+add, c3, 2, last, n, d);
    }

    return dp2[idx][c1][c2][c3][last][last2];
}

void solver(){
    int n, d; cin>>n>>d;
    ll ans = go1(0, 0, 0, 0, 0, 0, n, d);
    ll take = go2(0, 0, 0, 0, 0, 0, n, d);
    cout<<ans - take<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    init();
    while(t--){
        solver();
    }

    return 0;
}