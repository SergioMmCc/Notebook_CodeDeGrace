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
    int n; string s; cin>>n>>s;
    set<char> let; let.insert(s[0]);

    bool cond = 0;
    for(int i = 1; !cond && i < n - 1; i++){
        if(let.count(s[i])) cond = 1;
        else let.insert(s[i]);
    }

    let.clear();
    let.insert(s[n-1]);
    for(int i = n - 2; !cond && i > 0; i--){
        if(let.count(s[i])) cond = 1;
        else let.insert(s[i]);
    }

    cout<<(cond ? "Yes" : "No")<<endl;
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