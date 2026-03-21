#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    
    int O, A, K, i=0, j=0, possible = 0;
    cin >> O >> A >> K;
    
    for (i = A; i+j <= O && possible == 0; i+=A) {
        for (j = K; i+j <= O && possible == 0; j+=K) {
            if (i+j == O) 
                possible = 1;
        }
        j = 0;
    }
    
    if (possible == 1)cout << "1\n";
    else cout << "0\n";
    
    return 0;
}