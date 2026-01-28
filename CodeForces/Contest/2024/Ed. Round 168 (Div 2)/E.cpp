#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, q;cin>>n>>q;
    vector<int> levels(n+1);
    for(int i = 1; i <= n; i++) 
        cin>>levels[i];
    
    vector<int> bit(n+1), ans(n+1);

    for(int i = 1; i <= n; i++) {
        int flee = 0, monstersFaced = 0;
        for(int j = log2(n)+1; j >= 0; j--) {
            int testFlee = flee | (1 << j);
            if(testFlee > n)
                continue;
            
            int testMonstersFaced = monstersFaced + bit[testFlee];
            int playerLevel = testMonstersFaced / testFlee + 1;
            if(playerLevel > levels[i]) {
                flee = testFlee;
                monstersFaced = testMonstersFaced;
            }
        }

        ans[i] = flee+1;
        for(int j = ans[i]; j <= n; j += j & -j)
            bit[j]++;
    }

    while(q--) {
        int i, x;cin>>i>>x;
        if(x >= ans[i])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}