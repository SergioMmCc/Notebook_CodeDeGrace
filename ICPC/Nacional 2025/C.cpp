#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> pli;

const ll maxn = 1500;
ll components;
vector<ll> leader(maxn);
vector<ll> sets[maxn];

void initDSU(ll n){
    components = n;
    for(ll i = 0; i < n; i++){
       leader[i] = i;
       sets[i].clear();
       sets[i].push_back(i); 
    }
}

void join(ll u, ll v){
    ll leaderU = leader[u], leaderV = leader[v];
    if(leaderU == leaderV) return;
    else{
        if(sets[leaderV].size() > sets[leaderU].size()) swap(leaderU, leaderV);

        for(ll i = 0; i < sets[leaderV].size(); i++){
            ll v = sets[leaderV][i];
            leader[v] = leaderU;
            sets[leaderU].push_back(v);
        }

        sets[leaderV].clear();
        components--;
    }
}

struct poll{
    ll x, y;
};

void solver(ll n, ll k){
    vector<poll> p(n);
    for(ll i = 0; i < n; i++) cin>>p[i].x>>p[i].y;
    vector<vector<pli>> dis(n);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(i == j) continue;
            dis[i].push_back({(p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y), j});
        }
    }

    for(ll i = 0; i < n; i++) sort(dis[i].begin(), dis[i].end());

    vector<set<ll>> create(n);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < k && j < (ll)dis[i].size(); j++) create[i].insert(dis[i][j].second);
    }

    set<pii> edges;
    vector<ll> adj(n);
    for(ll u = 0; u < n; u++){
        for(ll v : create[u]){
            if(create[v].find(u) != create[v].end() && edges.find({min(u, v), max(u, v)}) == edges.end()){
                edges.insert({min(u, v), max(u, v)});
                adj[u]++;
                adj[v]++;
            }
        }
    }

    // for(pii e : edges) cout<<e.first<<' '<<e.second<<endl;
    initDSU(n);
    for(pii e : edges) join(e.first, e.second);

    ll c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
    for(ll i = 0; i < n; i++){
        if(leader[i] != i) continue;

        ll len = sets[i].size();

        // cout<<"i -> "<<i<<" size -> "<<sets[i].size()<<" count -> "<<cont[i]<<endl;
        if(len == 1){
            c5++;
            continue;
        }

        ll cont = 0;
        for(pii e : edges){
            if(leader[e.first] == i || leader[e.second] == i){
                cont++;
            }
        }
        
        if(cont == (len * (len - 1)) / 2){
            c3++;
            continue;
        }

        if(cont == len){
            bool cond = 1;
            for(int j = 0; cond && j < sets[i].size(); j++){
                if(adj[sets[i][j]] != 2) cond = 0;
            }

            if(cond){
                c2++;
                continue;
            }
        }

        if(cont == len - 1){
            // Test estrella
            bool cond = 0;
            for(ll j = 0; !cond && j < sets[i].size(); j++){
                if(adj[sets[i][j]] == len - 1) cond = 1;
            }
            if(cond){
                c4++;
                continue;
            }

            ll cont1 = 0, cont2 = 0;
            for(ll j = 0; j < sets[i].size(); j++){
                if(adj[sets[i][j]] == 1) cont1++;
                else if(adj[sets[i][j]] == 2) cont2++;
            }

            if(cont1 == 2 && cont2 == len - 2){
                c1++;
                continue;
            }
        }

        c5++;
    }

    cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<' '<<c5<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t = 1;
    ll n, k;
    while(cin>>n>>k){
        if(n + k == 0) return 0;
        solver(n, k);
    }

    return 0;
}