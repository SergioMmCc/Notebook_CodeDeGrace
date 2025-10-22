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

void solver(){
    int m; cin>>m;
    vector<char> dic(m);
    for(int i = 0; i < m; i++) cin>>dic[i];
    int n; cin>>n;
    while(n--){
        ll p; cin>>p;
        if(m == 1){
            for(int i = 0; i < p; i++) cout<<dic[0];
            cout<<endl;
            continue;
        }
        int len = 0; ll idx = 0, num = m;
        while(idx < p){
            len++;
            idx += num;
            num *= m;
        }

        num /= m;
        idx -= num; // Las palabras de longitud len inician en idx + 1
        num /= m; // num sera la cantidad de palabras cuyo siguiente caracter es x

        // La palabra es de longitud len
        vector<int> ans(len);
        for(int i = 0; i < len; i++){
            int letter = 0;
            while(idx + num < p){
                letter++;
                idx += num;
            }

            ans[i] = letter;
            num /= m;
        }

        for(int i = 0; i < len; i++) cout<<dic[ans[i]]; cout<<endl;
    }
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