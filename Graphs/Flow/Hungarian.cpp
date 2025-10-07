#include <bits/stdc++.h>
using namespace std;

/* 
    0-index.
    Sea n la cantidad en el lado izquierdo y m la cantidad en el lado
    derecho, se requiere n >= m, es decir, deben haber igual o mas 
	workers que jobs.
    Minimo costo para el maximum matching de un bipartito ponderado.
    Para explicar el algoritmo se documenta utilizando worker (W) como L
    y job (J) como R. Cada trabajador cobra cierta cantidad por realizar
    cierto trabajo sin embargo cada trabajador solo puede realizar un 
    trabajo. Se halla el menor costo para realizar todos los trabajos.
    Complejidad: O(J * W^2)
    Suele ser un poco mas eficiente que el algoritmo de MaxFlow MinCost.
*/

int ckmin(int &a, int b) { return a > b ? ((a = b), true) : false; }

/**
 * return the jobs of each worker in the optimal assignment,
 * or -1 if the worker is not assigned
 */
template <class T> vector<int> hungarian(const vector<vector<T>> &C){
	int J = C.size();
	int W = C[0].size();
	assert(J <= W); // Verifica que el lado izquierdo (W) sea mayor o igual al lado derecho (J)

	// job[w] = job assigned to w-th worker, or -1 if no job assigned
	// note: a W-th worker was added for convenience
	vector<int> job(W + 1, -1);
	vector<T> h(W);  // Johnson potentials

	const T inf = numeric_limits<T>::max();
	// assign j_cur-th job using Dijkstra with potentials
	for(int j_cur = 0; j_cur < J; j_cur++){
		int w_cur = W;  // unvisited worker with minimum distance
		job[w_cur] = j_cur;

		vector<T> dist(W + 1, inf);  // Johnson-reduced distances
		dist[W] = 0;
		vector<bool> vis(W + 1);     // whether visited yet
		vector<int> prv(W + 1, -1);  // previous worker on shortest path
		while(job[w_cur] != -1){   // Dijkstra step: pop min worker from heap
			T min_dist = inf;
			vis[w_cur] = true;
			int w_next = -1;  // next unvisited worker with minimum distance

			// consider extending shortest path by w_cur -> job[w_cur] -> w
			for(int w = 0; w < W; w++){
				if(!vis[w]){
					// sum of reduced edge weights w_cur -> job[w_cur] -> w
					T edge = C[job[w_cur]][w] - h[w];
					if (w_cur != W) {
						edge -= C[job[w_cur]][w_cur] - h[w_cur];
						assert(edge >= 0);
					}
					if (ckmin(dist[w], dist[w_cur] + edge)) { prv[w] = w_cur; }
					if (ckmin(min_dist, dist[w])) { w_next = w; }
				}
			}
			w_cur = w_next;
		}

		for(int w = 0; w < W; w++){  // update potentials
			ckmin(dist[w], dist[w_cur]);
			h[w] += dist[w];
		}

		while(w_cur != W){  // update job assignment
			job[w_cur] = job[prv[w_cur]];
			w_cur = prv[w_cur];
		}
	}

	return job; // Retorna la mejor asignacion encontrada
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> c(n, vector<int>(n));

	for(int i = 0; i < n; i++){ // ith job
		for(int j = 0; j < n; j++){ // jth worker
            cin>>c[i][j]; 
        }
	}

	vector<int> mat = hungarian(c);

    // Se suma segun el costo de que el job mat[i] sea realizado por el worker i
	int cost = 0;
	for (int i = 0; i < n; i++) cost += c[mat[i]][i]; 
	cout<<cost<<endl;
	for(int i = 0; i < n; i++) cout<<mat[i]<<' '<<i<<endl; // El job mat[i] es realizado por el worker i
}