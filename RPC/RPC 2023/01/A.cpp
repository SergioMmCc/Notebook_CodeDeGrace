#include <bits/stdc++.h>
using namespace std;
const int limite = 221;
bool es_primo[limite + 1];
vector<int> primos(1, 0);
vector<int> posPrimo(221, 0);
vector<long long>dp(7, 0);

void erastotenes () {
    es_primo[0] = es_primo[1] = false;
    for (int i = 2; i <= limite; ++i) 
        es_primo[i] = true;
    
    for (int p = 2; p * p <= limite; p++) {
        if (es_primo[p]) {
            for (int i = p * p; i <= limite; i += p) 
                es_primo[i] = false;
        }
    }
    for (int i = 2; i <= limite; i++) {
        if (es_primo[i]) {
            primos.push_back(i);
            posPrimo[i] = primos.size()-1;
        }
    }
}

long long pot (int b, int e) {
    long long result = 1;
    long long a = (long long)b;
    for (int i = 0; i < e; i++)
        result *= a;
    return result;
}

int main() {
    erastotenes();
    
    int n, pos, j, k, dif, l; cin >> n;
    long long ans, sus = 0, aux;
    if (n == 2 || n == 3) {
        cout << "1\n";
        return 0;
    }
    pos = posPrimo[n];
    ans = pot(2, pos-2); //Max # combinaciones
    
    // Malas formas de llegar a cada numero
    for (int i = 7; i <= pos; i++) {
        for (j = 1, dif = 15; dif > 14; j++) 
            dif = primos[i] - primos[j];
        j -= 2;
        dp.push_back(pot(2, j-1));
    }
    
    for (int i = 8; i <= pos; i++) {
        for (j = i-1; j >= 7 && primos[i] - primos[j] <= 14; j--) 
            dp[i] += dp[j];
    }

    cout << ans-dp[pos] << "\n";

    return 0;
}