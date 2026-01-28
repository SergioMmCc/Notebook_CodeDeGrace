#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,m; cin>>n>>m;
	int table[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
		cin>>table[i][j];
	}
	for(int i=n-1; i>=1; i--){
		for(int j=m-1; j>=1; j--){
			if(table[i][j] == 0){
				int minimum = min(table[i+1][j], table[i][j+1]) - 1;
				table[i][j] = minimum;
			}
		}
	}
	bool cond = true; long long sum = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
		sum += table[i][j];
	}
	for(int i=0; i<n && cond; i++){
		for(int j=0; j<m && cond; j++){
			if((i+1<n && table[i][j] >= table[i+1][j]) || (j+1<m && table[i][j] >= table[i][j+1]))
			cond = false;
		}
	}
	if(cond) cout<<sum<<endl;
	else cout<<-1<<endl;
}