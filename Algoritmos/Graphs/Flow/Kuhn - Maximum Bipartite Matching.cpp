#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

// n vertices
// Complejidad: O(v * e)

int n;
const int maxn = 1e4;
vector<int> graph[maxn];
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v){
    if(used[v])
        return 0;
    used[v] = 1;
    for(int to : graph[v]) {
        if(mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}

int main(){
    // ... reading the graph ...

    mt.assign(n + 1, -1);
    vector<bool> used1(n + 1, 0);
    for(int v = 1; v <= n; v++){
        for(int to : graph[v]){
            if(mt[to] == -1){
                mt[to] = v;
                used1[v] = 1;
                break;
            }
        }
    }
    for(int v = 1; v <= n; v++){
        if(used1[v]) continue;
        used.assign(n + 1, 0);
        try_kuhn(v);
    }

    for(int i = 1; i <= n; ++i)
        if(mt[i] != -1) cout<<mt[i] + 1<<' '<<i + 1<<endl;
}
