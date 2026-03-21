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

map<string, int> T;
void calc(){
    T["Animal Appendages"] = 1;
    T["Social Security Benefits"] = 2;
    T["Single-Elimination Tournament"] = 4;
    T["Cover Your Bases"] = 5;
    T["Country Roads"] = 6;
    T["Forgotten Fragments"] = 8;
    T["Grimms' Fairy Tales"] = 10;
    T["Who wants to be a Millionaire?"] = 11;
    T["World Population"] = 13;
    T["Jaded Journey"] = 15;
    T["Knavish Knockout"] = 17;
    T["What's the Order Anyway?"] = 19;
    T["Picture Caption"] = 21;
}

void solver(){
    string s;
    getline(cin, s);
    cout<<T[s]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calc();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}