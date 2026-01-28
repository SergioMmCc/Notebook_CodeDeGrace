#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

string toLower(string s){
	string ans = "";
	for(int i=0; i<s.size(); i++){
		if('a' <= s[i] && s[i] <= 'z')
		ans.push_back(s[i]);
		else
		ans.push_back(s[i] + ('a' - 'A'));
	}
	return ans;
}

bool isAsc(string s){
	for(int i=1; i<s.size(); i++){
		if(s[i] < s[i-1])	
		return false;
	}
	return true;
}

bool isDesc(string s){
	for(int i=1; i<s.size(); i++){
		if(s[i] > s[i-1])	
		return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	string s;
	cin>>s;
	s = toLower(s);
	if(isAsc(s) || isDesc(s)) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}