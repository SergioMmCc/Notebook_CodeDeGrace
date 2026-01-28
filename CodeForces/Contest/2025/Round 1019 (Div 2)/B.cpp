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

void solver(){
    int n; string s; cin>>n>>s;

    char last = '0';
    int ans = n;
    for(int i = 0; i < n; i++){
        if(s[i] != last){
            ans++;
            last = s[i];
        }
    }

    bool cond0 = 0, cond1 = 0, cond2 = 0;
    for(int i = 0; i < n; i++){
        if(!cond0 && s[i] == '1') cond0 = 1;
        else if(cond0 && !cond1 && s[i] == '0') cond1 = 1;
        else if(cond1 && s[i] == '1') cond2 = 1;
    }

    if(cond2){
        cout<<ans-2<<endl;
        return;
    }

    cond0 = 0, cond1 = 0, cond2 = 0;
    for(int i = 0; i < n; i++){
        if(!cond0 && s[i] == '0') cond0 = 1;
        else if(cond0 && !cond1 && s[i] == '1') cond1 = 1;
        else if(cond1 && s[i] == '0') cond2 = 1;
    }

    if(cond2){
        cout<<ans-1<<endl;
        return;
    }

    if(s[0] == '1'){
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                cout<<ans-1<<endl;
                return;
            }
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}