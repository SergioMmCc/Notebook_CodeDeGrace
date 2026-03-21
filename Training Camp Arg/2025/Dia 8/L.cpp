#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define int long long
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int inf = 1e9 + 1;

void solver(){
    int n, m; cin>>n>>m;
    vector<int> car(n+1);
    for(int i = 1; i <= n; i++) cin>>car[i];
    vector<queue<int>> next(n+1);
    priority_queue<pii, vector<pii>, greater<pii>> est;
    for(int i = 0; i < m; i++){
        int x, ind; cin>>x>>ind;
        est.push({x, ind});
        next[ind].push(x);
    }

    priority_queue<piii, vector<piii>, greater<piii>> bat;
    for(int i = 1; i <= n; i++){
        next[i].push(inf);
        bat.push({{next[i].front(), car[i]}, i});
        next[i].pop();
    }

    int pos = 0;
    while(!bat.empty()){
        int sum = bat.top().fi.se, index = bat.top().se, sig = bat.top().fi.fi;
        // cout<<"sum -> "<<sum<<endl;
        bat.pop();
        if(sum == 0) continue;

        if(est.empty()){
            pos += sum;
            continue;
        }
        int whe = est.top().fi, upd = est.top().se;
        // cout<<"here"<<endl;
        // Si llego a la proxima estacion antes de que se descargue, y me cargo ahi
        if(pos + sum >= whe && index == upd){
            // cout<<"Igual -> "<<"index -> "<<index<<" sum -> "<<sum<<" upd -> "<<upd<<endl;
            if(!next[index].empty()){
                bat.push({{next[index].front(), car[index]}, index});
                next[index].pop();
            }
            est.pop();
            pos = whe;
        }
        if(pos + sum >= whe && index != upd){
            // cout<<"Diferente -> "<<"index -> "<<index<<" sum -> "<<sum<<" upd -> "<<upd<<endl;
            bat.push({{sig, sum - whe + pos}, index}); // Con el que iba

            if(!next[upd].empty()){
                bat.push({{next[upd].front(), car[upd]}, upd});
                next[upd].pop();
            }
            // else{
            //     cout<<"index -> "<<index<<" empty"<<endl;
            // }
            est.pop();

            pos = whe;
        }

        if(pos + sum < whe){
            pos += sum;
            // cout<<"menor: "<<"index -> "<<index<<" sum -> "<<sum<<" upd -> "<<upd<<" pos -> "<<pos<<endl;
        }
    }

    cout<<pos<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}