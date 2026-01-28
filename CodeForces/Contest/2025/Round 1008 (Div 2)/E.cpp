#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
#define int long long

vector<int> pot2(31);
void calc(){
    pot2[0] = 1;
    for(int i = 1; i < 31; i++) pot2[i] = pot2[i-1] * 2;
}

void solver(){
    int q1 = 0, q2 = 0;
    for(int i = 0; i < 30; i++){
        if(i % 2) q2 += pot2[i];
        else q1 += pot2[i];
    }

    int ans1, ans2;
    cout<<q1<<endl;
    cin>>ans1; ans1 -= 2*q1; ans1 /= 2;
    cout<<q2<<endl;
    cin>>ans2; ans2 -= 2*q2;

    // cout<<"ans1 -> "<<ans1<<" ans2 -> "<<ans2<<endl;
    vector<int> count(30);
    
    for(int i = 1; i < 30; i += 2){
        if(ans1 % 2) count[i] = 1;
        ans1 /= 2;
        if(ans1 % 2) count[i] = 2;
        ans1 /= 2;
    }

    for(int i = 0; i < 30; i += 2){
        if(ans2 % 2) count[i] = 1;
        ans2 /= 2;
        if(ans2 % 2) count[i] = 2;
        ans2 /= 2;
    }

    cout<<'!'<<endl;
    int m; cin>>m;
    int ans = 0;
    for(int i = 0; i < 30; i++){
        if(m % 2) ans += pot2[i+1];
        else{
            if(count[i] == 1) ans += pot2[i];
            else if(count[i] == 2) ans += pot2[i+1];
        }

        m /= 2;
    }

    cout<<ans<<endl;
}

signed main(){
    // ios_base::sync_with_stdio(0);cin.tie(NULL);
    calc();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}