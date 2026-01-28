#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
using ll=long long;
using ld=long double;
using pll=pair<ll,ll>;
using vl=vector<ll>;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
template<class T>
using ordered_multiset = tree<
    pair<T, ll>,
    null_type,
    less<pair<T, ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
template<class Key, class Value>
using ordered_map = tree<
    Key,
    Value,
    less<Key>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
template<class Key, class Value>
using ordered_multimap = tree<
    pair<Key, ll>,
    Value,
    less<pair<Key, ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 
template<class T> using MAXPQ = priority_queue<T>;
template<class T> using MINPQ = priority_queue<T, vector<T>, greater<T>>;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(), (x).end()
#define BS(c,v) binary_search(ALL(c), v)
#define GE(c,v) lower_bound(ALL(c), v)
#define GT(c,v) upper_bound(ALL(c), v)
#define LE(c,v) ((GT(c,v) == (c).begin()) ? (c).end() : GT(c,v) - 1)
#define LT(c,v) ((GE(c,v) == (c).begin()) ? (c).end() : GE(c,v) - 1)
#define I_GE(c,v) ll((GE(c,v)) - (c).begin())
#define I_GT(c,v) ll((GT(c,v)) - (c).begin())
#define I_LE(c,v) ll(I_GT(c,v) > 0 ? I_GT(c,v) - 1 : -1)
#define I_LT(c,v) ll(I_GE(c,v) > 0 ? I_GE(c,v) - 1 : -1)
 
#define UNION(a,b,c) set_union(ALL(a), ALL(b), inserter((c), (c).begin()))
#define INTER(a,b,c) set_intersection(ALL(a), ALL(b), inserter((c), (c).begin()))
#define DIFF(a,b,c) set_difference(ALL(a), ALL(b), inserter((c), (c).begin()))
#define HAS(c, x) (c).find(x) != (c).end()

#define FOR(i,x,y) for(ll i=x; i<=y; i++)
#define FORR(i,x,y) for(ll i=x; i>=y; i--)
 
#define POPCOUNT(x) __builtin_popcountll(x)
#define CLZ(x) __builtin_clzll(x)
#define CTZ(x) __builtin_ctzll(x)
#define FFS(x) __builtin_ffsll(x)

#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a)/GCD(a,b)*(b))
#define PI (acos(-1.0L))
#define MED3(a,b,c) __median(a,b,c)
#define LOG2(x) __lg(x)
 
#define LSBMASK(s) ((s) & -(s))
 
const ll PINF_int = numeric_limits<ll>::max();
const ll NINF_int = numeric_limits<ll>::min();
const ld PINF_float = numeric_limits<ld>::max();
const ld NINF_float = numeric_limits<ld>::lowest();
const ld EPS = numeric_limits<ld>::epsilon();
 
const ll MOD = 1000000007;
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((a % m) - (b % m) + m) % m; }
ll mod_mult(ll a, ll b, ll m) {
    a %= m, b %= m;
    if (a <= PINF_int/ b)
        return ((a % m) * (b % m)) % m;
    ll ans = 0;
    while (b > 0) {
        if (b & 1) ans = mod_add(ans, a, m);
        a = mod_add(a, a, m);
        b >>= 1;
    }
    return ans;
}
ll mod_pow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mod_mult(res, a, m);
        a = mod_mult(a, a, m);
        b >>= 1;
    }
    return res;
}
 
bool chmin(ll& a, ll b) {return b < a ? a = b, true : false;}
bool chmax(ll& a, ll b) {return b > a ? a = b, true : false;}

void solver(){
    ll n,m;cin>>n>>m;
    vector<ll>v(m);
    ll acc=0;
    for(auto&i:v){
        cin>>i;
        acc+=i;
    }
    if(acc<n){
        cout<<"-1\n";
        return;
    }
    vector<ll>ans;
    FOR(i,0,m-1){
        if(v[i]>n-i){
            cout<<"-1\n";
            return;
        }
        ans.PB(n-i-v[i]+1);
    }
    ll last=1,idx=m-1;
    while(true){
        if(last>=ans[idx])
            break;
        ans[idx]=last;
        last+=v[idx];
        idx--;
    }
    FOR(i,0,m-1) cout<<(i?" ":"")<<ans[i];
    cout<<"\n";
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;//cin>>t;
    while(t--)solver();
}