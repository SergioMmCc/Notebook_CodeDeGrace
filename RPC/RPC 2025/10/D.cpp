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

void solver(){
    int n, m; cin>>n>>m;
    vector<set<int>> cero(n);
    vector<string> mat(n);
    for(int i = 0; i < n; i++){
        cin>>mat[i];
        for(int j = 0; j < m; j++){
            if(mat[i][j] == '0') cero[i].insert(j);
        }
        cero[i].insert(m);
    }

    int ans = 0;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            int mini = m;
            for(int j = y; j < n; j++){
                auto it = cero[j].lower_bound(x);
                int ind = *it;
                if(ind == x) break;
                mini = min(mini, ind);

                // cout<<"x -> "<<x<<" y -> "<<y<<" j -> "<<j<<" ind -> "<<ind<<" mini -> "<<mini<<endl;
                ans = max(ans, (j - y + 1) * (mini - x));
            }
        }
    }

    cout<<ans<<endl;
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