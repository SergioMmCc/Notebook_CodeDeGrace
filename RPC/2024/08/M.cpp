#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

map<int,int> T;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, w; cin>>n>>w;
	for(int i=0; i<n; i++){
		int x; cin>>x;
		T[x]++;
	}
	int maxRep = 0;
	for(map<int,int>::iterator it=T.begin(); it!=T.end(); it++)
	maxRep = max(maxRep, it->second);
	if(maxRep <= w) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}