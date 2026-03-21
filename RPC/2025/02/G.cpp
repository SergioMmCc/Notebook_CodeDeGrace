#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

ld stringToInt(string s){
    ld num = 0;
    int len = s.sz - 1;

    num += (int)s[len] - '0';
    num += 10 * ((int)s[len-1] - '0');
    num += 100 * ((int)s[len-3] - '0');
    if(len > 3){
        num += 1000 * ((int)s[len-4] - '0');
        if(len > 4)
            num += 10000 * ((int)s[len-5] - '0');
    }

    return num;
}

void solver(){
    int n; cin>>n;
    ll total = 0;
    ll count3 = 0, count4 = 0;
    for(int i = 0; i < n; i++){
        string aux; cin>>aux;
        ll num = stringToInt(aux);
        total += num;
        if(num % 5 == 1) total -= 1;
        else if(num % 5 == 2) total -= 2;
        else if(num % 5 == 3) count3++;
        else if(num % 5 == 4) count4++;
    }

    ll mini = min(count3, count4);
    total -= 2 * mini;
    count3 -= mini; count4 -= mini;
    total -= 2 * (count4 / 3);
    total -= count3 / 2;

    ld ans = (ld)total / 100.0;
    cout<<fixed<<setprecision(2)<<ans<<endl;
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