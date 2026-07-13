// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define print(arr) for(auto val : arr){ cout << val << " "; } cout << '\n';
#define sz(v) ((int)v.size())

typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;

const char ln = '\n';

int n, m;

vector<vi> graf, grafI;
vi disF, rec;

void bfs(int ini){

    queue<int> q;
    
    disF = vi(n, -1);

    q.push(ini);
    disF[ini] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : grafI[u]){
            if (disF[v] != -1) continue;

            disF[v] = disF[u] + 1;
            q.push(v);
        }
    }
}

int maxi, mini;
vi vis;

void dfs(int i){

    if (i == sz(rec) - 1) return;
    
    int u = rec[i];
    int nxt = rec[i + 1];


    int mini1 = 1e8;
    for (int v : graf[u]){
        mini1 = min(mini1, disF[v]);
    }

    int mini2 = 1e8;
    for(int v : graf[u]){
        if (v == nxt) continue;
        mini2 = min(mini2, disF[v]);
    }

    // cout << i << ": " << ln;
    // cout << mini1 << " " << mini2 << ln;

    if (mini1 == mini2) maxi++;

    if (disF[nxt] != mini1) mini++;

    dfs(i + 1);

}

void solve(){
    cin >> n >> m;

    graf = vector<vi>(n);
    grafI = vector<vi>(n);

    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        graf[u].push_back(v);
        grafI[v].push_back(u);
    }

    int m; cin >> m;
    rec = vi(m, 0);

    for(int &val : rec){
        cin >> val;
        val--;
    }

    int s = rec[0];
    int e = rec.back();

    bfs(e);

    mini = 0;
    maxi = 0;

    vis = vi(n, 0);

    dfs(0);

    cout << mini << " " << maxi << ln;

}

int main() {

    solve();

}
