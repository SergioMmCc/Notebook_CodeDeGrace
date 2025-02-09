#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int maxn = 200005;
int components;
vector<int> leader(maxn);
unordered_set<int> sets[maxn];

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sets[i].insert(i);
    }
}

void join(int u, int v, stack<pair<bool, piii>>& st){
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        if(sets[leaderV].size() > sets[leaderU].size())
            swap(leaderU, leaderV);
        
        for(int v : sets[leaderV]){
            leader[v] = leaderU;
            st.push({1, {v, {leaderV, leaderU}}});
            // Cada que hacemos algun cambio en el DSU, guardamos en una stack
            // la informacion sobre ese cambio, asi en caso de que hagamos rollback
            // podremos devolver cada vertice a su anterior posicion, como si eliminaramos
            // las aristas agregadas desde la ultima vez que "guardamos" el DSU
            sets[leaderU].insert(v);
        }
        sets[leaderV].clear();
        components--;
    }
}

// EL rollback sirve para devolver el DSU a un estado previo
void rollback(stack<pair<bool, piii>>& st){
    while(!st.empty()){
        bool op = st.top().first;
        int u = st.top().second.first;
        int to = st.top().second.second.first, from = st.top().second.second.second;
        st.pop();
        if(!op){
            // En caso de que op sea 0, quiere decir que llegamos al ultimo
            // guardado apartir del cual aun no habiamos hecho rollback. Asi
            // que reestablecemos el numero de componentes y terminamos el ciclo.
            components = u;
            break;
        }
        // Devolvemos cada vertice a su anterior componente
        sets[from].erase(u);
        sets[to].insert(u);
        leader[u] = to;
    }
}

void solver(){
    int n, m; cin>>n>>m;
    initDSU(n);
    stack<pair<bool, piii>> st;
    while(m--){
        string op; cin>>op;
        // Si la operacion dada es "persist", quiere decir que debemos guardar el
        // estado del DSU en ese momento. Para hacerlo guardamos en la pila una 
        // operacion de tipo 0 y el numero de componentes que habia en el momento
        // de ese guardado
        if(op == "persist") st.push({0, {components, {0, 0}}});
        else if(op == "rollback"){
            rollback(st);
            cout<<components<<endl;
        }
        else{
            int u, v; cin>>u>>v;
            join(u, v, st);
            cout<<components<<endl;
        }
    }
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