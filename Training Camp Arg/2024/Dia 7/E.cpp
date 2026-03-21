#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios_base::sync_with_stdio(0);cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        string caso; cin >> caso;
        string result = "";
        result += caso[0];
        int i = 1;
        while(i < n) {
            if(caso[i] > caso[i-1])
                break;
            else if(caso[i] < caso[i-1])
                result += caso[i];
            else {
                if(i == 1)
                    break;
                int reps = 0;
                while(i < n  && caso[i] == caso[i-1]) {
                    i++;
                    reps++;
                }
                while(reps--)
                    result += caso[i-1];
                if(i >= n || caso[i] > caso[i-1])
                    break;
                else
                    result += caso[i];
            }
            i++;
        }
        
        cout << result;
        for(int i = result.size()-1; i >= 0; i--)
            cout << result[i];
        cout << "\n";
    }

    return 0;
}