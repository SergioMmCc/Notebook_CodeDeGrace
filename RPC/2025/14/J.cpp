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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

bool check(string s, string t){
    bool cond = 0;
    for(int i = 0; !cond && i <= sz(s) - sz(t); i++){
        bool test = 1;
        for(int j = 0; test && j < sz(t); j++){
            if(t[j] != s[i + j]) test = 0;
        }
        if(test) cond = 1;
    }

    return cond;
}

void solver(){
    string s; cin>>s;
    vector<string> a(5);
    for(int i = 0; i < 5; i++) cin>>a[i];

    vector<int> perm = {1, 2, 3, 4, 5};
    bool cond = 0;
    for(int i = 0; !cond && i < 120; i++){
        string t = "";
        for(int j = 0; j < 5; j++){
            t += a[perm[j] - 1];
        }

        cond = check(s, t);

        if(i < 119) next_permutation(all(perm));
    }

    cout<<(cond ? "Nooo, la polizzia" : "Sargento Camelas, Gracias!")<<endl;
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