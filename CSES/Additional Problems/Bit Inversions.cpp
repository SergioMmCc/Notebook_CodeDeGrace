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
    string s; cin>>s;
    int n = sz(s);
    vb a(n + 1);
    for(int i = 0; i < n; i++) a[i+1] = s[i] == '1';

    set<int> p1, p0; p1.insert(0); p1.insert(n+1); p0.insert(0); p0.insert(n+1);
    multiset<int> len1, len0;
    for(int i = 1; i <= n+1; i++){
        if(i == n+1){
            auto it0 = p0.end(); --it0; --it0;
            int l0 = *it0;
            len0.insert(n + 1 - l0);

            auto it1 = p1.end(); --it1; --it1;
            int l1 = *it1;
            len1.insert(n + 1 - l1);
        }
        else if(!a[i]){
            auto it = p1.ub(i); --it;
            int l = *it;
            len1.insert(i - l);
            p1.insert(i);
        }
        else{
            auto it = p0.ub(i); --it;
            int l = *it;
            len0.insert(i - l);
            p0.insert(i);
        }
    }

    int m; cin>>m;
    while(m--){
        int idx; cin>>idx;
        if(a[idx]){
            // Eliminar en p0
            p0.erase(idx);
            auto it0 = p0.ub(idx);
            int r = *it0;
            --it0;
            int l = *it0;
            len0.erase(len0.find(idx - l));
            len0.erase(len0.find(r - idx));
            len0.insert(r - l);

            // Agregar en p1
            auto it1 = p1.ub(idx);
            r = *it1;
            --it1;
            l = *it1;
            len1.erase(len1.find(r - l));
            len1.insert(idx - l);
            len1.insert(r - idx);
            p1.insert(idx);

            a[idx] = 0;
        }
        else{
            // Eliminar en p1
            p1.erase(idx);
            auto it1 = p1.ub(idx);
            int r = *it1;
            --it1;
            int l = *it1;
            len1.erase(len1.find(idx - l));
            len1.erase(len1.find(r - idx));
            len1.insert(r - l);

            // Agregar en p0
            auto it0 = p0.ub(idx);
            r = *it0;
            --it0;
            l = *it0;
            len0.erase(len0.find(r - l));
            len0.insert(idx - l);
            len0.insert(r - idx);
            p0.insert(idx);

            a[idx] = 1;
        }

        cout<<max(*len0.rbegin(), *len1.rbegin()) - 1<<endl;
    }
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