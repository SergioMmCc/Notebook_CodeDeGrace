#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int, int> pii;

#define int long long
const int maxn = 4e5 + 2;

vector<int> bits(int n){
    vector<int> ans(32);
    int i = 0;
    while(n > 0){
        if(n % 2) ans[i] = 1;
        i++;
        n /= 2;
    }
   
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    
    int n, k; cin>>n>>k;
    vector<vector<int>> prefixSum(32, vector<int>(n+1));
    vector<int> bitk = bits(k);

    set<int> walls;
    for(int i = 1; i <= n; i++){
        int num; cin>>num;
        vector<int> aux = bits(num);
        for(int j = 0; j < 32; j++){
            prefixSum[j][i] = prefixSum[j][i-1] + aux[j];
            if(aux[j] && !bitk[j]) walls.insert(i);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int r = i;
        for(int bit = 0; bit < 32; bit++){
            if(!bitk[bit]) continue;
            vector<int>::iterator it = lower_bound(prefixSum[bit].begin(), prefixSum[bit].end(), prefixSum[bit][i-1] + 1);
            if(it == prefixSum[bit].end()){
                cout<<ans<<endl;
                return 0;
            }

            int index = distance(prefixSum[bit].begin(), it);
            r = max(r, index);
        }

        set<int>::iterator nextWall = walls.lower_bound(i);
        if(nextWall == walls.end()) ans += n - r + 1;
        else if(*nextWall > r) ans += *nextWall - r;
    }

    cout<<ans<<endl;

    return 0;
}