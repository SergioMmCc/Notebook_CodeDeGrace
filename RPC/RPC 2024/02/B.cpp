#include <bits/stdc++.h>
using namespace std;

long long potencia (int exponente) {
    if (exponente == 0)return 1;
    long long result = 2;
    for (int index = 1; index < exponente; index++)
        result *= 2;
    return result;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    long double n, result;
    cin >> n;
    result = log(n)/log(2);
    result = (int)result;
    if (potencia(result) < n)
        result++;
    result++;

    cout << result << "\n";

    return 0;
}