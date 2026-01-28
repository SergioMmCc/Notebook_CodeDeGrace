#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
#define int long long

unordered_map<int, int> T;

vector<int> pot10(12);
void calcPot10(){
    pot10[0] = 1;
    for(int i = 1; i < 12; i++) pot10[i] = 10 * pot10[i-1];
}

bool isPrime(int n){
    if(n == 1 || n == 0) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int calc(int n){
    if(T.find(n) != T.end()) return T[n];

    if(!isPrime(n)){
        T[n] = 0;
        return 0;
    }

    T[n] = 0;
    int lastNum = 0;
    for(int cifras = 1; pot10[cifras] < n * 10; cifras++){
        int aux = n;
        int num;
        aux /= pot10[cifras - 1];
        num = aux % 10;
        aux /= 10;
        aux *= pot10[cifras-1];
        aux += lastNum;
        T[n] = max(T[n], calc(aux));
        lastNum += num * pot10[cifras - 1];
    }

    T[n]++;
    return T[n];
}

void solver(){
    int n; cin>>n;
    if(n == 1e9){
        cout<<0<<endl;
        return;
    }
    cout<<calc(n)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPot10();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}