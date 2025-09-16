#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver() {
	ll a,b;
	cin>>a>>b;
	set<ll>ans;
	ans.insert(b);
	ans.insert(b+1);
	ans.insert((a+b)-b);
	ans.insert((a+b)-(b+1));
	cout<<((ll)ans.size()*(a+b)/2)<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t = 1;
	// cin>>t;
	while(t--) {
		solver();
	}

	return 0;
}