#include "../template.h"

/*
- Sirve para contestar queries sobre la cantidad de pasos que hay 
  que dar desde un nodo 'a' para llegar a un nodo 'b'.
- Complejidad: O(n * log(n)) del precalculo, O(log(n)) por query.

- isCicle marca si un nodo hace parte de un ciclo o no.
- liderCicle guarda el lider de cada ciclo.
- stCicle guarda la distancia desde un nodo de un ciclo hasta su 
  lider.
- lenCicle[i] si el nodo 'i' es lider de un ciclo dice la longitud
  de este, si no dice 0.
- distCicle guarda la distancia de un nodo cualquiera a un ciclo.
- whereCicle guarda para cada nodo fuera de un ciclo cual es el 
  nodo mas cercano que esta en un ciclo.
*/

int LOG_N = 18; // techo del log2 del maximo valor de k que me puedan dar en las queries
const int maxn = 2e5 + 1;
int n;
vi func(maxn), liderCicle(maxn), stCicle(maxn), lenCicle(maxn), distCicle(maxn), whereCicle(maxn);
vb vis(maxn), isCicle(maxn);
vector<vi> succ(LOG_N, vi(maxn)); // TAMBIEN COPIAR "GRAFO FUNCIONAL KTH STEP"

void calcSucc(){
    for1(i,n) succ[0][i] = func[i];
    for1(bit,LOG_N-1) for1(i,n) succ[bit][i] = succ[bit-1][succ[bit-1][i]];
}

int kSucc(int s, int k){
    for0(bit,LOG_N) if(k & (1 << bit)) s = succ[bit][s];
    return s;
}

// Precalcula isCicle, liderCicle, stCicle y lenCicle
void floyd(int x){
    vis[x] = 1;
    int a = func[x];
    int b = func[func[x]];

    while(a != b){
        if(vis[a]) return; // Saltar en caso de que ya haya calculado esta rama desde un nodo inferior
        vis[a] = 1; // Marcar los nodos externos a un ciclo que ya han sido visitados
        a = func[a];
        b = func[func[b]];
    }

    a = x;
    while(a != b){
        a = func[a];
        b = func[b];
    }
    if(isCicle[b]) return; // Ya fue procesado este ciclo

    int lider = b;
    liderCicle[lider] = b; // Se guarda el lider
    isCicle[b] = 1;
    lenCicle[b] = 1;
    int last = 0;
    vis[lider] = 1;
    b = func[b];
    while(a != b){
        liderCicle[b] = lider;
        lenCicle[lider]++; // Al llegar a otro nodo se aumenta la longitud del ciclo
        last++;
        stCicle[b] = last;
        isCicle[b] = 1;
        vis[b] = 1; // Se marcan como visitados todos los nodos del ciclo
        b = func[b];
    }
}

// Precalcula whereCicle y distCicle para los nodos fuera de un ciclo
void DFS(int u){
    int v = func[u];
    if(isCicle[v]){
        whereCicle[u] = v;
        distCicle[u] = 1;
    }
    else if(distCicle[v]){
        whereCicle[u] = whereCicle[v];
        distCicle[u] = distCicle[v] + 1;
    }
    else{
        DFS(v);
        whereCicle[u] = whereCicle[v];
        distCicle[u] = distCicle[v] + 1;
    }
}

void solver(){
    int q; cin>>n>>q; // n se declaro global
    vi inDegree(n+1);
    for1(i,n){
        cin>>func[i];
        inDegree[func[i]]++;
    }
    calcSucc();

    for1(i,n) if(!vis[i]) floyd(i);

    for1(i,n){
        if(inDegree[i]) continue;
        DFS(i);
    }

    while(q--){
        int a, b; cin>>a>>b;
        if(a == b){
            cout<<0<<endl;
            continue;
        }

        // Si ambos son parte de un ciclo primero se verifica si es el mismo y luego se calcula la distancia usando stCicle
        if(isCicle[a] && isCicle[b]){
            if(liderCicle[a] != liderCicle[b]) cout<<-1<<endl;
            else cout<<(stCicle[b] - stCicle[a] + lenCicle[liderCicle[a]]) % lenCicle[liderCicle[a]]<<endl;
        }

        // Si ninguno hace parte de ciclo se verifica si hacen parte de la misma rama (usando whereCicle), despues se usa
        // distCicle para calcular dif (a que distancia deberia estar 'a' de 'b') y si es positiva se usa kSucc para verificar que
        // al dar dif pasos desde 'a' se llega hasta 'b' (ya que estas ramas son arboles y se requiere que 'b' sea ancestro de 'a').
        else if(!isCicle[a] && !isCicle[b]){
            if(whereCicle[a] != whereCicle[b]) cout<<-1<<endl;
            else{
                int dif = distCicle[a] - distCicle[b];
                if(dif <= 0) cout<<-1<<endl;
                else{
                    if(kSucc(a, dif) == b) cout<<dif<<endl;
                    else cout<<-1<<endl;
                }
            }
        }

        // Si 'a' no esta en ciclo pero 'b' si, se revisa si 'a' llega al ciclo de 'b' (usando whereCicle) y en caso de que si se
        // suma la distancia de a hasta un ciclo y se usa whereCicle[a] y stCicle para calcular cuanto se tarda desde whereCicle[a] hasta b
        else if(!isCicle[a] && isCicle[b]){
            if(liderCicle[whereCicle[a]] != liderCicle[b]) cout<<-1<<endl;
            else cout<<distCicle[a] + ((stCicle[b] - stCicle[whereCicle[a]] + lenCicle[liderCicle[b]]) % lenCicle[liderCicle[b]])<<endl;
        }

        // Si a esta en un ciclo y b no, no se puede
        else cout<<-1<<endl;
    }
}