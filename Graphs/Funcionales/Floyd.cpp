#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

// Source: https://usaco.guide/CPH.pdf#page=166
// Sirve para hallar el tamaño de un ciclo en un grafocuncional
// Complejidad: O(n)

// x es el nodo inicial desde el cual se va a buscar un ciclo
int floyd(int x, vi& func){
    int a = func[x];
    int b = func[func[x]];

    // En el momento en que a y b se encuentran, a ha caminado k pasos y b 2k pasos, 
    // entonces la longitud del ciclo divide k (k % len == 0)
    while(a != b){
        a = func[a];
        b = func[func[b]];
    }

    // El primer nodo que pertenece al ciclo (partiendo desde x) se encuentra moviendo 
    // el puntero a al nodo x y avanazando a y b paso por paso hasta que se encuentran 
    // de nuevo
    a = x;
    while(a != b){
        a = func[a];
        b = func[b];
    }
    int firstCycleNode = a;

    // En este punto tanto a como b estan parados en el nodo inicial del ciclo, entonces 
    // para hallar la longitud del ciclo simplemente se puede avanzar b paso por paso 
    // hasta que se vuelva a encontrar con a, la cantidad de pasos dados es la longitud 
    // del ciclo
    b = func[b];
    int length = 1;
    while(a != b){
        b = func[b];
        length++;
    }

    return length;
}