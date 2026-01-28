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
#define int long long

vector<int> pot2(62);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 62; i++) pot2[i] = pot2[i-1] * 2;
}

void solver(){
    int n, k; cin>>n>>k;
    int ans = 0;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        for(int i = 0; i < 62; i++){
            if(num % 2) ans++;
            else pq.push(-pot2[i]);

            num /= 2;
        }
    }

    while(!pq.empty() && pq.top() >= -k){
        ans++;
        k += pq.top();
        pq.pop();
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPot2();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}