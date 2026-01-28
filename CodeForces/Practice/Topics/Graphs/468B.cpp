#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
vector<vector<int>> graph(maxn);

bool BFS(int s, vector<int>& p, vector<int>& sets, map<int, int>& T, int a, int b){
    int color = sets[s];
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(color == 0){
            if(T.find(a - p[u]) != T.end()){
                int v = T[a - p[u]];
                if(sets[v] == 1) return 0;
                if(sets[v] != 0){
                    sets[v] = 0;
                    q.push(v);
                }
            }
            else return 0;

            if(T.find(b - p[u]) != T.end()){
                int v = T[b - p[u]];
                if(sets[v] == 1) return 0;
                if(sets[v] != 0){
                    sets[v] = 0;
                    q.push(v);
                }
            }
        }

        else{
            if(T.find(b - p[u]) != T.end()){
                int v = T[b - p[u]];
                if(sets[v] == 0) return 0;
                if(sets[v] != 1){
                    sets[v] = 1;
                    q.push(v);
                }
            }
            else return 0;

            if(T.find(a - p[u]) != T.end()){
                int v = T[a - p[u]];
                if(sets[v] == 0) return 0;
                if(sets[v] != 1){
                    sets[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    return 1;
}

void solver(){
    int n, a, b; cin>>n>>a>>b;
    vector<int> p(n+1);
    map<int, int> T;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
        T[p[i]] = i;
    }

    vector<int> sets(n+1, -1);
    for(int i = 1; i <= n; i++){
        if(sets[i] != -1) continue;
 
        // Se puede con a
        bool cond1 = 0;
        int num1 = a - p[i];
        if(T.find(num1) != T.end() && (sets[T[num1]] == 0 || sets[T[num1]] == -1)) cond1 = 1;
 
        // Se puede con b
        bool cond2 = 0;
        int num2 = b - p[i];
        if(T.find(num2) != T.end() && (sets[T[num2]] == 0 || sets[T[num2]] == -1)) cond2 = 1;
 
        if(!cond1 && !cond2){
            cout<<"NO"<<endl;
            return;
        }
 
        if(cond1 && cond2) continue;
 
        if(cond1){
            sets[i] = 0;
            if(!BFS(i, p, sets, T, a, b)){
                cout<<"NO"<<endl;
                return;
            }
        }
 
        else if(cond2){
            sets[i] = 1;
            if(!BFS(i, p, sets, T, a, b)){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++){
        if(i > 1) cout<<' ';
        if(sets[i] == -1) cout<<0;
        else cout<<sets[i];
    }
    cout<<endl;
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