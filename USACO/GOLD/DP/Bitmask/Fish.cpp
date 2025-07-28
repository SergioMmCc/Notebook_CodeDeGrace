#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

ld strToLD(string s){
    int len = s.sz;
    ld pot10 = 1.0, ans = 0.0;

    for(int i = 0; i < len; i++){
        if(s[i] == '.') continue;
        int num = s[i] - '0';
        ans += (ld)num * pot10;
        pot10 /= 10.0;
    }

    return ans;
}

void solver(){
    int n; cin>>n;
    ld mat[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            string s; cin>>s;
            mat[i][j] = strToLD(s);
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<mat[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    int lim = 1 << n;
    vector<vector<ld>> dp(n, vector<ld>(lim, 0.0));
    for(int i = 0; i < n; i++) dp[i][1 << i] = 1.0;

    for(int mask = 1; mask < lim; mask++){
        int count = 0;
        for(int aux = 0; aux < n; aux++){
            if(mask & (1 << aux)) count++;
        }
        if(count == 1) continue;

        // cout<<"before -> "<<count;
        count *= count - 1; count /= 2;
        // cout<<" after -> "<<count<<endl<<endl;
        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) == 0) continue;

            for(int j = i + 1; j < n; j++){
                if((mask & (1 << j)) == 0) continue;

                for(int k = 0; k < n; k++){
                    dp[k][mask] += mat[i][j] * dp[k][mask ^ (1 << j)] / (ld)count;
                    dp[k][mask] += mat[j][i] * dp[k][mask ^ (1 << i)] / (ld)count;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<fixed<<setprecision(10)<<dp[i][lim-1];
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}