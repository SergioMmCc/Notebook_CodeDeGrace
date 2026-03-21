#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,a,b,ans = 0; cin>>n>>a>>b;
	b *= 5;
	for(int i=0; i<=n; i+=b){
		int diff = n - i;
		int rep = diff / a;
		ans = max(ans, i + rep * a);
	}
	ans = n- ans;
	cout<<ans<<endl;
}