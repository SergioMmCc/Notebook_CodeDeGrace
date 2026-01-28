#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 101
using ld = long double;

typedef pair<int, int> pii;

int matriz[MAXN][MAXN];
vector<pii> graph[MAXN][MAXN];
int r, c;

bool testInRow(int row, int inicial, int final){
    ld y1 = matriz[row][inicial], y2 = matriz[row][final];
    ld m = (y1-y2) / (ld)(inicial-final), b = y1 - m*(ld)inicial;
    for(int i = inicial + 1; i <= final; i++){
        ld point = m*(ld)i + b;
        if((ld)matriz[row][i]-0.00000005 > point)
            return false;
    }
    return true;
}

bool testInColumn(int column, int inicial, int final){
    int y1 = matriz[inicial][column], y2 = matriz[final][column];
    ld m = (y1-y2) / (ld)(inicial-final), b = y1 - m*(ld)inicial;
    for(int i = inicial + 1; i <= final; i++){
        ld point = m*(ld)i + b;
        if((ld)matriz[i][column]-0.00000005 > point)
            return false;
    }
    return true;
}

int BFS(){
    queue<pii> q; q.push({0, 0});
    bool visited[r][c]; 
    for(int i = 0; i < r; i++){
        for(int j = 0; j <c; j++)
            visited[i][j] = false;
    }
    visited[0][0] = true;
    int distance[r][c]; distance[0][0] = 0;
    while(!q.empty()){
        pii u = q.front(); q.pop();
        for(pii v : graph[u.first][u.second]){
            if(!visited[v.first][v.second]){
                visited[v.first][v.second] = true;
                distance[v.first][v.second] = distance[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }
    
    return distance[r-1][c-1]-1;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin>>r>>c;
    string save;
    for(int i = 0; i < r; i++){
        cin>>save;
        for(int j = 0; j < save.size(); j++)
            matriz[i][j] = save[j] - '0';
    }
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for(int l = j+1; l < c; l++){
                if(testInRow(i, j, l)){
                    graph[i][j].push_back({i, l});
                    graph[i][l].push_back({i, j});
                }
            }
            for(int k = i+1; k < r; k++){
                if(testInColumn(j, i, k)){
                    graph[i][j].push_back({k, j});
                    graph[k][j].push_back({i, j});
                }
            }
        }
    }
    cout<<BFS()<<endl;
    
    return 0;
}