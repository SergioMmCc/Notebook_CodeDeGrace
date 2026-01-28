#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;

vector<int> pot2(34);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 34; i++) pot2[i] = 2 * pot2[i-1];
}

void solver(){
    int n, x; cin>>n>>x;
    vector<int> bits(34);
    int aux = x;
    int lastBit = 33;
    for(int i = 0; i < 34; i++){
        if(aux % 2) bits[i] = 1;
        else lastBit = min(lastBit, i);
        aux /= 2;
    }

    int maxMex = pot2[lastBit];
    int lastRest = 0;
    vector<int> ans;
    for(int i = 0; i < n-1 && i < maxMex; i++){
        ans.pb(i);
        if(i == pot2[lastRest]){
            x -= pot2[lastRest];
            lastRest++;
        }
    }

    int elements = ans.sz;
    if(x > 0){
        ans.pb(x);
        elements++;
    }
    else if(ans.empty()){
        ans.pb(0);
        elements++;
    }
    else if(ans.back() < maxMex - 1){
        ans.pb(ans.back() + 1);
        elements++;
    }
    
    while(elements < n){
        ans.pb(0);
        elements++;
    }

    for(int num : ans) cout<<num<<' ';
    cout<<endl;
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