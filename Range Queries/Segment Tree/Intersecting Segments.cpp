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

const int maxn = 2e5 + 1;

// Implementacion con array 0-index
// Todas las operaciones se hacen inicialmente con v = 1, tl = 0, tr = n - 1
/*
    Para cada segmento cuenta la cantidad de otros segmentos con los cuales
    intersecta.
    Los recorre en orden del primero en r (que termina primero). Cuando llega 
    a l de algun segmento, asigna un 1 en esa posicion, cuando llega a r asigna
    la posicion l en -1 y r en 1. Para saber la cantidad pregunta la suma en el 
    [l, r].
    Todos los puntos de los segmentos son diferentes entre si.
*/ 
vector<ll> tree(4*maxn);

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) tree[v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
}

// Las queries son [l, r]
ll query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return tree[v];

    int tm = (tl + tr) / 2;
    return query(2*v, tl, tm, l, min(tm, r))
         + query(2*v + 1, tm + 1, tr, max(tm + 1, l), r);
}

void update(int v, int tl, int tr, int pos, ll val){
    if(tl == tr) tree[v] = val;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2*v, tl, tm, pos, val);
        else update(2*v + 1, tm + 1, tr, pos, val);
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
}

void solver(){
    int n; cin>>n;
    int n2 = 2*n;
    vector<int> a(n2);
    for(int i = 0; i < n2; i++){cin>>a[i]; a[i]--;}

    vector<int> ans(n), st(n, -1);
    for(int i = 0; i < n2; i++){
        int num = a[i];
        if(st[num] == -1){ // Si no he tocado el extremo izquierdo, lo guardo, asigno 1 en l y sigo
            st[num] = i;
            update(1, 0, n2 - 1, i, 1);
            continue;
        }

        int l = st[num];
        update(1, 0, n2 - 1, l, -1); // Asigno -1 en l
        update(1, 0, n2 - 1, i, 1); // Asigno 1 en r
        ans[num] = query(1, 0, n2 - 1, l, i); // Pregunto por la suma desde l hasta i
    }

    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<ans[i];
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