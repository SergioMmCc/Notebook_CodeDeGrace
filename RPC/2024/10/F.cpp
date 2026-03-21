#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ld = long double;

int main(){
	ld c1, m1, c2, m2; cin>>c1>>m1>>c2>>m2;
	ld mayor = c1 / (c1 + m1), menor = c2 / (c2 + m2);
	if(menor > mayor) swap(mayor, menor);
	if(c1 == 0 || c2 == 0 || m1 == 0 || m2 == 0){
		cout<<0<<endl;
		return 0;
	}
	ld n = 0.5;
	int ans = 1;
	bool cond = 0;
	while(!cond){
		if(n >= menor && n <= mayor){
			cond = true;
			continue;
		}
		ans++;
		if(mayor > n) {
			mayor -= n;
			menor -= n;
		}
		n /= 2;
	}

	cout<<ans<<endl;
	return 0;
}