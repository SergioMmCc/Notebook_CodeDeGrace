// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)v.size())

typedef vector<int> vi;

const char ln = '\n';

void solve(){
    int n, m; cin >> n >> m;

    bool okg = 0;
    for(int i = 0; i < m; ++i){

        set<int> unis;
        set<int> vis;

        int k; cin >> k;

        bool ok = 0;
        for(int j = 0; j < k; ++j){
            int val; cin >> val;

            if(vis.count(val)) continue;
            vis.insert(val);

            if (unis.count(abs(val))) ok = 1;
            
            unis.insert(abs(val));
        }

        if (!ok){
            okg = 1;
            break;
        }
    }

    cout << (okg ? "YES" : "NO") << ln;

}

int main() {

    solve();

}
