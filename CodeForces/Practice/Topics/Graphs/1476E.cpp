#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2e5 + 1;
vector<vector<int>> graph(maxn);
vector<int> inDegree(maxn);

void topoSort(int n, vector<int>& orden){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!inDegree[i]){
            q.push(i);
            orden.pb(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            inDegree[v]--;
            if(!inDegree[v]){
                q.push(v);
                orden.pb(v);
            }
        }
    }
}

void solver(){
    int n, m, k; cin>>n>>m>>k;
    int limit = 1;
    for(int i = 0; i < k; i++) limit *= 2;
    map<string, int> patterns;
    for(int i = 1; i <= n; i++){
        string save; cin>>save;
        patterns[save] = i;
    }
    
    bool cond = 1;
    for(int i = 0; i < m; i++){
        string s; int mt; cin>>s>>mt;
        if(!cond) continue;

        bool findMt = 0;
        int num = 0;
        vector<int> validNumbers;
        while(num < limit){
            string compare = s;
            int aux = num;
            for(int j = 0; j < k; j++){
                if(aux % 2) compare[j] = '_';
                aux >>= 1;
            }
            
            map<string, int>::iterator it = patterns.find(compare);
            if(it != patterns.end()){
                if(patterns[compare] == mt) findMt = 1;
                else validNumbers.pb(patterns[compare]);
            }
            
            num++;
        }

        if(!findMt){
            cond = 0;
            continue;
        }
        for(int v : validNumbers){
            graph[mt].pb(v);
            inDegree[v]++;
        }
    }

    if(!cond){
        cout<<"NO"<<endl;
        return;
    }

    vector<int> orden;
    topoSort(n, orden);
    if(orden.sz < n) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++){
            if(i) cout<<' ';
            cout<<orden[i];
        }
        cout<<endl;
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