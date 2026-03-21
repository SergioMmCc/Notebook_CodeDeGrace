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
    stack<char> ans;
    for(int i = 0; i < s.sz; i++){
        if(ans.empty() || ans.top() != s[i]){
            ans.push(s[i]);
        }
        else{
            // cout<<"tope -> "<<ans.front();
            ans.pop();
        }
    }

    stack<char> turn;
    while(!ans.empty()){
        turn.push(ans.top());
        ans.pop();
    }
    while(!turn.empty()){
        cout<<turn.top();
        turn.pop();
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