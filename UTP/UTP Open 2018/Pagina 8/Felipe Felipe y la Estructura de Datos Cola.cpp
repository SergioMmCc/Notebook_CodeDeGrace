#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int qu; cin>>qu;
    int total = 0;
    queue<int> q;
    while(qu--){
        int op; cin>>op;
        if(op == 1){
            int v; cin>>v;
            total += v;
            q.push(v);
        }
        else if(op == 2){
            if(q.empty()) continue;
            int v = q.front();
            total -= v;
            q.pop();
        }

        else{
            if(q.empty()) cout<<"Empty!"<<endl;
            else cout<<total<<endl;
        }
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