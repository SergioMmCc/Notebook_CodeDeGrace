#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> value;
vector<vector<int>> tree;

void DFS (int nodo) {
    int minSon = 2e9;
    if(tree[nodo].size() == 0)
        return;
    for(int son : tree[nodo]) {
        DFS(son);
        minSon = min(minSon, value[son]);
    }
    
    if(nodo == 1) 
        value[1] += minSon;
    else {
        if(minSon < value[nodo])
            value[nodo] = minSon;
        else 
            value[nodo] += (minSon - value[nodo])/2;
    }
}

void solver() {
    int n; cin>>n;
    value.assign(n+1, 0);
    tree.assign(n+1, vector<int>());
    for(int i = 1; i <= n; i++)
        cin>>value[i];
        
    for(int i = 2; i <= n; i++) {
        int save; cin>>save;
        tree[save].push_back(i);
    }
    
    DFS(1);
    cout<<value[1]<<endl;
    
    value.clear();
    tree.clear();
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}