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
typedef pair<string, string> pss;
typedef pair<pii, pss> piiss;

void solver(){
    int n; cin>>n;
    vector<string> w(n);
    for(int i = 0; i < n; i++) cin>>w[i];

    map<piiss, int> pos;
    for(int i = 0; i < n - 1; i++){
        string s1 = w[i];
        for(int j = i + 1; j < n; j++){
            string s2 = w[j];
            if(s1.sz != s2.sz) continue;

            int len = s1.sz;
            int difl = -1, difr = -1;
            for(int k = 0; k < len; k++){
                if(s1[k] == s2[k]) continue;
                if(difl == -1) difl = k;
                else if(difl + 1 == k) difr = k;
                else{
                    difl = len;
                    difr = len;
                }
            }

            if(difl == difr - 1){
                string add1 = "", add2 = "";
                add1 += s1[difl]; add1 += s1[difr];
                add2 += s2[difl]; add2 += s2[difr];
                if(add1 > add2) swap(add1, add2);

                piiss add = {{len, difl}, {add1, add2}};
                pos[add]++;
            }
        }
    }

    int ans = 0;
    for(const auto& it : pos){
        if(it.se == 1) ans++;
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