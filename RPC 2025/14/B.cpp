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

ll ans = 0;

ll mazeToInt(vector<string>& a){
    ll num = 0, pot = 1;
    for(int i = 0; i < sz(a); i++){
        for(int j = 0; j < sz(a[i]); j++){
            if(a[i][j] == 'X') num += pot;
            pot *= 2LL;
        }
    }

    return num;
}

vector<string> moveUp(vector<string>& a){
    int n = sz(a), m = sz(a[0]);
    vector<int> tope(m, -1);
    vector<string> b(n);
    for(int i = 0; i < n; i++){
        b[i] = a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'X'){
                b[i][j] = '.';
                b[tope[j]+1][j] = 'X';
                tope[j]++;
            }
            else if(a[i][j] == '#') tope[j] = i;
        }
    }

    return b;
}

vector<string> moveDown(vector<string>& a){
    int n = sz(a), m = sz(a[0]);
    vector<int> tope(m, n);
    vector<string> b(n);
    for(int i = n-1; i >= 0; i--){
        b[i] = a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'X'){
                b[i][j] = '.';
                b[tope[j]-1][j] = 'X';
                tope[j]--;
            }
            else if(a[i][j] == '#') tope[j] = i;
        }
    }

    return b;
}

vector<string> moveLeft(vector<string>& a){
    int n = sz(a), m = sz(a[0]);
    vector<int> tope(n, -1);
    vector<string> b(n);
    for(int i = 0; i < n; i++){
        b[i] = a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'X'){
                b[i][j] = '.';
                b[i][tope[i]+1] = 'X';
                tope[i]++;
            }
            else if(a[i][j] == '#') tope[i] = j;
        }
    }

    return b;
}

vector<string> moveRight(vector<string>& a){
    int n = sz(a), m = sz(a[0]);
    vector<int> tope(n, m);
    vector<string> b(n);
    for(int i = 0; i < n; i++){
        b[i] = a[i];
        for(int j = m-1; j >= 0; j--){
            if(a[i][j] == 'X'){
                b[i][j] = '.';
                b[i][tope[i]-1] = 'X';
                tope[i]--;
            }
            else if(a[i][j] == '#') tope[i] = j;
        }
    }

    return b;
}

bool BFS(vector<string>& s){
    set<ll> vis;
    ll si = mazeToInt(s);
    if(ans == si) return 1;
    vis.insert(si);
    queue<vector<string>> q;
    q.push(s);

    while(!q.empty()){
        vector<string> u = q.front(); q.pop();
        
        vector<string> v; ll vi;

        // cout<<"u -> "<<endl; for(int i = 0; i < sz(u); i++) cout<<u[i]<<endl;

        v = moveDown(u);
        vi = mazeToInt(v);
        if(vi == ans) return 1;
        if(vis.find(vi) == vis.end()){
            vis.insert(vi);
            q.push(v);
        }
        // cout<<"down -> "<<endl; for(int i = 0; i < sz(v); i++) cout<<v[i]<<endl;

        v = moveUp(u);
        vi = mazeToInt(v);
        if(vi == ans) return 1;
        if(vis.find(vi) == vis.end()){
            vis.insert(vi);
            q.push(v);
        }
        // cout<<"up -> "<<endl; for(int i = 0; i < sz(v); i++) cout<<v[i]<<endl;

        v = moveLeft(u);
        vi = mazeToInt(v);
        if(vi == ans) return 1;
        if(vis.find(vi) == vis.end()){
            vis.insert(vi);
            q.push(v);
        }
        // cout<<"left -> "<<endl; for(int i = 0; i < sz(v); i++) cout<<v[i]<<endl;

        v = moveRight(u);
        vi = mazeToInt(v);
        if(vi == ans) return 1;
        if(vis.find(vi) == vis.end()){
            vis.insert(vi);
            q.push(v);
        }
        // cout<<"right -> "<<endl; for(int i = 0; i < sz(v); i++) cout<<v[i]<<endl;
        // cout<<endl;
    }

    return 0;
}

void solver(){
    int n, m; cin>>n>>m;
    vector<string> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    ans = mazeToInt(b);

    cout<<(BFS(a) ? "YES" : "NO")<<endl;
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