#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    string code; getline(cin,code);
    string era; getline(cin,era);

    set<char> st;
    for(int i = 0; i < era.sz; i++) st.insert(era[i]);

    string ans = "";
    for(int i = 0; i < code.sz; i++){
        if(st.find(code[i]) != st.end()) continue;
        if(code[i] == ' '){
            if(ans.sz == 0 || ans[ans.sz - 1] == ' ') continue;
            ans += ' ';
        }
        else{
            if(ans.sz == 0 || ans[ans.sz - 1] != code[i]) ans += code[i];
        }
    }

    for(int i = 0; i < ans.sz; i++){
        if(i == ans.sz - 1 && ans[i] == ' ') continue;
        cout<<ans[i];
    }

    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}