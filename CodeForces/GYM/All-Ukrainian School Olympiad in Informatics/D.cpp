#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = unsigned long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

vector<ll> pot2(64);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 64; i++) pot2[i] = pot2[i-1] * 2;
}

void solver(){
    ll a, b; cin>>a>>b;
    if(a < b){
        cout<<-1<<endl;
        return;
    }

    ll dif = a - b;
    if(dif % 2){
        cout<<-1<<endl;
        return;
    }

    ll y = b, x = 0;
    for(int i = 0; i < 64; i++){
        if(dif % 2) x += pot2[i-1];
        dif /= 2;
    }

    y += x;
    cout<<x<<' '<<y<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPot2();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}