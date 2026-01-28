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

vector<ll> pot2(62);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 62; i++) pot2[i] = pot2[i-1] * 2;
}

void solver(){
    ll n, l, r, k; cin>>n>>l>>r>>k;
    if(n % 2){
        cout<<l<<endl;
        return;
    }
    if(n == 2){
        cout<<-1<<endl;
        return;
    }
    auto it = upper_bound(pot2.begin(),  pot2.end(), l);
    ll num = *it;
    if(num > r) cout<<-1<<endl;
    else{
        if(k <= n-2) cout<<l<<endl;
        else cout<<num<<endl;
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