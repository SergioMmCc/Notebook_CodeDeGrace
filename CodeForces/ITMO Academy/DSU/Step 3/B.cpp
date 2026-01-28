#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int maxn = 50005;
int components;
vector<int> leader(maxn), sizen(maxn);

int block_size;

struct Query {
    int l, r, id;
    bool operator<(Query other) const
    {
        return r < other.r;
    }
};

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

        if(!op) break;
        
        sizen[from] = len;
        leader[u] = u;
        components++;
    }
}

void persist(stack<change>& st){
    st.push({0, 0, 0, 0});
}

void solver(){
    stack<change> st1, st2;
    int n, m; cin>>n>>m;
    block_size = sqrt(m) + 1;
    vector<pii> edges(m+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        edges[i+1] = {u, v};
    }

    vector<vector<Query>> blocks(block_size);
    int q; cin>>q;
    for(int i = 0; i < q; i++){
        int l, r; cin>>l>>r;
        blocks[l / block_size].pb({l, r, i});
    }

    vector<int> ans(q);
    initDSU(n);
    for(int i = 0; i < block_size; i++){
        if(blocks[i].empty()) continue;
        int len = blocks[i].sz;
        sort(blocks[i].begin(), blocks[i].end());
        int j = 0;

        // Inicialmente vamos a evaluar individualmente las queries en 
        // las que tanto l como r estan dentro del rango
        int maxRange = (i+1)*block_size;
        while(j < len && blocks[i][j].r < maxRange){
            int l = blocks[i][j].l, r = blocks[i][j].r, id = blocks[i][j].id;
            persist(st1);
            for(int edge = l; edge <= r; edge++){
                join(edges[edge].first, edges[edge].second, st1);
            }
            
            ans[id] = components;
            rollback(st1);
            j++;
        }

        int lastR = maxRange - 1;
        persist(st2);
        for(; j < len; j++){
            while(lastR < blocks[i][j].r){
                lastR++;
                join(edges[lastR].first, edges[lastR].second, st2);
            }
            
            persist(st1);
            for(int l = maxRange - 1; l >= blocks[i][j].l; l--)
                join(edges[l].first, edges[l].second, st1);

            ans[blocks[i][j].id] = components;
            rollback(st1);
        }
        rollback(st2);
    }

    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
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