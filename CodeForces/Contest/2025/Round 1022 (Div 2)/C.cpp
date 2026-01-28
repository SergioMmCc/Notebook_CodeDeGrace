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
typedef pair<pii, int> piii;

void solver(){
    int n; cin>>n;
    priority_queue<piii> pq;
    vector<int> a(n+1);
    vector<bool> taken(n+1);
    for(int i = 1; i <= n; i++){
        int save; cin>>save;
        a[i] = save;
        pq.push({{save, 0}, i});
    }

    int ans = 0;
    while(!pq.empty()){
        int adj = pq.top().fi.se, ind = pq.top().se; pq.pop();
        if(taken[ind]) continue;

        taken[ind] = 1;
        if(!adj) ans++;
        if(ind > 1 && !taken[ind - 1]) pq.push({{a[ind - 1], 1}, ind - 1});
        if(ind < n && !taken[ind + 1]) pq.push({{a[ind + 1], 1}, ind + 1});
    }

    cout<<ans<<endl;
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