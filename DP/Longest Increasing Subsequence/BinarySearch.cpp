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

const int inf = 1e9 + 1;

// Complejidad: O(n * log(n))
// - En este problema me piden el tamaño de la Longest Increasing
//   Subsequence (LIS). Una LIS es un array a donde para cada
//   i, j con i < j, a[i] < a[j].
// - Para hallar una Longest Non-Decreasing Subsequence, es decir,
//   el tamaño del mayor array a donde para cada i < j, a[i] <= a[j],
//   solo hay que revisar la inecuacion de la busqueda binaria
// - La Longest Decreasing Subsequence (LDS) es quivalente a el LIS
//   de un array invertido
// - Si me piden el menor numero de Increasing Subsequences, eso es
//   equivalente al tamaño de la Longest Non-Increasing Subsequence.
//   Es decir, el mayor tamaño de array a, donde para cada 
//   i < j, a[i] >= a[j]

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<int> d(n+1, inf); d[0] = -inf;

    for(int i = 1; i <= n; i++){
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), a[i]);
        if(it == d.end()) continue;

        int index = distance(d.begin(), it);
        // Este if se encarga de no poner numeros iguales
        // Si me piden que cada numero sea estrictamente mayor
        // Si piden mayor o igual se puede quitar
        if(a[i] > d[index - 1]) d[index] = a[i]; 
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] < inf) ans = i;
    }

    cout<<ans<<endl;
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