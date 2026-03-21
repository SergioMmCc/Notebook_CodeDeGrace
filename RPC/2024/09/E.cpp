#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const long double pw = 0.647110838434, ph = 0.352889161566;

long double Used(long double w, long double h){
	return (2.0 * (w+h)) + (2.0 * sqrt(w*w + h*h)) + sqrt(w*w + 4*h*h);
}

long double CalculateH(long double n, long double w){
	long double ep = 0.00000001;
	long double first = 0.0, last = 10000.0;
	while((last - first) > ep){
		long double middle = (first + last) / 2.0;
		long double h = middle;
		long double u = Used(w, h);
		if(u <= n) first = middle;
		else last = middle;
	}
	long double h = first;
	return h;
}

void solver(long double n){
	long double ep = 0.000000001;
	long double first = 0.005, last = n;
	while((last - first) > ep){
		long double l, r, wl, hl, wr, hr, al, ar;
		l = (2.0 * first + last) / 3.0;
		r = (first + 2.0 * last) / 3.0;
		wl = l;	hl = CalculateH(n, wl);
		wr = r; hr = CalculateH(n, wr);
		al = 1.5 * wl * hl;
		ar = 1.5 * wr * hr;	
		if(ar <= 0.0000001)
		last = r;
		else{
			if(al > ar) last = r;
			else first = l;
		}
	}
	long double w = first;
	long double h = CalculateH(n, w);
	long double area = 1.5 * w * h;
	cout<<fixed<<setprecision(12)<<area<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	long double n; cin>>n;
	solver(n);
}