#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 1020;
bool matriz[maxn][maxn];
int procesed[maxn][maxn];

bool try_kuhn(int v, vector<bool>& used, vector<int>& mt, set<int> graph[]) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : graph[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to], used, mt, graph)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++){
        string s; cin>>s;
        for(int j = 1; j <= n; j++){
            if(s[j-1] == '0') matriz[i][j] = 0;
            else matriz[i][j] = 1;
        }
    }

    // Limpiar matriz de aristas procesadas
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            procesed[i][j] = 0;
        }
    }

    // Encontrar cliques
    vector<set<int>> cliques(1);

    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            if(!procesed[i][j] && matriz[i][j]){
                procesed[i][j] = procesed[j][i] = 1;
                bool cond = 0;
                for(int k = 1; !cond && k <= n; k++){
                    if(k == i || k == j) continue;
                    if(matriz[k][i] && matriz[k][j]){
                        cond = 1;

                        int assignClique;
                        if(!procesed[i][k] && !procesed[j][k]){
                            assignClique = cliques.sz;
                            set<int> newClique = {i, j, k};
                            cliques.pb(newClique);
                        }
                        else{
                            assignClique = max(procesed[i][k], procesed[j][k]);
                            cliques[assignClique].insert(i);
                            cliques[assignClique].insert(j);
                            cliques[assignClique].insert(k);
                        }

                        for(int u : cliques[assignClique]){
                            procesed[u][i] = assignClique;
                            procesed[i][u] = assignClique;
                            procesed[u][j] = assignClique;
                            procesed[j][u] = assignClique;
                            procesed[u][k] = assignClique;
                            procesed[k][u] = assignClique;
                        }
                    }
                }

                if(!cond){
                    set<int> newClique = {i, j};
                    procesed[i][j] = procesed[j][i] = cliques.sz;
                    cliques.pb(newClique);
                }
            }
        }    
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        bool cond = 1;
        for(int j = 1; cond && j <= n; j++){
            if(matriz[i][j]) cond = 0;
        }

        if(cond) ans++;
    }

    set<int> graph[2*n + 10];
    vector<int> count(n+1);
    int add = cliques.sz;
    for(int clique = 1; clique < cliques.sz; clique++){
        for(int u : cliques[clique]){
            for(int clique2 = 1; clique2 < cliques.sz; clique2++){
                if(clique2 == clique) continue;
                if(cliques[clique2].find(u) != cliques[clique2].end()){
                    graph[clique].insert(clique2);
                    graph[clique2].insert(clique);
                    count[u]++;
                }
            }

            if(!count[u]){
                graph[add].insert(clique);
                graph[clique].insert(add);
                add++;
                count[u]++;
            }
        }
    }

    // Correr el maximum bipartite matching
    n = add - 1;
    vector<int> mt(n + 1, -1);
    vector<bool> used;
    vector<bool> used1(n + 1, 0);

    for(int v = 1; v <= n; v++) {
        for(int to : graph[v]) {
            if(mt[to] == -1) {
                mt[to] = v;
                used1[v] = true;
                break;
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        if (used1[v]) continue;
        used.assign(n + 1, 0);
        try_kuhn(v, used, mt, graph);
    }

    int aux = 0;
    for (int i = 1; i <= n; i++)
        if (mt[i] != -1) aux++;

    aux /= 2;
    ans += aux;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}