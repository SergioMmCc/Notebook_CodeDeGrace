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

void answer(vb& ans){
    for(int i = 0; i < sz(ans); i++) cout<<(ans[i] ? 1 : 0);
    cout<<endl;
}

void solver(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vb ans(n);

    int cntl = 0, cntr = 0;
    vi save;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            cntl++;
            save.pb(i);
        }
        else cntr++;

        if(cntl <= cntr){
            while(k && !save.empty()){
                ans[save.back()] = 1;
                save.pop_back();
                k--;
            }

            if(!k){
                answer(ans);
                return;
            }
            cntl = 0, cntr = 0;
        }
    }

    save.clear();
    cntl = 0, cntr = 0;
    for(int i = n-1; i >= 0; i--){
        if(ans[i]) continue;
        if(s[i] == '(') cntl++;
        else{
            cntr++;
            save.pb(i);
        }

        if(cntr <= cntl){
            while(k && !save.empty()){
                ans[save.back()] = 1;
                save.pop_back();
                k--;
            }

            if(!k){
                answer(ans);
                return;
            }
            cntl = 0, cntr = 0;
        }
    }

    answer(ans);
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