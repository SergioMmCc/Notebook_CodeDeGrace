#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<bool, bool> pbb;
typedef pair<ll, ll> pll;
typedef pair<pll, pbb> pllbb;
typedef pair<ll, vector<int>> plv;

map<pllbb, plv> dp;
vector<int> n1, n2;
int len;

vector<int> intToVec(ll x){
    len = 0;
    vector<int> num;
    for(int i = 0; i < 20; i++){

        num.pb(x % 10);
        len++;
        x /= 10;
    }

    reverse(num.begin(), num.end());

    return num;
}

plv calc(int idx, bool under, bool over, ll num, vector<int> how){
    if(how.sz == 1 && how[0] == 0){
        num = 1;
        how.pop_back();
    }


    if(idx == len) return {num, how};

    if(dp.find({{idx, num}, {under, over}}) != dp.end()) return dp[{{idx, num}, {under, over}}];

    plv ans = {-1, {}};
    if(under && over){
        vector<int> aux = how; aux.pb(9);
        ans = max(ans, calc(idx + 1, under, over, num * 9, aux));
    }

    else if(!under && over){
        vector<int> aux = how; aux.pb(n1[idx]);
        ans = max(ans, calc(idx + 1, under, over, num * n1[idx], aux));
        
        if(n1[idx]){
            aux.pop_back();
            aux.pb(n1[idx] - 1);
            ans =  max(ans, calc(idx + 1, 1, over, num * (n1[idx] - 1), aux));
        }
    }

    else if(under && !over){
        vector<int> aux = how; aux.pb(9);
        bool nOver = n2[idx] < 9;
        ans = max(ans, calc(idx + 1, under, nOver, num * 9, aux));
    }

    else{ // !under && !over
        vector<int> aux = how; aux.pb(n1[idx]);
        bool nOver = n1[idx] > n2[idx];
        ans = max(ans, calc(idx + 1, under, nOver, num * n1[idx], aux));

        if(n1[idx] && n1[idx] > n2[idx]){
            aux.pop_back();
            aux.pb(n1[idx] - 1);
            nOver = n1[idx] - 1 > n2[idx];
            ans = max(ans, calc(idx + 1, 1, nOver, num * (n1[idx] - 1), aux));
        }
    }

    
    // cout<<"idx -> "<<idx<<" under -> "<<under<<" over -> "<<over<<" num -> "<<num<<" len -> "<<how.sz<<endl;
    // cout<<"num -> "<<ans.fi<<endl;
    dp[{{idx, num}, {under, over}}] = ans;
    return ans;
}

void solver(){
    ll l, r; cin>>l>>r;
    n1 = intToVec(r);
    n2 = intToVec(l);
    // for(int i = 0; i < n1.sz; i++) cout<<n1[i]; cout<<endl;
    // for(int i = 0; i < n2.sz; i++) cout<<n2 [i]; cout<<endl;
    

    plv ans = calc(0, 0, 0, 1, {});

    // Limpiar leading zeroes
    vector<int> aux;
    for(int i = 0; i < ans.se.sz; i++){
        if(!ans.se[i] && aux.empty()) continue;
        aux.pb(ans.se[i]);
    }

    // cout<<"Answer -> ";
    for(int i = 0; i < aux.sz; i++) cout<<aux[i];
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}