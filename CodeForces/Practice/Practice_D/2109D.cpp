#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const int maxn = 2e5 + 2;
const ll inf = 1e18;
vector<vector<int>> graph(maxn);

void BFS(vector<ll>& dPar, vector<ll>& dImpar){
    queue<pii> q; q.push({1, 0});
    dPar[1] = 0;

    while(!q.empty()){
        int u = q.front().fi, parity = q.front().se; q.pop();
        for(int v : graph[u]){
            if(parity == 1){
                if(dImpar[u] + 1 < dPar[v]){
                    dPar[v] = dImpar[u] + 1;
                    q.push({v, 0});
                }
            }
            else{
                if(dPar[u] + 1 < dImpar[v]){
                    dImpar[v] = dPar[u] + 1;
                    q.push({v, 1});
                }
            }
        }
    }
}

void solver(){
    int n, m, l; cin>>n>>m>>l;

    // Limpiar el grafo
    for(int i = 1; i <= n; i++) graph[i].clear();

    ll sumPar = 0;
    vector<ll> impares;
    for(int i = 0; i < l; i++){
        ll save; cin>>save;
        if(save % 2) impares.pb(save);
        else sumPar += save;
    }
    for(int i = 1; i <= m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    sort(impares.begin(), impares.end());

    ll maxPar = sumPar;
    for(int i = impares.sz - 1; i >= 0; i--){
        if(i == 0 && impares.sz % 2) break;

        maxPar += impares[i];
    }

    ll maxImpar = sumPar;
    for(int i = impares.sz - 1; i >= 0; i--){
        if(i == 0 && impares.sz % 2 == 0) break;

        maxImpar += impares[i];
    }
    if(maxImpar % 2 == 0) maxImpar = -1;

    vector<ll> dPar(n+1, inf), dImpar(n+1, inf);
    BFS(dPar, dImpar);

    for(int i = 1; i <= n; i++){
        if(dPar[i] <= maxPar || dImpar[i] <= maxImpar) cout<<'1';
        else cout<<'0';
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}