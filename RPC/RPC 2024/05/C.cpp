#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    
    int n, m, c;cin >> n >> m >> c;
    int first, second, result1 = 0, result2 = 0; 
    vector<int> numStu(m, c);
    
    for (int i = 0; i < n; i++) {
        cin >> first >> second;
        if (numStu[first-1] > 0) {
            numStu[first-1]--;
            result1++;
        }
            
        else if (numStu[second-1] > 0) {
            numStu[second-1]--;
            result2++;
        }
    }
    
    cout << result1 << " " << result2 << "\n";
    

    return 0;
}