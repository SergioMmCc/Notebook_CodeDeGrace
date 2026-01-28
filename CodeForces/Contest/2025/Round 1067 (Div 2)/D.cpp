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
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vii> add(16);
void fillAdd(){
    add[0] = {{0, 3}};
    add[1] = {{0, 2}};
    add[2] = {{0, 1}, {0, 2}, {0, 3}};
    add[3] = {{0, 1}};
    add[4] = {{2, 3}, {1, 3}, {0, 3}};
    add[5] = {{0, 2}, {2, 3}, {1, 3}};
    add[6] = {{1, 2}, {0, 3}};
    add[7] = {{1, 3}, {0, 3}};
    add[8] = {{1, 3}};
    add[9] = {{1, 2}};
    add[10] = {{1, 3}, {0, 1}, {0, 2}};
    add[11] = {{2, 3}, {1, 3}};
    add[12] = {{2, 3}};
    add[13] = {{0, 1}, {0, 2}};
    add[14] = {{0, 2}, {0, 3}};
}

void cut(string& s, string& t, int n){
    int i;
    for(i = 0; i < n; i++) if(s[i] != t[i]) break;

    int j;
    for(j = n-1; j >= 0; j--) if(s[j] != t[j]) break;

    string auxs = "", auxt = "";
    for(; i <= j; i++) auxs += s[i], auxt += t[i];
    s = auxs; t = auxt;
}

void addMove(string& aux, int i, vii& moves, bool rev){
    int num = 0;
    if(aux[0] == '1') num += 8;
    if(aux[1] == '1') num += 4;
    if(aux[2] == '1') num += 2;
    if(aux[3] == '1') num += 1;

    if(!rev) for(int j = 0; j < sz(add[num]); j++) moves.pb({add[num][j].fi + i, add[num][j].se + i});
    else for(int j = sz(add[num]) - 1; j >= 0; j--) moves.pb({add[num][j].fi + i, add[num][j].se + i});
}

void ans(vii& moves){
    cout<<sz(moves)<<endl;
    for(pii m : moves) cout<<m.fi + 1<<' '<<m.se + 1<<endl;
}

void solver(){
    int n; string s, t; cin>>n>>s>>t;
    vii moves;
    
    for(int i = 0; i < n - 3; i += 4){
        string aux = "";
        aux += s[i]; aux += s[i+1]; aux += s[i+2]; aux += s[i+3];
        addMove(aux, i, moves, 0);
        s[i] = s[i+1] = s[i+2] = s[i+3] = '1';
    }
    if(n % 4){
        string aux = "";
        aux += s[n-4]; aux += s[n-3]; aux += s[n-2]; aux += s[n-1];
        addMove(aux, n-4, moves, 0);
        s[n-4] = s[n-3] = s[n-2] = s[n-1] = '1';
    }

    for(int i = 0; i < n - 4; i++){
        if(s[i] == t[i]) continue;
        moves.pb({i, n-1});
        for(int j = i+1; j < n; j++) t[j] = (t[j] == '1' ? '0' : '1');
    }

    string aux = "";
    aux += t[n-4]; aux += t[n-3]; aux += t[n-2]; aux += t[n-1];
    addMove(aux, n-4, moves, 1);

    ans(moves);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in, "r", stdin);
	// freopen("name.out", "w", stdout);
    fillAdd();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}