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
    string s1, s2; cin>>s1>>s2;
    int n = s1.sz;
    int ans = 0;
    int last = 0;
    if(s1[0] == '0') last++;
    if(s2[0] == '0') last++;
    for(int i = 1; i < n; i++){
        int next = 0;
        if(s1[i] == '0') next++;
        if(s2[i] == '0') next++;

        if(next == 2 && last == 2){
            ans++;
            next = 1;
        }
        else if((next == 1 && last == 2) || (next == 2 && last == 1)){
            ans++;
            next = 0;
        }
        last = next;
    }

    cout<<ans<<endl;
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