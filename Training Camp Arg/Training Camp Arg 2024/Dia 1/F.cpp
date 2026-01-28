#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;

struct Comp {
	bool operator() (pii a, pii b) {
		return a.first < b.first;
	}
};

bool sortDesc(int a, int b){ return a > b; }

int gauss(int x){ return (x*(x+1)) / 2; }

int optimalReduction(int n, int r){
	int diff = n - r;
	int rep = diff / (r+1);
	return gauss(rep) * (r+1) + (rep+1) * (diff % (r+1));
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,k; cin>>n>>k;
	string s; cin>>s;
	vector<int> sequences;
	int counter = 0;
	for(int i=0; i<n; i++){
		if(s[i] == '0'){
			if(counter > 0)
			sequences.push_back(counter);
			counter = 0;
		}
		else
		counter++;
	}
	if(counter > 0)
	sequences.push_back(counter);
	sort(sequences.begin(), sequences.end(), sortDesc);

	int z = sequences.size();
	vector<int> f[z];
	for(int i=0; i<z; i++){
		f[i].clear();
		f[i].resize(sequences[i]+1);
		for(int j=0; j<=sequences[i]; j++)
		f[i][j] = optimalReduction(sequences[i],j);
	}

	int sum = 0;
	vector<int> pointers(z);
	priority_queue<pii, vector<pii>, Comp> pq;
	for(int i=0; i<z; i++){
		sum += f[i][0];
		pointers[i] = 1;
		if(f[i].size() >= 2)
		pq.push(pii(f[i][0] - f[i][1], i));
	}

	int ans = 0;
	while(sum > k && !pq.empty()){
		pii p = pq.top(); pq.pop();
		int diff = p.first, id = p.second;
		sum -= diff;
		pointers[id]++;
		if(pointers[id] < f[id].size())
		pq.push(pii(f[id][pointers[id]-1] - f[id][pointers[id]], id));
		ans++;
	}
	cout<<ans<<endl;
}