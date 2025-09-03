#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    string s; cin>>s;
    bool t = 0, a = 0, p = 0;
    for(int i = 0; i < s.sz; i++){
        if(!t && s[i] == 'T') t = 1;
        else if(!a && t && s[i] == 'A') a = 1;
        else if(!p && a && s[i] == 'P') p = 1;
    }
    cout<<(p ? 'S' : 'N')<<endl;
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