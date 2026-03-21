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
    int n0 = 1, n1 = 1;
    for(int i = 0; i < s.sz; i++){
        if(s[i] == '0'){
            cout<<3<<' '<<n0<<endl;
            n0++;
            if(n0 > 4) n0 = 1;
        }
        else{
            cout<<2<<' '<<n1<<endl;
            n1 += 2;
            if(n1 > 4) n1 = 1;
        }
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