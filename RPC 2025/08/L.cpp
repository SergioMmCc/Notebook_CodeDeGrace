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
    int h1, d1, t1, h2, d2, t2; cin>>h1>>d1>>t1>>h2>>d2>>t2;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1}); pq.push({0, 2});
    int die1 = 1e6 + 1, die2 = 1e6 + 1;
    while(!pq.empty()){
        int t = pq.top().fi, p = pq.top().se; pq.pop();

        if(p == 1){
            h2 -= d1;
            if(h2 <= 0) die2 = t;
            else pq.push({t + t1, 1});
        }
        else{
            h1 -= d2;
            if(h1 <= 0) die1 = t;
            else pq.push({t + t2, 2});
        }
    }

    if(die1 < die2) cout<<"player two"<<endl;
    else if(die1 > die2) cout<<"player one"<<endl;
    else cout<<"draw"<<endl;
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