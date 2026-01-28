#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ld = long double;

const ld pi = 3.141592653589;

ld ssin(ld x) {
	int n = 20;
	ld sign = 1, factorial = 1, xp = x;
	ld ans = x;
	for(int i=1; i<=n; i++){
		sign *= -1;
		factorial *= (2*i) * (2*i + 1);
		xp *= x * x;
		ans += (sign * xp) / factorial;
	}
	return ans;
}

ld ccos(ld x) {
    int n = 20;
    ld sign = 1, factorial = 1, xp = 1;
    ld ans = 1;
    for(int i = 1; i <= n; i++) {
        sign *= -1;
        factorial *= (2*i - 1) * (2*i);
        xp *= x * x;
        ans += (sign * xp) / factorial;
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ld a, x;cin>>a>>x;
    ld dry = 2*(1 + sqrt(2))*x*x*(2 - sqrt(2));
    if(dry <= a){
        cout<<setprecision(6)<<fixed<<dry<<endl;
        return 0;
    }
    ld d = sqrt(2*x*x - 0.5*sqrt(16*x*x*x*x - a*a));
    dry = 2 * d * d * ccos(pi/8) / ssin(pi/8);
    cout<<setprecision(10)<<fixed<<dry<<endl;
    
    return 0;
}