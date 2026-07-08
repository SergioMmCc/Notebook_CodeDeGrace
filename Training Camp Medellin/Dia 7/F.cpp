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
    int n; cin>>n;
    vs a(n);
    map<string, int> freq;
    map<string, string> word;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        set<string> x;
        for(int j = 0; j < sz(a[i]); j++){
            string aux = "";
            for(int k = j; k < sz(a[i]); k++){
                aux += a[i][k];
                // cout<<aux<<endl;
                if(x.find(aux) == x.end()){
                    freq[aux]++;
                    x.insert(aux);
                    word[aux] = a[i];
                }
            }
        }
    }

    int q; cin>>q;
    while(q--){
        string b; cin>>b;
        if(freq.find(b) == freq.end()){
            cout<<0<<" -"<<endl;
            continue;
        }

        cout<<freq[b]<<' '<<word[b]<<endl;
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