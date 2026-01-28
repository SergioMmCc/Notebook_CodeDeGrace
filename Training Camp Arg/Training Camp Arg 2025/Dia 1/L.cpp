#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

//Esta función genera numeros aleatorios hasta de 64 bits
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solver(){
    int n; cin>>n;
    vector<int> p(3); p[0] = 1; p[1] = 2; p[2] = 3;
    bool cond = 0;
    while(!cond){
        cout<<"? "<<p[0]<<' '<<p[1]<<' '<<p[2]<<endl;
        int ans; cin>>ans;
        if(!ans) cond = 1;
        else p[rng() % 3] = ans;
    }

    cout<<"! "<<p[0]<<' '<<p[1]<<' '<<p[2]<<endl;
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