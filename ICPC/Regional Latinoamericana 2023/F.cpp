
#include <bits/stdc++.h>
#define TRUE 1
#define FALSE 0
using namespace std;
 
const int middle = 1e6;
 
int palindromo (long long n, long long base) {
    vector <long long> v;
    long long saveNumber = n;
    
    while (saveNumber != 0) {
        v.push_back (saveNumber % base);
        saveNumber /= base;
    }
    
    while (v.size() > 1) {
        if (v.front() != v.back()) return FALSE;
        v.pop_back();
        v.erase(v.begin());
    }
    return TRUE;
}
 
int main ()
{
    long long n, limit, index;
    int result;
    set <long long> lista; 
    cin >> n;
    limit = sqrt(n);
    
    if (n < middle) index = n;
    else index = 1;
    
    for (; index <= limit; index++) {
        if (n%index == 0 && n/index > 2)
            lista.insert (n/index - 1);
    }
    
    for (; index > 1; index--) {
        result = palindromo (n, index);
        if (result == TRUE) lista.insert (index);
    }
    if (lista.empty ()) cout<<"*";
    else {
        auto index = lista.begin(), n = lista.end(); 
        n--;
        for (; index != n; index++) cout << *index << " ";
        cout << *index;
    }
    
    cout<<"\n";
 
    return 0;
}
