#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

vector<vector<int>> generateCycles(const vector<int>& a){
    int n = a.sz;
    vector<bool> visited(n);
    vector<vector<int>> cycles;

    for(int i = 1; i < n; i++){
        if(!visited[i]){
            vector<int> cycle;
            int pos = i;
            while(!visited[pos]){
                visited[pos] = 1;
                cycle.pb(pos);
                pos = a[pos];
            }

            cycles.pb(cycle);
        }
    }

    return cycles;
}

void solver(){
    int n, k; cin>>n>>k;
    vector<int> rows(n+1), columns(n+1);
    vector<bool> rowCyc(n + 1), colCyc(n + 1);
    
    for(int i = 1; i <= n; i++){
        rows[i] = i;
        columns[i] = i;
    }
    for(int i = 0; i < k; i++){
        char c; int a, b;
        cin>>c>>a>>b;
        if(c == 'R') swap(rows[a], rows[b]);
        else swap(columns[a], columns[b]);
    }

    vector<vector<int>> rowCycles = generateCycles(rows);
    vector<vector<int>> columnCycles = generateCycles(columns);

    bool cond = 1;
    int cycleLen = rowCycles[0].sz;
    int totalCycles = rowCycles.sz;
    if(columnCycles.sz != totalCycles) cond = 0;
    for(int i = 0; cond && i < totalCycles; i++){
        if(rowCycles[i].sz != cycleLen || columnCycles[i].sz != cycleLen)
            cond = 0;
    }

    if(!cond) {cout<<'*'<<endl; return;}
    // else cout<<"YES"<<endl;
    // cout<<cycleLen<<endl;
    int ans[n+1][n+1];
    
    for(int rCyc = 0; rCyc < totalCycles; rCyc++){
        for(int cCyc = 0; cCyc < totalCycles; cCyc++){
            int value1 = ((totalCycles + rCyc - cCyc) % totalCycles) * cycleLen;
            for(int r = 0; r < cycleLen; r++){
                for(int c = 0; c < cycleLen; c++){
                    int value2 = value1 + ((cycleLen + r - c) % cycleLen) + 1;
                    int i = rowCycles[rCyc][r];
                    int j = columnCycles[cCyc][c];
                    ans[i][j] = value2;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j > 1)cout<<' ';
            cout<<ans[i][j];
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