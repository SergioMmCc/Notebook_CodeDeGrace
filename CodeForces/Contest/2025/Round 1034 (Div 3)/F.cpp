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
const int limite = 1e5 + 1; // Hasta este numero hay un poco mas de 6e5 primos

vector<bool> esPrimo(limite, 1);

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }
}

void solver(){
    int n; cin>>n;
    vector<bool> assi(n+1);
    vector<int> ans(n+1); ans[1] = 1;
    for(int i = n; i > 1; i--){
        if(!esPrimo[i]) continue;

        int next = (n / i) * i, last = i;
        if(next == i){
            ans[i] = i;
            continue;
        }

        // cout<<"primo -> "<<i<<endl;
        while(next){
            // cout<<"last -> "<<last<<" next -> "<<next<<endl;
            if(!assi[next]){
                ans[last] = next;
                assi[next] = 1;
                last = next;
            }
            next -= i;
        }
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    sieve();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}