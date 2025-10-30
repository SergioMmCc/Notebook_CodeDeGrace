#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int maxn = 300005;
int components;
vector<int> leader(maxn), sizen(maxn);
vector<int> ans;

struct change{
    bool op;
    int u, len, from;
}; stack<change> st;

struct query{
    bool op;
    int t, l, r, u, v;
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

void join(int u, int v){
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

void rollback(){
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

void persist(){
    st.push({0, 0, 0, 0});
}

void work(int l, int r, queue<query>& q1){
    if(l == r - 1){
        persist();
        
        queue<query> q2;
        while(!q1.empty()){
            query q = q1.front(); q1.pop();
            if(!q.op && q.t == l) q2.push(q);
            if(q.op && q.l <= l && q.r >= r) join(q.u, q.v);
        }
        while(!q2.empty()){
            query q = q2.front(); q2.pop();
            ans[q.t] = components;
        }
        rollback();
        return;
    }

    persist();
    queue<query> q2;
    while(!q1.empty()){
        query q = q1.front(); q1.pop();
        if(q.op && q.l <= l && q.r >= r) join(q.u, q.v);
        else if((!q.op && q.t >= l && q.t < r) ||
            (q.op && ((q.l >= l && q.l < r) || (q.r - 1 >= l && q.r <= r)))) q2.push(q);
    }

    int m = (l + r) >> 1;
    queue<query> q3 = q2;
    work(l, m, q2);
    work(m, r, q3);
    rollback();
}

void solver(){
    int n, m; cin>>n>>m; if(!m) return;
    initDSU(n);
    map<pii, int> T;
    vector<query> queries;
    for(int i = 0; i < m; i++){
        char op; cin>>op;
        if(op == '?') queries.pb({0, i, 0, 0, 0, 0});
        else{
            int u, v; cin>>u>>v; if(u > v) swap(u, v);
            if(op == '+'){
                T[{u, v}] = queries.sz;
                queries.pb({1, 0, i, -1, u, v});
            }
            else queries[T[{u, v}]].r = i;
        }
    }

    queue<query> q1;
    for(int i = 0; i < queries.sz; i++){
        if(queries[i].op && queries[i].r == -1) queries[i].r = m;
        q1.push(queries[i]);
    }

    ans.resize(m);
    work(0, m, q1);
    for(int i = 0; i < m; i++){
        if(!ans[i]) continue;
        cout<<ans[i]<<endl;
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