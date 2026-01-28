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
    int n, k; cin>>n>>k;
    string s; cin>>s;
    if(s.sz == 1){
        cout<<"NO"<<endl;
        return;
    }
    
    if(!k){
        string aux = "";
        for(int i = n-1; i >= 0; i--){
            aux += s[i];
        }
        cout<<(s < aux ? "YES" : "NO")<<endl;
    }

    else{
        char last = s[0];
        bool cond = 0;
        for(int i = 0; !cond && i < n; i++){
            if(s[i] != last) cond = 1;
        }cout<<(cond ? "YES" : "NO")<<endl;
    }

    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}