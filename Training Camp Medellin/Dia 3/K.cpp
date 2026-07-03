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
    string s;
    getline(cin, s);
    // cout<<s<<endl;

    // cout<<sz(s)<<endl;
    string aux = "";
    for(int i = 0; i < sz(s); i++){
        // cout<<"i -> "<<i<<" s[i] -> "<<s[i]<<endl;
        if(s[i] == ','){
            // cout<<"HERE"<<endl;
            aux += ',';
            aux += ' ';
            // aux += ',';
            // cout<<aux<<endl;
        }
        else if(s[i] == '.'){
            aux += ' ';
            aux += "...";
            i += 2;
        }

        else if((int)s[i] >= '0' && s[i] <= '9'){
            aux += ' ';
            while(i < sz(s) && (int)s[i] >= '0' && s[i] <= '9'){
                aux += s[i];
                i++;
            }
            i--;
        }
    }
    // cout<<aux<<endl;
    string ans = "";
    for(int i = 0; i < sz(aux); i++){
        if(aux[i] == ' ' && (!i || aux[i-1] == ' ' || i == sz(aux)-1)) continue;
        // if(i && i < sz(aux) - 1 && aux[i] == ' ' && aux[i-1] == '.' && (int)aux[i+1] >= '0' && (int)aux[i+1] <= '9') continue;
        if(aux[i] == ' ' && !(aux[i-1] == ',' || aux[i+1] == '.' || ((int)aux[i-1] >= '0' && (int)aux[i-1] <= '9' && (int)aux[i+1] >= '0' && (int)aux[i+1] <= '9'))) continue;
        ans += aux[i];
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