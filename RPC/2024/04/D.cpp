#include <bits/stdc++.h>
using namespace std;

bool vocal (char compare) {
    return (compare == 'a' || compare == 'e' || compare == 'i' ||
            compare == 'o' || compare == 'u');
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    string w1, w2, aux, result;
    char v1 = '*', v2 = '*';
    int l1, l2, lr, la;
    
    cin >> w1 >> w2;
    l1 = w1.length();
    l2 = w2.length();
    
    result += w1[0];
    
    for (int i = 1; i < l1; i++) {
        if (vocal(w1[i])) {
            v1 = w1[i];
            break;
        }
        result += w1[i];
    }
    lr = result.length();
    
    aux += w2[l2-1];
    for (int i = l2-2; i >= 0; i--) {
        if(vocal(w2[i])) {
            v2 = w2[i];
            break;
        }
        aux += w2[i];
    }
    la = aux.length();
    
    if (v2 != '*') 
        result += v2;
    else if (v1 != '*')
        result += v1;
    else 
        result += 'o';
    
    lr++;
    
    for (int i = la-1; i >= 0; i--) 
        result += aux[i];
        
    cout << result << "\n";

    return 0;
}