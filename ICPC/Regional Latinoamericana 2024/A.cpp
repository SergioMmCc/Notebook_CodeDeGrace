#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

void solver(){
    string s;cin>>s;
    set<char> letters;
    for(int i = 0; i < s.size(); i++){
        letters.insert(s[i]);
    }

    cout<<s.size() - letters.size()<<endl;
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