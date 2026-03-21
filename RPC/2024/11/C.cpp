#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solver(){
	string a;cin>>a;
	vector<ll> freq(7);
	ll ans = 0;
	for(int i = 0; i < a.size(); i++){
		ll number; int search;
		if(a[i] == 'I'){
			number = 1;
			search = 0;
			freq[0]++;
		}
		else if(a[i] == 'V'){
			number = 5;
			search = 1;
			freq[1]++;
		}
		else if(a[i] == 'X'){
			number = 10;
			search = 2;
			freq[2]++;
		}
		else if(a[i] == 'L'){
			number = 50;
			search = 3;
			freq[3]++;
		}
		else if(a[i] == 'C'){
			number = 100;
			search = 4;
			freq[4]++;
		}
		else if(a[i] == 'D'){
			number = 500;
			search = 5;
			freq[5]++;
		}
		else{
			number = 1000;
			search = 6;
			freq[6]++;
		}

		ans += number;

		for(int j = search-1; j >= 0; j--){
			if(j == 5) {
				ans -= 2*500*freq[j];
				freq[j] = 0;
			}
			else if(j == 4) {
				ans -= 2*100*freq[j];
				freq[j] = 0;
			}
			else if(j == 3) {
				ans -= 2*50*freq[j];
				freq[j] = 0;
			}
			else if(j == 2) {
				ans -= 2*10*freq[j];
				freq[j] = 0;
			}
			else if(j == 1) {
				ans -= 2*5*freq[j];
				freq[j] = 0;
			}
			else if(j == 0) {
				ans -= 2*1*freq[j];
				freq[j] = 0;
			}
		}
		//cout<<"i -> "<<i<<" ans -> "<<ans<<endl;
	}

	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		solver();
	}

	return 0;
}