// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)v.size())

typedef vector<int> vi;

const char ln = '\n';

void solve(){
    int n, k; cin >> n >> k;
    vector<string> types;

    for(int i = 0; i < n - k + 1; ++i){
        string wor; cin >> wor;
        types.push_back(wor);
    }

    vector<int> ans;

    vi vis(52, 0);

    for(int i = 0; i < k - 1; ++i){
        ans.push_back(i);
        vis[i] = 1;
    }

    for(int i = 0; i < n - k + 1; ++i){
        if (types[i] == "YES"){

            for(int j = 0; j < 52; ++j){
                if (vis[j] == 0){
                    ans.push_back(j);
                    vis[j] = 1;
                    break;
                }
            }

            int last = ans[sz(ans) - k];
            vis[last] = 0;

        }else{
            int last = ans[sz(ans) - k + 1];
            ans.push_back(last);
        }
    }

    for(int i = 0; i < sz(ans); ++i){
        
        if (ans[i] < 26){
            cout << 'A';
            cout << char('a' + ans[i]) << " ";
        }
        else{
            cout << "Aa";
            cout << char('a' + (ans[i] - 26)) << " ";
        }
    }
    cout << ln;
}

int main() {

    solve();

}
