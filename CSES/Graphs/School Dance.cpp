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
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

// Maximum Bipartite Matching
// Complexity: O(VE)
// Finds a maximum bipartite matching for two sets of
// size L and R.

// How to use:
// Set g[i][j] to 1 if element i of the Left set can
// be paired with element j of the Right set.
// Fill the table for all 1 <= i <= L and 1 <= j <= R.
// matchL[i] will contain i’s match in the Right set
// and matchR[j] will contain j’s match in the Left set.

const int maxn = 501;
bool g[maxn][maxn], seen[maxn];
int L, R, matchL[maxn], matchR[maxn];

bool assign(int i){
    for(int j = 1; j <= R; ++j) if(g[i][j] && !seen[j]){
        seen[j] = 1;
        if(matchR[j] < 0 || assign(matchR[j])) return matchL[i] = j, matchR[j] = i, 1;
    }
    return 0;
}

int maxBipartiteMatching(){
    for(int i = 1; i <= L; ++i) matchL[i] = -1;
    for(int j = 1; j <= R; ++j) matchR[j] = -1;
    int ans = 0;
    for(int i = 1; i <= L; ++i){
        for(int j = 1; j <= R; ++j) seen[j] = 0; // or memset
        if(assign(i)) ans++;
    }
    return ans;
}

void solver(){
    int k; cin>>L>>R>>k;
    for(int i = 0; i < k; i++){
        int a, b; cin>>a>>b;
        g[a][b] = 1;
    }

    cout<<maxBipartiteMatching()<<endl;
    for(int i = 1; i <= L; i++){
        if(matchL[i] != -1)
            cout<<i<<' '<<matchL[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}