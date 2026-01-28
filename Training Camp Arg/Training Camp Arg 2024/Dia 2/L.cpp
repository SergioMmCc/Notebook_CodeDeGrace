#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> ans;

int euclides(int a, int b){
	if(a == 0) return b;
	if(b == 0) return a;
	while(a % b != 0){
		int aux = a%b;
		a = b;
		b = aux;
	}
	return b;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> v(n), binc(30, 0);;
		for(int i=0; i<n; i++){
			int x; cin>>x;
			for(int j=0; j<30; j++){
				if((x & (1<<j)) > 0)
				binc[j]++;
			}
		}
		long long gcd = binc[0];
		for(int j=1; j<30; j++)
		gcd = euclides(gcd, binc[j]);

		for(int i=1; i<=n; i++){
			if(gcd % i == 0)
			ans.push_back(i);
		}
		for(int i=0; i<ans.size(); i++)
		cout<<((i > 0) ? " " : "")<<ans[i];
		cout<<endl;
		ans.clear();
	}
}