#include<bits/stdc++.h>
using namespace std;

long long logB (long long n, long long m) {
    return log(n)/log(m);
}

vector<int> pot2;
void calcularPot2 () {
    pot2.push_back(1);
    int i = 1;
    while(i < 100000) {
        i *= 2;
        pot2.push_back(i);
    }
}

void solver() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;cin>>n;
    long long save, originalSave, lastNumber, lastI = 0, search, pos;
    long long ans = 0, extra;
    
    vector<int> cases;
    vector<int>::iterator it;
    
    for(int index = 0; index < n; index++) {
        cin>>save;
        cases.push_back(save);
    }
    
    lastNumber = cases[0];
    for(int index = 1; index < n; index++) {
        save = originalSave = cases[index];
        
        if(save == 1 && lastNumber > 1) {
            cout << "-1\n";
            return;
        }
        if(lastI == 0 && save >= lastNumber) {
            lastNumber = save;
            continue;
        }
            
        extra = 0;
        while(save < lastNumber) {
            extra++;
            save *= save;
        }
        ans += extra;
        search = logB(save, lastNumber);
        
        it = upper_bound(pot2.begin(), pot2.end(), search);
        pos = distance(pot2.begin(), it) - 1;
        
        if(lastI >= pos) {
            ans += lastI - pos;
            lastI = extra + lastI - pos;
        }
        else 
            lastI = extra;
        lastNumber = originalSave;
    }
    
    cout << ans << "\n";
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcularPot2();
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
        solver();

    return 0;
}