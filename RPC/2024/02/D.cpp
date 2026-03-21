#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,k; cin>>n>>k;
	string ans(k, ' ');
	vector<string> v(n);
	for(int i=0; i<n; i++)
	cin>>v[i];
	for(int j=0; j<k; j++){
		vector<int> alp(26,0);
		for(int i=0; i<n; i++)
		alp[v[i][j]-'a']++;

		ans[j] = 'a';
		for(int i=0; i<26; i++){
			if(alp[i] > alp[ans[j]-'a'])
			ans[j] = 'a' + i;
		}
	}
	cout<<ans<<endl;
}