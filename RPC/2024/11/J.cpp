#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, m; cin>>n>>m;
	int ans = 0;
	vector<int> a;
	for(int i = 0; i < n; i++){
		int save; cin>>save;
		a.push_back(save);
	}
	sort(a.begin(), a.end());
	if(m > n) m = n;
	if(n % m == 0){
		if (2*m == n){
			for(int i = 0; i < (n + 1) / 2; i++){
				ans = max(ans, a[i] + a[n-1-i]);
				//cout<<i<<' '<<n-i<<endl;
			}
		}
		else ans = a[n-1];
	}
	else{
		int limit = 2 * (n % m);
			//cout<<"limit -> "<<limit<<endl;
		for(int i = 0; i < (limit + 1) / 2; i++){
			ans = max(ans, a[i] + a[limit-1-i]);
			//cout<<i<<' '<<limit-i-1<<endl;
		}

		ans = max(ans, a[n-1]);
	}

	cout<<ans<<endl;
	return 0;
}