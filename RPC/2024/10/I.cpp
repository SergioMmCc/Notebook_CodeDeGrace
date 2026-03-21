#include<bits/stdc++.h>
using namespace std;
#define ednl '\n'

const int maxN = 500000;
const int root = 700;
const int maxBlocks = 720;
vector<int> v(maxN+1, 0);
vector<int> block(maxN,0);

void add(int pos){
	int idBlock = pos / root;
	block[idBlock]++;
	v[pos]++;
}

int query(int l, int r){
	int ans = 0;
	int id1 = l/root, id2 = r/root;
	for(int i=l; i<=r; ){
		int id = i / root;
		if(i == (id*root) && l <= id*root && ((id+1)*root)-1 <= r){
			ans += block[id];
			i += root;
		}
		else{
			ans += v[i];
			i++;
		}
	}
	ans = r+1-l - ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,t;
	cin>>n>>t;
	while(t--){
		char op; cin>>op;
		if(op == 'R'){
			int pos; cin>>pos; add(pos);
		}
		else{
			int l, r; cin>>l>>r;
			cout<<query(l,r)<<endl;
		}
	}
}