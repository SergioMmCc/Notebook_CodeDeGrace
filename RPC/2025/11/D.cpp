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

ll mod=10'007;

ll myPow(ll b, ll e){
    ll result = 1;
    while(e > 0){
        if(e % 2 == 1)
            result = ((b % mod) * (result % mod)) % mod;
        b = ((b % mod) * (b % mod)) % mod;
        e /= 2;
    }
    return result;
}

ll calc(string&s,ll start){
    if(start>=s.size())return 1;
    ll ans;
    if(s.size()%2==0){
        ll mn=s[start]-'0';
        ans=myPow(10,(s.size()-start-2)/2);
        if(s[start]>=s[start+1]) mn--;
        ans=(ans*(mn+1))%mod;
        if(s[start]==s[start+1])ans+=calc(s,start+2);
    }else
        ans=myPow(10,(s.size()-1)/2);
    return ans;
}

bool check(string s){
    if(s.size()%2==1)return false;
    for(ll i=0;i<s.size();i+=2)
        if(s[i]!=s[i+1])return false;
    return true;
}

void solver(){
    string a,b;cin>>a>>b;
    cout<<((calc(b,0)+mod)-calc(a,0)+check(a))%mod<<"\n";
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