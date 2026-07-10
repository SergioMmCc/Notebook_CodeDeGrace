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

void solver(){
    int n, m; cin>>n>>m;
    vs maze(n);
    for(int j = 0; j < m; j++){
        if(j % 2 == 0) maze[0] += '1';
        else maze[0] += '0';
    }
    maze[n-1] = maze[0];

    for(int i = 1; i < n-1; i++){
        if(i & 1){
            for(int j = 0; j < m; j++) maze[i] += '0';
        }
        else{
            if(i != n-2){
                maze[i] += '1';
            }
            else maze[i] += '0';
            for(int j = 1; j < m-1; j++){
                maze[i] += '0';
            }
            if(i != n-2){
                maze[i] += '1';
            }
            else maze[i] += '0';
        }
    }

    for(int i = 0; i < n; i++) cout<<maze[i]<<endl;
    cout<<endl;
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