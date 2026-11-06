#include "../template.h"

/*
- Recibe los datos 1-index y los pasa a 0-index.
- Halla la descomposicion por centroides de un arbol.
- Se halla el centroide del arbol completo y se parte en
  subarboles eliminando ese nodo. Entonces se vuelve a
  hallar el centroide de cada subarbol y asi sucesivamente.
- Se dice que los centroides de los subarboles a los cuales 
  pertenece un nodo son sus ancestros, siendo el mayor 
  ancestro el centroide del arbol general (el cual tambien 
  es el unico nodo que no tiene ancestros).
- Cada nodo tiene a lo sumo log(n) ancestros, siendo 'n' la
  cantidad de nodos del arbol.
- En el vector ancestros se guardan los ancestros de cada 
  nodo y su distancia a estos. Iniciando en el centroide del 
  arbol completo y yendo hacia el del menor subarbol.
- UN ANCESTRO MAYOR QUE OTRO NO SIGNIFICA QUE ESTA MAS LEJOS.
- UN NODO NO SE INCLUYE A SI MISMO EN LA LISTA DE ANCESTROS.
EJEMPLO:
- En este ejemplo se tiene que inicialmente todos los nodos
  son azules excepto el nodo '0' el cual es rojo y hay 2 
  tipos de queries. Una es pintar el nodo 'v' de rojo y la 
  otra es consultar el nodo rojo mas cercano a 'v'.
- Solucion:
  * Primero se hace la descomposicion.
  * Cuando pinto un nodo 'v' de rojo le digo a todos mis
    ancestros que actualicen su distancia mas corta a un nodo
    rojo si es que yo estoy mas cerca que lo que tenian 
    guardado inicialmente.
  * Cuando hago una query para el nodo 'v', tengo en cuenta 
    que si 'v' es rojo la distancia al mas cercano es '0'.
  * Si no, reviso cual es la distancia minima que tiene a los 
    nodos rojos de su descendencia y guardo eso como respuesta 
    inicial.
  * Recorro mis ancestros y comparo la suma de la distancia a 
    mi ancestro y la distancia de mi ancestro a su nodo rojo 
    mas cercano, con la respuesta que tenia guardada y dejo
    la menor.
*/

vector<vi> adj;
vi subtree_size;
// min_dist[v] := the minimal distance between v and a red node
vi min_dist;
vb is_removed;
vector<vii> ancestors;

// O(s) sea s el tamaño del subarbol
int get_subtree_size(int node, int parent = -1){
	subtree_size[node] = 1;
	for(int child : adj[node]){
		if(child == parent || is_removed[child]) { continue; }
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

// Halla el centroide del arbol o subarbol, teniendo en cuenta que en
// is_removed se han marcado los nodos que ya se han marcado como 
// centroides de algun subarbol, asi que se ignoran
// O(s) sea s el tamaño del subarbol
int get_centroid(int node, int tree_size, int parent = -1){
	for(int child : adj[node]){
		if(child == parent || is_removed[child]) { continue; }
		if(subtree_size[child] * 2 > tree_size){
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

/**
 * Calculate the distance between current `node` and the `centroid` it belongs
 * to. The distances between a node and all its centroid ancestors are stored
 * in the vector `ancestors`.
 * @param cur_dist the distance between `node` and `centroid`
 */
// O(s) sea s el tamaño del subarbol
void get_dists(int node, int centroid, int parent = -1, int cur_dist = 1){
	for(int child : adj[node]){
		if(child == parent || is_removed[child]) { continue; }
		cur_dist++;
		get_dists(child, centroid, node, cur_dist);
		cur_dist--;
	}
	ancestors[node].pb({centroid, cur_dist});
}

// O(n log(n)).
void build_centroid_decomp(int node = 0){
	int centroid = get_centroid(node, get_subtree_size(node));

	/*
	 * For all nodes in the subtree rooted at `centroid`, calculate their
	 * distances to the centroid
	 */
	for(int child : adj[centroid]){
		if(is_removed[child]) { continue; }
		get_dists(child, centroid, centroid);
	}

	is_removed[centroid] = true;
	for(int child : adj[centroid]){
		if(is_removed[child]) { continue; }
		// build the centroid decomposition for all child components
		build_centroid_decomp(child);
	}
}

/**
 * Paint `node` red by updating all of its ancestors' minimal distances
 * to a red node. O(logn).
 */
void paint(int node){
	for(auto &[ancestor, dist] : ancestors[node]){
		min_dist[ancestor] = min(min_dist[ancestor], dist);
	}
	min_dist[node] = 0;
}

/** Print the minimal distance between `node` to a red node. O(logn) */
void query(int node){
	int ans = min_dist[node];
	for(auto &[ancestor, dist] : ancestors[node]){
		if(!dist) { continue; }
		/*
		 * The distance between `node` and a red painted node is the sum of
		 * the distance from `node` to one of its ancestors (`dist`) and the
		 * distance from this ancestor to the nearest red node
		 * (`min_dist[ancestor]`).
		 */
		ans = min(ans, dist + min_dist[ancestor]);
	}

	cout<<ans<<endl;
}

// O(nlog(n) + mlog(n))
void solver(){
	int n, m; cin>>n>>m; // n es la cantidad de nodos y m la cantidad de queries
	
	adj.assign(n, vi());
	for1(i,n-1){ // Construccion del arbol
		int a, b; cin>>a>>b; a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	subtree_size.assign(n, 0);
	ancestors.assign(n, vii());
	is_removed.assign(n, false);
	build_centroid_decomp();

	min_dist.assign(n, INF); // AL inicio sin nodos rojos, todas las distancias son infinitas
	paint(0); // En el ejemplo el nodo '0' inicia siendo rojo.
	while(m--){
		int t, v; cin>>t>>v; v--;
		if(t == 1) paint(v); // Pintar un nodo de rojo
		else query(v); // Consultar el nodo rojo mas cercano
	}
}





/*
=====================================================================
CONTAR CAMINOS CON LONGITUD EN [L, R] (inclusive) USANDO
DESCOMPOSICION POR CENTROIDES
=====================================================================

Para contar caminos con longitud en [L, R] hay que cambiar la tecnica.
`ancestors`, `min_dist`, `paint` y `query` ya no sirven para esto,
porque `ancestors[v]` guarda la distancia al centroide pero no dice a
cual subarbol hijo del centroide pertenece `v`, y eso se necesita para
no contar pares cuyo camino real no pasa por el centroide.

IDEA:
Para cada centroide `c` se cuentan los caminos que PASAN por `c`. Cada
camino se cuenta exactamente una vez, en el primer centroide que lo
"corta". Para un componente con centroide `c`:
  1. Se recolectan las profundidades (distancia a `c`) de todos sus
     nodos, incluyendo `c` con profundidad 0.
  2. Se cuentan los pares ordenados (u, v) con d_u + d_v en [L, R]
     usando un arreglo de frecuencias y sumas prefijas.
  3. Se restan los pares donde `u` y `v` estan en el MISMO subarbol
     hijo, porque su camino real no pasa por `c`.
  4. Se divide entre 2, porque los pares estaban ordenados.
Los pares (u, u) aparecen en ambos conteos y se cancelan solos.
Esto asume L >= 1.

CAMBIOS EN LO QUE YA TENIAS:
  - Ya no hacen falta `ancestors`, `min_dist`, `get_dists`, `paint`
    ni `query`.
  - Se siguen usando `adj`, `subtree_size`, `is_removed`,
    `get_subtree_size` y `get_centroid` (sin cambios).
  - En `build_centroid_decomp` el bloque de `get_dists` se reemplaza
    por la llamada a `count_paths`, ANTES de marcar el centroide como
    removido.
  - En `main` basta con leer L y R, construir el arbol, llamar a
    `build_centroid_decomp()` e imprimir `total_paths`.

COMPLEJIDAD (s = tamano del componente sobre el que se llama):
  - collect_depths:          O(s)
  - count_pairs:             O(s), porque la profundidad maxima es <= s
  - count_paths:             O(s)
  - build_centroid_decomp:   O(n log n) en total

DETALLES:
  - Tipo de dato: el resultado puede llegar a n(n-1)/2, asi que se
    usa long long.
  - Pares no ordenados: el resultado cuenta cada camino una sola vez.
    Si necesitas pares ordenados, multiplica por 2.
  - Por que count_pairs(todos) - sum count_pairs(hijo): dos nodos del
    mismo hijo cumplen d_u + d_v en el rango pero su distancia real es
    menor, asi que se contarian mal. Se restan con el mismo calculo, y
    esos caminos se cuentan bien mas adelante, en el centroide del
    subarbol que los contiene.
  - Recursion: collect_depths tiene el mismo riesgo de profundidad O(n)
    que get_subtree_size en arboles tipo camino.
*/

vector<vi> adj;
vi subtree_size;
vb is_removed;

long long total_paths = 0;
int L, R; // rango de longitudes, inclusive (L >= 1)

int get_subtree_size(int node, int parent = -1){
	subtree_size[node] = 1;
	for(int child : adj[node]){
		if(child == parent || is_removed[child]) { continue; }
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1){
	for(int child : adj[node]){
		if(child == parent || is_removed[child]) { continue; }
		if(subtree_size[child] * 2 > tree_size){
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

// Guarda en `depths` la distancia al centroide de cada nodo del subarbol.
// O(s).
void collect_depths(int node, int parent, int d, vi &depths){
	depths.pb(d);
	for(int child : adj[node]){
		if(child == parent || is_removed[child]) { continue; }
		collect_depths(child, node, d + 1, depths);
	}
}

/**
 * Cuenta los pares ORDENADOS (i, j), incluyendo i == j, tales que
 * depths[i] + depths[j] esta en [L, R]. O(depths.size()).
 */
long long count_pairs(const vi &depths){
	int mx = *max_element(depths.begin(), depths.end());
	// pref[d] := cantidad de nodos con profundidad <= d
	vector<long long> pref(mx + 1, 0);
	for(int d : depths) pref[d]++;
	for(int d = 1; d <= mx; d++) pref[d] += pref[d - 1];

	long long res = 0;
	for(int d : depths){
		// Se buscan los nodos con profundidad p tal que L <= d + p <= R
		int lo = max(0, L - d), hi = min(mx, R - d);
		if(lo > hi) { continue; }
		res += pref[hi] - (lo ? pref[lo - 1] : 0);
	}
	return res;
}

/** Suma a `total_paths` los caminos que pasan por `centroid`. O(s). */
void count_paths(int centroid){
	vi all_depths = {0}; // el centroide, a profundidad 0
	long long same_child = 0;

	for(int child : adj[centroid]){
		if(is_removed[child]) { continue; }
		vi depths;
		collect_depths(child, centroid, 1, depths);
		same_child += count_pairs(depths); // pares dentro del mismo hijo
		all_depths.insert(all_depths.end(), depths.begin(), depths.end());
	}

	// Pares ordenados totales menos los del mismo hijo, entre 2
	total_paths += (count_pairs(all_depths) - same_child) / 2;
}

void build_centroid_decomp(int node = 0){
	int centroid = get_centroid(node, get_subtree_size(node));

	count_paths(centroid); // caminos que pasan por este centroide

	is_removed[centroid] = true;
	for(int child : adj[centroid]){
		if(is_removed[child]) { continue; }
		build_centroid_decomp(child);
	}
}

int main() {
	int n; cin>>n>>L>>R; // n nodos y el rango [L, R] de longitudes

	adj.assign(n, vi());
	for1(i,n-1){ // Construccion del arbol (datos 1-index -> 0-index)
		int a, b; cin>>a>>b; a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	subtree_size.assign(n, 0);
	is_removed.assign(n, false);
	build_centroid_decomp();

	cout<<total_paths<<'\n';
}