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

int go(int n, int num, vi& dp, vi& ml, vi& mr, vi& sl, vi& sr){
    if(num == 0) return 0;
    if(dp[num] != -1) return dp[num];

    dp[num] = min(ml[num] + go(n, sr[num], dp, ml, mr, sl, sr), mr[num] + go(n, sl[num], dp, ml, mr, sl, sr));
    return dp[num];
}

void solver(){
    int n; cin>>n;
    vi p(n+1);
    vi r(n+1);
    for(int i = 1; i <= n; i++){
        cin>>p[i];
        r[p[i]] = i;
    }

    vi ml(n+1), mr(n+1);
    set<int> vals; vals.insert(0); vals.insert(n+1);
    for(int i = n; i > 0; i--){
        int idx = r[i];

        auto itr = vals.ub(idx);
        auto itl = vals.ub(idx); --itl;

        ml[i] = idx - *itl - 1;
        mr[i] = *itr - idx - 1;

        vals.insert(idx);
    }

    vi sl(n+1), sr(n+1);
    stack<int> st;
    for(int i = 1; i <= n; i++){
        int last = -1;
        while(!st.empty() && p[i] > st.top()){
            last = st.top();
            st.pop();
        }

        if(last != -1) sl[p[i]] = last;
        if(!st.empty()) sr[st.top()] = p[i];

        st.push(p[i]);
    }
    vi dp(n+1, -1);

    cout<<go(n, n, dp, ml, mr, sl, sr)<<endl;
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