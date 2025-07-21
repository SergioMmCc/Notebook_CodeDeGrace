#include <bits/stdc++.h>
#define dir first
#define val second
using namespace std;
using ll = long long;
const int top=2e5, INF=1e9, MOD=1e9+7;

char change(char a, char b){
    if(a == 'N'){
        return (b == 'W')? 'L' : 'R'; 
    }
    if(a == 'E'){
        return (b == 'N')? 'L' : 'R'; 
    }
    if(a == 'S'){
        return (b == 'E')? 'L' : 'R'; 
    }
    return (b == 'S')? 'L' : 'R'; 
    
}

void solve(){
    int n;
    cin>>n;
    vector<pair<char, int>> vec(n), ans; char c;
    for(int i=0; i<n; i++)cin>>vec[i].dir>>vec[i].val;
    c = vec[0].dir;

    for(int i=0; i<n; i++){
        ans.push_back({'Z', vec[i].val});
        if(i < n-1){
            ans.push_back({change(vec[i].dir, vec[i+1].dir), -1});
        }
    }

    cout<<ans.size()<<" "<<c<<"\n";
    for(auto [a, b] : ans){
        cout<<a;
        if(b != -1){
            cout<<" "<<b;
        }
        cout<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int t; cin>>t;
    while(t--) solve();
    return 0;
}