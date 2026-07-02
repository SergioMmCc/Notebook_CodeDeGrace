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

bool check(set<int>& a, set<int>& b){
    int cnt = 0;
    for(int x : a) if(b.find(x) != b.end()) cnt++;
    if(!cnt || (cnt == sz(a) && cnt == sz(b))) return 1;
    return 0;
}

void solver(){
    int n, m; cin>>n>>m;
    vector<set<int>> nums(n);
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        for(int j = 0; j < m; j++) if(s[j] == '#') nums[i].insert(j);
    }

    bool cond = 1;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            cond = check(nums[i], nums[j]);
            if(!cond){
                cout<<"No"<<endl;
                return;
            }
        }
    }

    cout<<"Yes"<<endl;
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