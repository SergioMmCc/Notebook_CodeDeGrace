void dijkstra (struct graph *G, int d[], int pi[], int s) {
	int u, v, w, heapSize = 0;
	struct nodePQ Q[MAXV + 1];
	int positionVertex[MAXV + 1];
	struct edge *tempEdge;

	for(u = 1; u <= G->n_vertex; u++) {
		pi[u] = NIL;
		d[u] = myInfinite;
	}
	d[s] = 0;
    MinPQ_Insert(Q, 0, 1, &heapSize, positionVertex);
	while(heapSize >= 1) {
		u = MinPQ_Extract(Q, &heapSize, positionVertex);

		if(d[u] == myInfinite)
			break;

		tempEdge = G->Adj[u];
		while(tempEdge != NULL) {
			v = tempEdge->vertex;
			w = tempEdge->weight;

			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pi[v] = u;
				MinPQ_Insert(Q, d[v], v, &heapSize, positionVertex);
				MinPQ_DecreaseKey(Q, positionVertex[v], d[v], positionVertex);
			}
			tempEdge = tempEdge->next;
		}
	}
}