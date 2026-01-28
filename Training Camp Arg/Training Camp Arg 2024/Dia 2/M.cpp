#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n, m;cin>>n>>m;
    int limit = (m+1)/2;
    vector<int> used(n+1);
    vector<int> ans;
    vector<vector<int>> choose(m+1);
    
    int save;
    bool possible = true;
    for(int i = 1; i <= m; i++) {
        int k;cin>>k;
        if(k == 1) {
            cin>>save;
            used[save]++;
            choose[i].push_back(save);
            if(used[save] > limit) 
                possible = false;
        }
        else {
            for(int j = 0; j < k; j++) {
                cin>>save;
                choose[i].push_back(save);
            }
        }
    }
    if(!possible) {
        cout<<"NO"<<endl;
        return;
    }
    
    for(int i = 1; i <= m; i++) {
        if(choose[i].size() == 1) {
            ans.push_back(choose[i][0]);
            continue;
        }
        int j = 0;
        while(used[choose[i][j]] == limit)
            j++;
        ans.push_back(choose[i][j]);
        used[choose[i][j]]++;
    }
    
    cout<<"YES"<<endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i>0)cout<<" ";
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