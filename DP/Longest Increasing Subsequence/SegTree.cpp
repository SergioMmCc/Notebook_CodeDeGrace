#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const int maxn = 200001, ninf = -1e9 - 5;

// Esta implementacion es 0-index
/* 
    Para hallar el LIS usando Segment Tree, decimos que 
    t[a[i]] = max(t[0], t[1], ..., t[a[i] - 1]) + 1
    Esta definicion quiere decir que el LIS que puedo obtener finalizando en el 
    valor a[i] es igual a 1 mas el mayor de los LIS para j < i && a[j] < a[i]
    Para hallar el valor mayor usamos Segment Tree.
    
    Adicionalmente, para saber la cantidad total de Increasing Subsequence's
    que tiene el array a, simplemente tenemos que modificar este enfoque 
    haciendo que el Segment Tree no nos de el maximo en un rango si no la
    suma en un rango. Tener en cuenta que el valor puede ser muy grande asi
    que es necesario usar modularidad.
*/
// Complejidad: O(n * lgn)
// El arbol del segment tree va a servir para representar el array t
vector<int> tree(4*maxn);
int n;

void updateTree(int update, int value){
    tree[n + update] = value;
    update += n;
    for(int i = update; i > 1; i >>= 1) tree[i>>1] = max(tree[i], tree[i ^ 1]); //Si i es el hijo por izquierda de i/2, entonces i ^ 1 es el hijo por derecha, y viceversa
    //i >> i -> i/2
}

// La implementacion es [l, r)
int query(int l, int r){
    int ans = ninf;
    l += n; r += n; 
    while(l < r){
        if(l & 1) ans = max(ans, tree[l++]);
        if(r & 1) ans = max(ans, tree[--r]);
        l >>= 1; r >>= 1;
    }
    
    return ans;
}

void solver(){
    cin>>n;
    map<int, int> comp;
    int next = 0;
    vector<int> ori(n), sorted(n), a(n);

    for(int i = 0; i < n; i++) cin>>ori[i];
    sorted = ori;
    sort(sorted.begin(), sorted.end());

    // Comprimir
    for(int i = 0; i < n; i++){
        if(!comp.count(sorted[i])){
            comp[sorted[i]] = next;
            next++;
        }
    }
    for(int i = 0; i < n; i++) a[i] = comp[ori[i]];

    for(int i = 0; i < n; i++){
        int maxi;
        // Si a[i] es 0 no hacer query ya que dara menos infinito debido a que el intervalo seria [0, 0)
        if(!a[i]) maxi = 0; 
        else maxi = query(0, a[i]); // Consultar el mayor t[i] entre los valores menores a a[i]
        updateTree(a[i], maxi + 1); // Actualizar con el valor ddel mayor de los antecesores + 1
    }

    cout<<query(0, n)<<endl; // La respuesta es el valor maximo de t
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