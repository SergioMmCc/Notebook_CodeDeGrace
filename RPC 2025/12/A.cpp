#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, l, h; cin>>n>>l>>h;
    vector<vector<bool>> pos(n, vector<bool>(21));
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        for(int j = -10; j <= 10; j++){
            int test = num + j*12;
            if(test >= l && test <= h) pos[i][j+10] = 1;
        }
    }

    //vector<vector<vector<bool>>> dp(n, vector<bool> (n, vector<bool>(21)));
    vector<vector<bool>> check(n, vector<bool> (n));
    for(int i = 0; i < n; i++){
        for(int k = 0; k <= 20; k++){
            for(int j = i; j < n; j++){
                if(pos[j][k]){
                    check[i][j] = 1;
                }
                else break;
            }
        }
    }
    vector<int>DP(n+1,0);
    DP[0]=1'000'000'000;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(check[j][i-1])
                DP[i]=max(DP[i],min(DP[j],i-j));
    cout<<DP[n]<<"\n";
    //for(int i=0;i<n;i++) for(int j=0;j<check[i].size();j++) cout<<"i"<<i<<"j"<<j<<(check[i][j]?"YES\n":"NO\n");
    //for(auto&i:DP)cout<<i<<endl;
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
