#include <bits/stdc++.h>
#define limite 1000000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    //Sieve of  Eratosthenes
    vector<int> primos(1,0);
    map<int, vector<int>> bigPrimes;
    vector<bool> es_primo(limite + 1, true);
    for (int p = 2; p < 1000; p++)
        if (es_primo[p]){
            primos.push_back(p);
            for (int i = p * p; i <= limite; i += p)
                es_primo[i] = false;
        }
    int nPrimos = primos.size() - 1;
    //--------------------------------------------------
    int save, test, days; cin >> days;
    vector<vector<int>> freq(nPrimos + 1, vector<int>(1,0));
    for (int i = 1; i <= days; i++) {
        cin >> save;
        test = 1;
        while (save != 1 && test <= nPrimos) {
            if (save % primos[test] == 0) {
                freq[test].push_back(i);
                save /= primos[test];
            } else
                test++;
        }
        if (save != 1) {
            if (bigPrimes.find(save) != bigPrimes.end())
                bigPrimes[save].push_back(i);
            else
                bigPrimes[save] = vector<int> {i};
        }
    }
    //--------------------------------------------------
    bool possible;
    int q, l, r, n, search;
    cin >> q;
    while (q--) {
        possible = true;
        test = 1;
        cin >> l >> r >> n;
        vector<int> caso(nPrimos + 1, 0);
        while (n != 1 && test <= nPrimos) {
            if (n % primos[test] == 0) {
                caso[test]++;
                n /= primos[test];
            } else {
                if (caso[test] > 0) {
                    search = distance (lower_bound(freq[test].begin(), freq[test].end(), l), upper_bound(freq[test].begin(), freq[test].end(), r));
                    if (search < caso[test]) {
                        possible = false;
                        break;
                    }
                }
                test++;
            }
        }
        if (possible && test <= nPrimos) {
            search = distance (lower_bound(freq[test].begin(), freq[test].end(), l), upper_bound(freq[test].begin(), freq[test].end(), r));
            if (search < caso[test])
                possible = false;
        }
        if(possible && n != 1) {
            if (bigPrimes.find(n) == bigPrimes.end())
                possible = false;
            else {
                vector<int> bigPrimePos = bigPrimes.find(n)->second;
                search = distance (lower_bound(bigPrimePos.begin(), bigPrimePos.end(), l), upper_bound(bigPrimePos.begin(), bigPrimePos.end(), r));
                if (search == 0)
                    possible = false;
            }
        }
        cout << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}