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

void add(multiset<int>& sm, multiset<int>& bi, int num){
    if(sm.empty()){
        sm.insert(num);
        return;
    }
    
    bi.insert(num);

    if(*sm.rbegin() > *bi.begin()){
        bi.insert(*sm.rbegin());
        auto aux = sm.end(); sm.erase(--aux);

        sm.insert(*bi.begin());
        bi.erase(bi.begin());
    }

    if(sz(bi) > sz(sm)){
        sm.insert(*bi.begin());
        bi.erase(bi.begin());
    }
}

void solver(){
    int n, k; cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    multiset<int> sm, bi;

    for(int i = 0; i < k - 1; i++) add(sm, bi, a[i]);
    
    for(int i = k-1; i < n; i++){
        add(sm, bi, a[i]);

        cout<<(i >= k ? " " : "");
        cout<<*sm.rbegin();

        int del = a[i - k + 1];
        if(del <= *sm.rbegin()){
            sm.erase(sm.find(del));
            if(sz(bi) > sz(sm)){
                sm.insert(*bi.begin());
                bi.erase(bi.begin());
            }
        }

        else{
            bi.erase(bi.find(del));
            if(sz(sm) - 1 > sz(bi)){
                bi.insert(*sm.rbegin());
                auto aux = sm.end(); sm.erase(--aux);
            }
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}