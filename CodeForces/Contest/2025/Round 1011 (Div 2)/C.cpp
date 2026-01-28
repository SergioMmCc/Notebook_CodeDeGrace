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

vector<ll> pot2(60);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 60; i++) pot2[i] = 2 * pot2[i-1];
}

void solver(){
    ll x, y; cin>>x>>y;
    if(x == y){
        cout<<-1<<endl;
        return;
    }
    ll z = x + y;
    if(z % 2){
        vector<ll>::iterator it = upper_bound(pot2.begin(), pot2.end(), z);
        ll next = *it; next--;
        cout<<next - z / 2<<endl;
    }

    else{
        vector<ll>::iterator it = lower_bound(pot2.begin(), pot2.end(), z);
        ll next = *it;
        cout<<next - max(x, y)<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPot2();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}