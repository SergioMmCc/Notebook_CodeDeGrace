#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<pib, pib> piibb;

void solver(){
    int n; cin>>n;
    vector<piibb> gates(n);
    vector<pii> genera(n+1);

    for(int i = 0; i < n; i++){
        char op1, op2; int num1, num2; cin>>op1>>num1>>op2>>num2;
        gates[i] = {{num1, op1 == 'x' ? 1 : 0}, {num2, op2 == 'x' ? 1 : 0}};
    }

    // Calcular vector genera
    genera[n-1] = {gates[n-1].first.second ? gates[n-1].first.first : 1, gates[n-1].second.second ? gates[n-1].second.first : 1};
    genera[n] = {1, 1};
    for(int i = n-2; i >= 0; i--){
        genera[i].first = genera[i+1].first + (gates[i].first.second ? (gates[i].first.first - 1) * max(genera[i+1].first, genera[i+1].second) : 0);
        genera[i].second = genera[i+1].second + (gates[i].second.second ? (gates[i].second.first - 1) * max(genera[i+1].first, genera[i+1].second) : 0);
    }

    // Calcular la respuesta
    int ans = genera[0].first + genera[0].second;
    for(int i = 0; i < n; i++){
        if(!gates[i].first.second) ans += gates[i].first.first * max(genera[i+1].first, genera[i+1].second);
        if(!gates[i].second.second) ans += gates[i].second.first * max(genera[i+1].first, genera[i+1].second);
    }

    cout<<ans<<endl;
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