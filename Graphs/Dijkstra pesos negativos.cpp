struct comparator{
	bool operator() (pii a, pii b){
		return a.second > b.second;
	}
};

const int maxN = 5000;
vector<pii> graph[maxN+1];
vector<int> dist(maxN);

void dijkstra(int n, int z){
	priority_queue<pii, vector<pii>, comparator> pq;
	vector<int> S(n+1);
	for(int x=1; x<=n; x++){
		dist[x] = inf;
		S[x] = 0;
	}
	dist[z] = 0;

	pq.push(pii(z,0));
	while(!pq.empty()){
		pii p = pq.top(); pq.pop();
		int x = p.first;
		S[x] = 1;
		for(int i=0; i<graph[x].size(); i++){
			int y = graph[x][i].first;
			int w = graph[x][i].second;
			if(dist[x]+w < dist[y]){
				dist[y] = dist[x] + w;
				pq.push(pii(y,w));
			}
		}
	}
}