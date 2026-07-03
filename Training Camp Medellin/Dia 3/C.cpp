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
typedef pair<ll, pii> plii;
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
    int n, k; cin>>n>>k;
    vl a(n);
    ll ans = 0;
    pqueue<plii> pq;
    for(int i = 0; i < n; i++){
        ll num; cin>>num;
        a[i] = num;
        ans += num * num;
        ll m1 = num / 2, m2 = (num+1) / 2;
        pq.push({num*num - (m1*m1 + m2*m2), {1, i}});
        k--;
    }

    while(k > 0){
        plii aux = pq.top(); pq.pop();
        ans -= aux.fi;
        ll ori = a[aux.se.se];
        ll parts = aux.se.fi + 1;

        ll f = ori / parts, c = (ori + parts - 1) / parts;
        ll mod = ori % parts;
        ll last = (parts - mod) * f * f + mod * c * c;

        parts++;
        f = ori / parts, c = (ori + parts - 1) / parts;
        mod = ori % parts;
        ll next = (parts - mod) * f * f + mod * c * c;
        parts--;

        ll take = last - next;
        pq.push({take, {parts, aux.se.se}});

        k--;
    }

    cout<<ans<<endl;
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