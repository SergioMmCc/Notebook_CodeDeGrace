#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n; cin>>n;
    int ans = 1;
    vector<int> a; 
    if(n % 2 == 1){
        ans = n;
        for(int i = 2; i <= n - 2; i++){
            if(i == 3)continue;
            a.push_back(i);
        }
        a.push_back(1); a.push_back(3); a.push_back(n - 1); a.push_back(n);
    }
    else{
        int lg = 31 - __builtin_clz(n) + 1;
        ans <<= lg; ans--;
        int comp = ans - n;
        if(comp == 3 || comp == 1){
            for(int i = 4; i < n; i++)
                a.push_back(i);
            a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(n);
        }
        else{
            for(int i = 2; i < n; i++){
            if(i == 3 || i == comp || i == comp - 1)continue;
                a.push_back(i);
            }
            a.push_back(1); a.push_back(3); a.push_back(comp - 1); a.push_back(comp); a.push_back(n);
        }
    }

    cout<<ans<<endl;
    for(int i = 0; i < n - 1; i++)
        cout<<a[i]<<' ';
    cout<<a[n-1]<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}