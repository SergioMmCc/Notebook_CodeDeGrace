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
typedef pair<int, pii> piii;

const int maxh = 1005, maxn = 1000009;
vector<string> maze(maxh);
vector<vector<int>> tree(maxn);

vector<pii> movements(4);
void initializeMovements(){
    movements[0] = {0, -1};
    movements[1] = {0, 1};
    movements[2] = {-1, 0};
    movements[3] = {1, 0};
}

int components;
vector<int> leader(maxn), sizen(maxn);

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = 1;
    }
}

int find(int u){
    if(leader[u] != u)
        leader[u] = find(leader[u]);
    return leader[u];
}

void join(int u, int v){
    int leaderU = find(u), leaderV = find(v);
    if(leaderU != leaderV){
        if(sizen[leaderV] > sizen[leaderU])
            swap(leaderU, leaderV);
        leader[leaderV] = leaderU;
        sizen[leaderU] += sizen[leaderV];
        components--;
    }
}

void updateAllLeaders(int n){
    for(int i = 1; i <= n; i++)
        find(i);
}

void buildTree(int h, int w){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int s = i * w + j + 1;
            // cout<<"s -> "<<s<<endl;
            if(maze[i][j] == '#'){
                components--;
                sizen[s] = 0;
                continue;
            }
            for(int k = 0; k < 4; k++){
                int vy = i + movements[k].fi, vx = j + movements[k].se;
                if(vy < 0 || vy >= h || vx < 0 || vx >= w || maze[vy][vx] == '#') continue;
                int d = vy * w + vx + 1;
                tree[s].pb(d);
                // cout<<"join -> "<<s<<' '<<d<<endl;
                join(s, d);
            }
        }
    }
}

int findDiamter(int s){
    queue<piii> q; q.push({s, {-1, 0}});
    pii ns = {0, s};
    while(!q.empty()){
        int u = q.front().fi, pa = q.front().se.fi, dis = q.front().se.se; q.pop();
        if(dis > ns.fi) ns = {dis, u};
        for(int v : tree[u]){
            if(v == pa) continue;
            q.push({v, {u, dis + 1}});
        }
    }

    s = ns.se;
    q.push({s, {-1, 0}});
    int ans = 0;
    while(!q.empty()){
        int u = q.front().fi, pa = q.front().se.fi, dis = q.front().se.se; q.pop();
        ans = max(ans, dis);
        for(int v : tree[u]){
            if(v == pa) continue;
            q.push({v, {u, dis + 1}});
        }
    }

    return ans;
}

void solver(){
    int h, w; cin>>h>>w;
    for(int i = 0; i < h; i++){
        cin>>maze[i];
    }

    int n = h * w;
    for(int i = 1; i <= n; i++){
        tree[i].clear();
    }

    initDSU(n);
    buildTree(h, w);
    
    int maxi = 0;
    for(int i = 1; i <= n; i++){
        find(i);
        maxi = max(maxi, sizen[i]);
    }

    int diameter = 0;
    for(int i = 1; i <= n; i++){
        if(find(i) != i || sizen[i] < maxi) continue;
        diameter = max(diameter, findDiamter(i));
    }

    cout<<components<<' '<<maxi<<' '<<diameter<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    initializeMovements();
    int t = 1;
    cin>>t;
    for(int i = 1; i <= t; i++){
        cout<<"Case "<<i<<": ";
        solver();
    }

    return 0;
}