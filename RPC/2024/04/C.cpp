#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    
    int A[45], result = 1, contador = 1, n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> A[i];
        
    for (int i = 1; i < n; i++) {
        if (A[i] > A[i-1])
            contador++;
        else {
            if (contador > result) 
                result = contador;
            contador = 1;
        }
    }
    if (contador > result) 
        result = contador;
    
    cout << result << "\n";
    
    return 0;
}