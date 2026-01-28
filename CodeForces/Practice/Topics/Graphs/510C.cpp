#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 27;
vector<vector<int>> graph(maxn);
vector<int> inDegree(maxn);

// Sirve para hallar un "Topological Sort" en un DAG (Directed Acyclic Graph)
// Un "Topological Sort", es una forma de ordenar los nodos dado que para cada
// arista dirigida de 'u' a 'v', 'u' aparece antes que 'v' en el orden
// Esta implementacion se base en un BFS, por ende la complejidad es O(n + m)
void topoSort(vector<int>& orden){
    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(!inDegree[i]){ 
            // Si el nodo no tiene ningun inDegree, quiere decir que puede ir al incio del topoSort
            q.push(i);
            orden.pb(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            inDegree[v]--; // Quitamos un inDegree a cada vertice que puede ser visitado desde otro ya procesado
            if(!inDegree[v]){ 
                // Si su inDegree ahora es 0, quiere decir que ya fueron procesados todos los nodos que lo 
                // anteceden, por ende ahora puede ser agregado al topoSort, y lo metemos a la cola
                q.push(v);
                orden.pb(v);
            }
        }
    }
}

void solver(){
    int n; cin>>n;
    string lastName; cin>>lastName;
    bool cond = 1;
    for(int i = 1; i < n; i++){
        string newName; cin>>newName;
        int j = 0;
        while(j < lastName.sz && j < newName.sz && lastName[j] == newName[j]) j++;
        if(j >= newName.sz) cond = 0;
        else if(j < lastName.sz){
            graph[lastName[j] - 'a'].pb(newName[j] - 'a');
            inDegree[newName[j] - 'a']++;
        }
        lastName = newName;
    }

    if(!cond){
        cout<<"Impossible"<<endl;
        return;
    }

    vector<int> ans;
    
    topoSort(ans);
    if(ans.sz < 26) cout<<"Impossible"<<endl;
    else{
        for(int i = 0; i < ans.sz; i++){
            cout<<(char)(ans[i] + 'a');
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