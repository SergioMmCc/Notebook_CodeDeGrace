#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    int n, q;cin >> n >> q;
    int save;
    char sig;
    int conjunto = 1;
    
    map<int, int> order;
    vector<map<int, int>> search;
    search.resize(100100);
    vector<int> pares(100100, 0);
    int impares = 0;
    
    for (int i = 1; i < n; i++) {
        cin >> save >> sig;
        save %= 2;
        order[i] = conjunto;
        search[conjunto][i] = save;
        
        if (save == 0) 
            pares[conjunto]++;
        
        if (sig == '+' || sig == '-') {
            if (pares[conjunto] == 0)
                impares++;
            conjunto++;
        }
    }
    cin >> save;
    save %= 2;
    order[n] = conjunto;
    search[conjunto][n] = save;
    if (save == 0)
        pares[conjunto]++;
    if (pares[conjunto] == 0)
        impares++;
        
    if (impares % 2 == 1)
        cout << "odd\n";
    else
        cout << "even\n";
     
    int id, find, aux;   
    while (q--) {
        cin >> id >> save;
        save %= 2;
        find = order[id];
        aux = search[find][id];
        if (aux == 1 && save == 0) {
            search[find][id] = 0;
            pares[find]++;
            
            if (pares[find] == 1)
                impares--;
        }
        if (aux == 0 && save == 1) {
            search[find][id] = 1;
            pares[find]--;
            
            if (pares[find] == 0)
                impares++;
        }
        
        if (impares % 2 == 1)
            cout << "odd\n";
        else
            cout << "even\n";
    }

    return 0;
}