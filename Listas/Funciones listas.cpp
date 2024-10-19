#include<bits/stdc++.h>
using namespace std;

/* A partir de estas funciones se pueden simular listas ascendentes,
   circulares, enlazadas y doblemente enlazadas */

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
    list <int> lista;
	lista.push_back(1);
	len = lista.size();
	list<int>::iterator it1 = lista.begin();
	list<int>::iterator it2 = lista.end();
	lista.erase(it1);
	list<int>::iterator s1 = next(lista, s1);
	list<int>::iterator s2 = prev(lista, s1);
    
    return 0;
}