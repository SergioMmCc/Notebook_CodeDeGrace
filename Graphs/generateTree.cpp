/* Esta funcion sirve para cuando tenemos grafo tipo
arbol y queremos que se almacene como tal */

#include<bits/stdc++.h>
using namespace std;

const int maxN = 1000000;
vector<int> graph[maxN+1];
vector<int> tree[maxN+1];

void generateTree(int root){
	queue<int> Q;
	vector<int> S(maxN+1, 0);
	Q.push(root); S[root] = 1;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i=0; i<graph[x].size(); i++){
			int y = graph[x][i];
			if(S[y] == 0){
				S[y] = 1;
				Q.push(y);
				tree[x].push_back(y);
			}
		}
	}
}