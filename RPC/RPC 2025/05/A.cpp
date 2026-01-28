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
    ll n, x, a, b, cost = 0;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while(n--){
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1){
        a = pq.top();
        b = 0;
        pq.pop();

        if(!pq.empty()){
            b = pq.top();
            pq.pop();
        }

        x = a + b;
        cost += x;
        pq.push(x);
    }

    cout << cost << endl;
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}