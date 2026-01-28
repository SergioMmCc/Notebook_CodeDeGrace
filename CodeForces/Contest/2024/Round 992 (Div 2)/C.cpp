#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 51;
const ll inf = 1e18;

vector<ll> pot2(maxn);

void preCaclPot2(){
    pot2[0] = 1;
    for(int i = 1; i < maxn; i++) pot2[i] = pot2[i-1] * 2;
}

void solver(){
    int n; ll k; cin>>n>>k;
    if(n < 51 && k > pot2[n - 1]){
        cout<<-1<<endl;
        return;
    }

    vector<int> ans(n);
    int l = 0, r = n - 1;
    int auxN = n;
    for(int i = 1; i <= n; i++){
        ll total;
        auxN--;
        if(auxN < 51) total = pot2[auxN-1];
        else total = inf;
        if(k > total){
            ans[r] = i;
            r--;
            k -= total;
        }
        else{
            ans[l] = i;
            l++;
        }
    }

    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<ans[i]; 
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    preCaclPot2();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}