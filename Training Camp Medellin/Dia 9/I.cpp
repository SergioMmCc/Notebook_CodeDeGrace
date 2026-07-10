#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int topoSort(int n, vi inDegree, vector<vi>& graph, vi& h, int st){
    int sum = 0;
    vector<queue<int>> q(4);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!inDegree[i]){ 
            // Si el nodo no tiene ningun inDegree, quiere decir que puede ir al incio del topoSort
            q[h[i]].push(i);
        }
    }
    if(q[st].empty()) return 1e8;

    int cur = st;
    while(cnt < n){
        while(!q[cur].empty()){
            cnt++;
            int u = q[cur].front(); q[cur].pop();
            for(int v : graph[u]){
                inDegree[v]--;
                if(!inDegree[v]) q[h[v]].push(v);
            }
        }

        if(cnt < n){
            sum++;
            cur++;
            if(cur == 4) cur = 1;
        }
    }

    return sum;
}

void solver(){
    int n; cin>>n;
    vi h(n+1);
    for(int i = 1; i <= n; i++) cin>>h[i];

    vector<vi> graph(n+1);
    vi inDegree(n+1);
    for(int i = 1; i <= n; i++){
        int num; cin>>num;
        inDegree[i] = num;
        for(int j = 0; j < num; j++){
            int from; cin>>from;
            graph[from].pb(i);
        }
    }

    int ans = 1e8;
    for(int i = 1; i <= 3; i++){
        ans = min(ans, topoSort(n, inDegree, graph, h, i));
    }

    cout<<ans+n<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
