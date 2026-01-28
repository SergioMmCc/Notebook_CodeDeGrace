#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, k; 

    cin >> n >> k; 

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if( k > 0) {
                cout << 1; 
                k--;
                continue;
            }
            cout << 0;
        }
        cout << endl; 
    }
}