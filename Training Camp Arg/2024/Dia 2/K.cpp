#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;

bool sortPiiFirstAsc(pii a, pii b){ return a.first < b.first; }

bool sortPiiSecondDescFirstAsc(pii a, pii b){
	if(a.second != b.second)
	return a.second > b.second;
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	vector<pii> v(n);
	for(int i=0; i<n; i++){
		v[i].first = i;
		cin>>v[i].second;
	}
	sort(v.begin(), v.end(), sortPiiSecondDescFirstAsc);

	int m; cin>>m;
	while(m--){
		int k, pos; cin>>k>>pos;
		vector<pii> s(k);
		for(int i=0; i<k; i++)
		s[i] = v[i];
		sort(s.begin(), s.end(), sortPiiFirstAsc);
		cout<<s[pos-1].second<<endl;
	}
}