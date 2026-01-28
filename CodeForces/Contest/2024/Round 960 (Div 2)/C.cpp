#include <bits/stdc++.h>
using namespace std;

void solver() {
    int n;
    long long sum = 0, parcialSum = 0;
    cin >> n;
    int a[n+1], freq[n+1];
    int maxRep = 0, anteriorMaxRep = 0, startingPoint = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        freq[i] = 0; 
    }
    for(int i = 1; i <= n; i++) {
        freq[a[i]]++;
        if(freq[a[i]] > 1 && a[i] > maxRep) {
            if(startingPoint == i-1) {
                parcialSum += anteriorMaxRep;
            }
            
            maxRep = a[i];
            sum += maxRep;
            startingPoint = i;
        }
            
        else {
            if(startingPoint == i - 1) {
                parcialSum += 2*maxRep;
                anteriorMaxRep = maxRep;
            }
                
            else
                parcialSum += maxRep;
        }
        
        sum += parcialSum;
    }
    cout << sum << "\n";
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solver();
    }
    return 0;
}