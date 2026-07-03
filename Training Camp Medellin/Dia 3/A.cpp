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

map<int, int> c = {{0, 0}, {1, 1}, {2, 5}, {3, -1}, {4, -1}, {5, 2}, {6, -1}, {7, -1}, {8, 8}, {9, -1}};

void add(int& h1, int& h2, int& m1, int& m2, int lh, int lm){
    int h = 10*h1 + h2, m = 10*m1 + m2 + 1;
    if(m == lm){
        m1 = 0; m2 = 0;
        h++;
        if(h == lh){
            h1 = 0; h2 = 0;
        }
        else if(h2 + 1 == 10){
            h2 = 0;
            h1++;
        }
        else h2++;
    }

    else if(m2 + 1 == 10){
        m2 = 0;
        m1++;
    }

    else m2++;
}

void solver(){
    int h, m; cin>>h>>m;
    string s; cin>>s;
    int h1 = s[0] - '0', h2 = s[1] - '0', m1 = s[3] - '0', m2 = s[4] - '0';

    while(1){
        int ho1 = c[m2], ho2 = c[m1], mi1 = c[h2], mi2 = c[h1];
        if(ho1 != -1 && ho2 != -1 && mi1 != -1 && mi2 != -1 && 10*ho1 + ho2 < h && 10*mi1 + mi2 < m){
            cout<<h1<<h2<<':'<<m1<<m2<<endl;
            return;
        }

        add(h1, h2, m1, m2, h, m);
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