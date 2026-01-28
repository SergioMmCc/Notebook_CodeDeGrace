#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int mod = 998244353;

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    map<pii, int> save;
    save[{0, 1}]++;
    if(!a[1]) save[{1, 0}]++;

    for(int i = 2; i <= n; i++){
        map<pii, int> newT;
        for(map<pii, int>::iterator it = save.begin(); it != save.end(); ++it){
            int liars = it->first.second, last = it->first.first, freq = (it->second) % mod;
            if(a[i] == liars){ // Si acerto los mentirosos, es honesto
                newT[{1, liars}] += freq; 
                newT[{1, liars}] %= mod;
            }
            if(last){ // El actual puede mentir sin importar el contexto
                newT[{0, liars + 1}] += freq;
                newT[{0, liars + 1}] %= mod;
            }
        }

        save = newT;
    }

    int ans = 0;
    for(map<pii, int>::iterator it = save.begin(); it != save.end(); ++it){
        ans += it->second % mod;
        ans %= mod;
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