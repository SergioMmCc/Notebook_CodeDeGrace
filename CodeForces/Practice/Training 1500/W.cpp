#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n, m; cin>>n>>m;
    set<int, greater<int>> numbers;
    for(int i = 0; i < m; i++){
        int save; cin>>save;
        numbers.insert(save);
    }

    vector<int> ans(n+1);
    set<int, greater<int>> used[n+1];
    for(int i = 1; i <= n; i++){
        if(used[i].sz == m){
            cout<<-1<<endl;
            return;
        }

        set<int>::iterator it1 = numbers.begin();
        while(used[i].find(*it1) != used[i].end()) ++it1;
        ans[i] = *it1;

        for(int j = i + i; j <= n; j += i) used[j].insert(*it1);
    }

    for(int i = 1; i <= n; i++){
        if(i > 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}