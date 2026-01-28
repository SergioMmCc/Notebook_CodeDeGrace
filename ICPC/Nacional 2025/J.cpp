#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver(string s){
    string a = "";
    for(int i = 0; i < s.size(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            if(s[i] >= 'A' && s[i] <= 'Z') a += s[i] - 'A' +'a';
            else a += s[i];
        }
        
    }

    // cout<<a<<endl;

    bool cond = 1;
    int n = a.size();
    for(int i = 0; cond && i < n; i++){
        if(a[i] != a[n - i - 1]) cond = 0;
    }

    cout<<(cond ? "Y" :"N")<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    string s; 
    while(getline(cin, s)){
        if(s == "*") return 0;
        solver(s);
    }

    return 0;
}