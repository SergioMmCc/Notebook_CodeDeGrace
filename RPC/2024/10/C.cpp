#include<bits/stdc++.h>

using namespace std; 

int main() {

    int n, m; 

    vector<pair<bool, bool>> vals(100005); 
    cin >> n >> m; 
    int a, b; 
    for(int i=0; i<m; i++) {
        cin >> a >> b; 

        if(b == 1) {
            vals[a].first = true;
        }

        if(b == 2) {
            vals[a].second = true;
        }
    }

    for(int i=1; i<=n; i++) {
        if(vals[i].first&& vals[i].second) {
            cout << i << endl; 
        }
    }
}