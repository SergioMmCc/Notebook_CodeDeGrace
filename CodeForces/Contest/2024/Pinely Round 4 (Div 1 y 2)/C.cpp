#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n;cin>>n;
    bool cero = false;
    vector<int> x(n);
    int maxn = 0, count = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        cin>>x[i];
        maxn = max(maxn, x[i]);
        if (x[i] == 0)
            cero = true;
    }
    if(cero && maxn % 2 == 1) {
        cout<<"-1"<<endl;
        return;
    }
    if(maxn == 0) {
        cout<<"0"<<endl<<endl;
        return;
    }
    
    while(maxn>0) {
        count++;
        ans.push_back(maxn/2);
        cero = false;
        int newMax = 0;
        for(int i = 0; i < n; i++) {
            x[i] = abs(x[i]-maxn/2);
            newMax = max(newMax, x[i]);
            if (x[i] == 0)
                cero = true;
        }
        maxn = newMax;
        if(cero && maxn % 2 == 1) {
            cout<<"-1"<<endl;
            return;
        }
        if(maxn == 1) {
            count++;
            ans.push_back(1);
            break;
        }
    }
    cout<<count<<endl;
    for(int i = 0; i < count; i++) {
        if(i > 0)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
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