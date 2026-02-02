#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Comparator{
	bool operator() (const int& a, const int& b) {
		return a > b;
	}
};

const int maxN = 10000, maxR = 100, maxC = 100;
int table[maxR][maxC], posI[maxN+1], posJ[maxN+1];
vector<int> S(maxN+1, 0);

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int r, c; cin>>r>>c;
	int n = r*c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>table[i][j];
			posI[table[i][j]] = i;
			posJ[table[i][j]] = j;
		}
	}
	int ans = 0;
	for(int z=1; z<=n; z++){
		if(S[z] == 0){
			int aux = 0, greater = 0;
			vector<int> inPQ(n+1, 0);
			priority_queue<int, vector<int>, Comparator> pq;
			pq.push(z);
			inPQ[z] = 1;
			while(!pq.empty()){
				int x = pq.top();
				pq.pop();
				if(x > greater){
					greater = x;
					aux++;
					S[x] = 1;
					int i = posI[x], j = posJ[x];
					for(int di=-1; di<=1; di++){
						for(int dj=-1; dj<=1; dj++){
							if(abs(di) + abs(dj) == 1){
								if(0 <= i+di && i+di < r && 0 <= j+dj && j+dj < c){
									int y = table[i+di][j+dj];
									if(inPQ[y] == 0){
										pq.push(y);
										inPQ[y] = 1;
									}
								}
							}
						}
					}
				}
			}
			ans = max(ans, aux);
		}
	}
	cout<<ans<<endl;
}