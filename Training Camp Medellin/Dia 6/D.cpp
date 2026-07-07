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

pll calcMexes(vl& a){
    set<ll> used;
    for(ll x : a) used.insert(x);
    ll mex = 0;
    for(ll i = 0; i <= sz(a); i++){
        if(used.find(i) == used.end()){
            mex = i;
            break;
        }
    }

    used.insert(mex);
    ll mex2 = 0;
    for(ll i = 0; i <= sz(a) + 1; i++){
        if(used.find(i) == used.end()){
            mex2 = i;
            break;
        }
    }

    return {mex, mex2};
}

void solver(){
    int n; cin>>n;
    vector<vl> nums(n);
    vector<map<ll, ll>> freq(n);
    vll mexes(n);
    ll sumex = 0;
    int maxxEle = 0;
    for(int i = 0; i < n; i++){
        int cnt; cin>>cnt;
        maxxEle = max(maxxEle, cnt);
        for(int j = 0; j < cnt; j++){
            ll aux; cin>>aux;
            nums[i].pb(aux);
            freq[i][aux]++;
        }

        mexes[i] = calcMexes(nums[i]);
        sumex += mexes[i].fi;
    }

    vl altMexes(maxxEle + 1);
    vl freqMex(maxxEle + 1);
    for(pll x : mexes){
        altMexes[x.fi] += x.se;
        freqMex[x.fi]++;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(ll x : nums[i]){
            ans += sumex * ((ll)n-1);
            if(mexes[i].fi > x && freq[i][x] == 1){ // Seria el MEX
                ans += (x - mexes[i].fi) * ((ll)n-1);
            }
            if(x < sz(altMexes)) ans += altMexes[x] - x * freqMex[x];
        }
    }

    cout<<ans<<endl;
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