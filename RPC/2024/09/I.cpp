#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 6e18

const int maxN = 1000000;
vector<int> v(2*maxN+1);
vector<long long> accu(2*maxN+1), accuOdds(2*maxN+1);

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	for(int i=0; i<2*n; i++)
	cin>>v[i];
	reverse(v.begin(), v.begin()+2*n);

	accu[0] = v[0];
	for(int i=1; i<2*n; i++)
	accu[i] = accu[i-1] + v[i];

	accuOdds[1] = v[1];
	for(int i=3; i<2*n; i+=2)
	accuOdds[i] = accuOdds[i-2] + v[i];

	long long ans = inf;
	for(int i=n-1; i<2*n-1; i++){
		long long w, h, aux;
		h = v[2*n-1] + v[i];
		w = accu[2*n-1] - accu[i];

		int k = n - (2*n-1 - i);
		if(k >= 1)
		w += accuOdds[2*k-1];

		aux = w*h;
		ans = min(ans, aux);
	}
	cout<<ans<<endl;
}