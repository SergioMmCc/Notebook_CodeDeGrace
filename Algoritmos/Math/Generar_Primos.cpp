#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
const int INF=1E9, MOD=1E9+7, top=1E5;

// Aqui se almacenaran los primos
vector<int> primes;

// Array auxiliar, usando el algoritmo Sieve of Eratosthenes
// Genera primos menores de top, en aproximado O(nlogn)
int vis[top+3];


int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    for(int i=2; i<=top; i++){
        if(!vis[i]){
            primes.push_back(i);
            for(int j=i*2; j<=top; j+=i) vis[j]=1;
        }
    }
    return 0;
}
