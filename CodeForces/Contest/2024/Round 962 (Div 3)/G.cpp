#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solver() {
    int n, m, a, b;
    long long r;
    cin>>n>>m;
    vector<long long> D(n);
    while(m--) {
        cin>>a>>b;
        r = rng();
        D[a-1] ^= r;
        D[b-1] ^= r;
    }
    
    unordered_map<long long, int> conjuntos;
    int fixAns = 0;
    long long save = 0;
    for(long long diag : D)
        fixAns = max(fixAns, conjuntos[save^=diag]++);
        
    cout<<n-fixAns-1<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}