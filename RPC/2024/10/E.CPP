#include<bits/stdc++.h>
using namespace std;
#define ednl '\n'

const int maxN = 200000;
int ps[26][maxN+1];

int getMaxRep(int l, int r){
	int maxRep = 0;
	for(int i=0; i<26; i++)
	maxRep = max(maxRep, ps[i][r] - ps[i][l-1]);
	return maxRep;
}

bool validate(int l, int r, int m){
	int size = r+1-l, maxRep = getMaxRep(l, r);
	return size-maxRep <= m;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	string s; cin>>s;
	int m, k; cin>>m;
	k = s.size() - m;

	// prefix sum
	for(int i=0; i<26; i++)
	ps[i][0] = 0;
	for(int j=1; j<=s.size(); j++){
		for(int i=0; i<26; i++)
		ps[i][j] = ps[i][j-1];
		ps[s[j-1]-'a'][j]++;
	}

	int ans = 0;
	for(int i=0; i<s.size(); i++){
		// binary search
		int first = i, last = s.size()-1;
		while(first < last){
			int middle = (first + last + 1) / 2;
			if(validate(i+1,middle+1,m)) first = middle;
			else last = middle - 1;
		}
		int aux = getMaxRep(i+1, first+1);
		ans = max(ans, aux);
	}
	cout<<ans<<endl;
}