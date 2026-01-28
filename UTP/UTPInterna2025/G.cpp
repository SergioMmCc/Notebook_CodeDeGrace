#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--){
        int op; cin>>op;
        if(op == 1){
            int v; cin>>v;
            pq.push(v);
        }
        else if(op == 2){
            if(pq.empty()) continue;
            pq.pop();
        }
        else{
            if(pq.empty()) cout<<"Empty!"<<endl;
            else{
                int u = pq.top();
                cout<<u<<endl;
            }
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