#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(int n){
    queue<int> q; stack<int> st; priority_queue<int> pq;
    int qb = 1, stb = 2, pqb = 4;
    while(n--){
        int op, u; cin>>op>>u;
        if(op == 1){
            q.push(u);
            st.push(u);
            pq.push(u);
        }
        else{
            if(!q.sz){
                qb = 0;
                stb = 0;
                pqb = 0;
            }
            else{
                int v;
                v = q.front(); q.pop();
                if(v != u) qb = 0;
                v = st.top(); st.pop();
                if(v != u) stb = 0;
                v = pq.top(); pq.pop();
                if(v != u) pqb = 0;
            }
        }
    }
    
    int sum = qb + stb + pqb;
    if(!sum) cout<<"impossible"<<endl;
    else if(sum == 1) cout<<"queue"<<endl;
    else if(sum == 2) cout<<"stack"<<endl;
    else if(sum == 4) cout<<"priority queue"<<endl;
    else cout<<"not sure"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    // cin>>t;
    while(cin>>n){
        solver(n);
    }

    return 0;
}