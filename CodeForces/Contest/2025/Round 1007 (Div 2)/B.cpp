#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;
set<int> squ;
void calcSqu(){
    for(int i = 1; i <= 5e5 + 1; i++) squ.insert(i*i);
}

void solver(){
    int n; cin>>n;
    if(squ.find((n * (n+1)) / 2) != squ.end()){
        cout<<-1<<endl;
        return;
    }

    int count = 0;
    vector<int> ans;
    bool last = 0;
    for(int i = 1; i <= n; i++){
        if(last){
            ans.pb(i-1);
            count += i-1;
            last = 0;
        }
        else if(squ.find(count + i) != squ.end()){
            ans.pb(i+1);
            count += i+1;
            last = 1;
        }
        else{
            ans.pb(i);
            count += i;
        }
    }

    for(int i : ans) cout<<i<<' ';
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcSqu();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}