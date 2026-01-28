#include <bits/stdc++.h>
using namespace std;

list <int>::iterator next(list <int> &lista, list <int>::iterator i) {
    i++;
    if(i == lista.end())
        i = lista.begin();
    return i;
}

list <int>::iterator prev(list <int> &lista, list <int>::iterator i) {
    if (i == lista.begin()) 
        i = lista.end();
    i--;
    return i;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, r, c; cin >> n >> r >> c;
    r--;
    c--;
    list <int> lista;
    vector<int> ganadores;
    
    for (int i = 1; i <= n; i++)
        lista.push_back(i);
    list <int>::iterator s1 = lista.begin(), s2 = lista.end();
    s2--;
    list <int>::iterator aux1, aux2;
    
    int t1, t2;
    while (lista.size() > 2) {
        t1 = r % lista.size();
        t2 = c % lista.size();
        for (int i = 0; i < t1; i++) 
            s1 = next(lista, s1);
        for (int i = 0; i < t2; i++)
            s2 = prev(lista, s2);
        
        if (s1 == s2) {
            aux1 = s1;
            ganadores.push_back(*s1);
            s1 = next(lista, s1);
            s2 = prev(lista, s2);
            lista.erase(aux1);
        }
        else {
            aux1 = s1;
            aux2 = s2;
            s1 = next(lista, s1);
            s2 = prev(lista, s2);
            if (aux1 == s2) {
                s1 = next(lista, s1);
                s2 = prev(lista, s2);
            }
            lista.erase(aux1);
            lista.erase(aux2);
        }
    }
    for (list<int>::iterator i = lista.begin(); i != lista.end(); i++) 
        ganadores.push_back(*i);
    sort(ganadores.begin(), ganadores.end());
    for (int i = 0; i < ganadores.size()-1; i++) 
        cout << ganadores[i] << " ";
    cout << ganadores[ganadores.size()-1] << "\n";
    
    return 0;
}