#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> coord;
coord operator + (const coord &a, const coord &b) {return make_pair(a.first + b.first, a.second + b.second);}
coord operator - (const coord &a, const coord &b) {return make_pair(a.first - b.first, a.second - b.second);}
 
const int MAXT = 2005;
char lab[MAXT][MAXT];
vector<coord> movements;
stack<coord> review;
 
vector<coord> inicializerMovements() {
    movements.push_back({-1, 0});
    movements.push_back({1, 0});
    movements.push_back({0, -1});
    movements.push_back({0, 1});
    
    return movements;
}
 
int visit (coord cell, int n, int m) {
    int cont = 0;
    int change = -1;
    coord aux;
    for(int i = 0; i < 4; i++) {
        aux = cell + movements[i];
        if(aux.first >= 0 && aux.second >= 0 && aux.first < n && aux.second < m && lab[aux.first][aux.second] == '.') {
            cont++;
            change = i+1;
        }
    }
 
    if(cont != 1) return -1;
    else return change;
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    inicializerMovements();
    int n, m, cont = 0;
    int adjacency;
    coord cell, aux;
    cin >> n >> m;
    
    for(int idRow = 0; idRow < n; idRow++) 
        cin >> lab[idRow];
    
    for(int idRow = 0; idRow < n; idRow++) {
        for(int idColumn = 0; idColumn < m; idColumn++) {
            if(lab[idRow][idColumn] == '*')
                cont++;
            if(lab[idRow][idColumn] != '.')
                continue;
 
            review.push(make_pair(idRow, idColumn));
 
            while(!review.empty()) {
                cell = review.top();
                review.pop();
                adjacency = visit(cell, n, m);
                    
                if(adjacency != -1) {
                    cont += 2;
 
                    if(adjacency == 1) {
                        lab[cell.first][cell.second] = 'v';
                        cell = cell + movements[adjacency-1];
                        lab[cell.first][cell.second] = '^';
                    }
                    else if(adjacency == 2) {
                        lab[cell.first][cell.second] = '^';
                        cell = cell + movements[adjacency-1];
                        lab[cell.first][cell.second] = 'v';
                    }
                        
                    else if(adjacency == 3) {
                        lab[cell.first][cell.second] = '>';
                        cell = cell + movements[adjacency-1];
                        lab[cell.first][cell.second] = '<';
                    }
                        
                    else {
                        lab[cell.first][cell.second] = '<';
                        cell = cell + movements[adjacency-1];
                        lab[cell.first][cell.second] = '>';
                    }
 
                    for(int i = 0; i < 4; i++) {
                        aux = cell + movements[i];
                        if(aux.first >= 0 && aux.second >= 0 && aux.first < n && aux.second < m && lab[aux.first][aux.second] == '.')
                            review.push(aux);
                    }
                }
            }
        }
    }
    
    if(cont == m*n) {
        for(int idRow = 0; idRow < n; idRow++) {
            for(int idColumn = 0; idColumn < m; idColumn++)
                cout << lab[idRow][idColumn];
            cout << "\n";
        }
    }
    else
        cout << "Not unique\n";
 
 
    return 0;
}