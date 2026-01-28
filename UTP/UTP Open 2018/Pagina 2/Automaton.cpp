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
typedef pair<int, char> pic;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, m, s, k; cin>>n>>m>>s>>k;
    unordered_map<char, int> dic;
    for(int i = 0; i < s; i++){
        char c; cin>>c;
        dic[c] = i;
    }
    set<int> fin1;
    for(int i = 0; i < k; i++){
        int num; cin>>num;
        fin1.insert(num);
    }

    // Transiciones originales AFND
    vector<vector<vector<int>>> d(n, vector<vector<int>>(s));
    for(int i = 0; i < m; i++){
        int u, v; char c; cin>>u>>v>>c;
        d[u][dic[c]].pb(v);
    }

    // Convertir AFND en AFD
    vector<vector<int>> D(1, vector<int>(s, -1));
    map<set<int>, int> add;
    queue<set<int>> q;
    add[{0}] = 0;
    q.push({0});
    set<int> fin2;
    if(fin1.find(0) != fin1.end()) fin2.insert(0);

    int count = 1;
    
    while(!q.empty()){
        set<int> it = q.front(); q.pop();
        for(int j = 0; j < s; j++){
            set<int> aux;
            bool cond = 0;
            for(int i : it){
                for(int k : d[i][j]){
                    aux.insert(k);
                    if(fin1.find(k) != fin1.end()) cond = 1;
                }
            }

            if(add.find(aux) == add.end()){
                add[aux] = count;
                q.push(aux);
                count++;
                D.pb(vector<int>(s, -1));
                if(cond) fin2.insert(add[aux]);
            }

            D[add[it]][j] = add[aux];
        }
    }

    // AFD
    // for(int i = 0; i < count; i++){
    //     for(int j = 0; j < s; j++){
    //         cout<<D[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    int qr; cin>>qr;
    while(qr--){
        string ask; cin>>ask;
        vector<int> v(sz(ask));
        for(int i = 0; i < sz(ask); i++) v[i] = dic[ask[i]];

        // Recorrer el automata
        int cur = 0;
        for(int i = 0; i < sz(ask); i++){
            cur = D[cur][v[i]];
        }

        cout<<(fin2.find(cur) != fin2.end() ? "Yes" : "No")<<endl;
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