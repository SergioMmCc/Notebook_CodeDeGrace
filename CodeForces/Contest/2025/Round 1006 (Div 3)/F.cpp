#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

vector<int> pot2(32);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 32; i++) pot2[i] = 2*pot2[i-1];
}

string calc(int n){
    string s = "";
    vector<int>::iterator it = upper_bound(pot2.begin(), pot2.end(), n);
    --it;
    if(*it == n){
        for(int i = 0; i < n; i++) s += "1";
    }
    else{
        int aux = n - *it;
        string add = calc(aux);
        s += add;
        for(int i = 0; i < n - 2*add.sz; i++) s += "0";
        s += add;
    }

    return s;
}

void solver(){
    int n, k; cin>>n>>k;
    string ans = calc(n);
    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<(ans[i] == '1' ? k : 0);
    }
    cout<<endl;
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