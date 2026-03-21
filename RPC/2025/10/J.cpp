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
    int n; cin>>n;
    set<string> dic;
    for(int i = 0; i < n; i++){
        string save; cin>>save;
        dic.insert(save);
    }

    int m; cin>>m;
    while(m--){
        string s; cin>>s;
        if(dic.find(s) != dic.end()){
            cout<<1<<endl;
            continue;
        }

        bool cond = 0;
        for(int i = 1; !cond && i < s.sz; i++){
            string a = "", b = "";
            for(int j = 0; j < s.sz; j++){
                if(j < i) a += s[j];
                else b += s[j];
            }

            if(dic.find(a) != dic.end() && dic.find(b) != dic.end()) cond = 1;
        }

        cout<<(cond ? 2 : 0)<<endl;
    }
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