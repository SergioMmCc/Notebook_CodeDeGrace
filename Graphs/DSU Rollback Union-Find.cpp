#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

// Esta implmentacion usando Union-Find es ligeramente mas rapida
const int maxn = 200005;
int components;
vector<int> leader(maxn), sizen(maxn);

// - op = 0 para decir que llegamos al anterior persist
// - u es el vertice cuyo lider cambiamos
// - len es el tamaño del vertice hacia el cual enviamos el componente
// que lideraba u
// - from es el vertice que ahora va a liderar a u
struct change{
    bool op;
    int u, len, from;
};

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = 1;
    }
}

int find(int u){
    if(leader[u] == u) return u;
    return find(leader[u]);
}

void join(int u, int v, stack<change>& st){
    u = find(u); v = find(v);
    if(u != v){
        if(sizen[v] > sizen[u])
            swap(u, v);
        leader[v] = u;
        st.push({1, v, sizen[u], u});
        sizen[u] += sizen[v];
        components--;
    }
}

void rollback(stack<change>& st){
    while(!st.empty()){
        bool op = st.top().op;
        int u = st.top().u;
        int len = st.top().len, from = st.top().from;
        st.pop();

        if(!op) break; // Si !op quiere decir que llegamos al anterior persist
        
        sizen[from] = len; // Recuperar la talla que tenia from antes del join que estamos eliminando
        leader[u] = u; // Ahora u vuelve a ser su propio lider, como antes del join
        components++; // Siempre que deshago una union quiere decir que dividi un componente
    }
}

void persist(stack<change>& st){
    st.push({0, 0, 0, 0});
}

void solver(){
    int n, m; cin>>n>>m;
    initDSU(n);
    stack<change> st;
    while(m--){
        string op; cin>>op;
        if(op == "persist") persist(st);
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