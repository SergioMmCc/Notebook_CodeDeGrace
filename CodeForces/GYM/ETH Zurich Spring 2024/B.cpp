#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxN = 100000;
const long long mod = 1e9 + 7;
vector<int> tree[maxN+1], counter(maxN+1);
vector<long long> pw2(maxN+1);

void precalculatePW2(){
	pw2[0] = 1;
	for(int i=1; i<=maxN; i++)
	pw2[i] = (pw2[i-1] * 2) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	precalculatePW2();
	int n; cin>>n;
	long long ans = 0;
	for(int i=1; i<n; i++){
		int x, y; cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
		counter[x]++; counter[y]++;
	}
	for(int x=1; x<=n; x++){
		for(int i=0; i<tree[x].size(); i++){
			int y = tree[x][i];
			counter[y]--;
		}
		ans = (ans + pw2[counter[x]] - 1) % mod;
		for(int i=0; i<tree[x].size(); i++){
			int y = tree[x][i];
			if(x < y)
			ans = (ans + pw2[counter[y]] - 1) % mod;
		}
	}
	cout<<ans<<endl;
}