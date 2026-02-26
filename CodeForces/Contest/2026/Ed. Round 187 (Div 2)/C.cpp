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

vi func(ll x){
    vi ans;
    ll aux  = x;
    int bit = 0;
    while(aux){
        if(aux & 1) ans.pb(bit);
        bit++;
        aux >>= 1;
    }

    return ans;
}

bool can(ll k, vl cnt, vi& bm){
    for(int i = sz(bm)-1; i > 0; i--){
        if(cnt[bm[i]] <= k) continue;
        ll take = cnt[bm[i]] - k;
        // if(k == 5) cout<<"i -> "<<i<<" cnti -> "<<cnt[bm[i]]<<" cnti-1 -> "<<cnt[bm[i-1]];
        cnt[bm[i-1]] += take * (1LL << (bm[i] - bm[i-1]));
        // if(k == 5) cout<<" take -> "<<take<<" cnti-1 -> "<<cnt[bm[i-1]]<<endl;
    }

    return cnt[bm[0]] <= k;
}

void solver(){
    ll s, m; cin>>s>>m;
    vi bs = func(s);
    vi bm = func(m);


    vl cnt(64);
    for(int b : bs){
        auto it = ub(all(bm), b);
        if(it == bm.begin()){
            cout<<-1<<endl;
            return;
        }

        --it;
        int idx = *it;
        cnt[idx] += 1LL << (b - idx);
    }

    // for(int i = 0; i < sz(bm); i++) cout<<"i -> "<<i<<" bm -> "<<bm[i]<<" cnt -> "<<cnt[bm[i]]<<endl;

    ll l = 1, r = s;
    while(l < r){
        ll k = (l + r) / 2;
        if(can(k, cnt, bm)) r = k;
        else l = k + 1;

        // for(int i = 0; i < sz(bm); i++) cout<<"i -> "<<i<<" bm -> "<<bm[i]<<" cnt -> "<<cnt[bm[i]]<<endl;
    }
    cout<<r<<endl;
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