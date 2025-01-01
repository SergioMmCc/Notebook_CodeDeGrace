#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

// Maximum Bipartite Matching
// Complexity: O(VE)
// Finds a maximum bipartite matching for two sets of
// size L and R.

// How to use:
// Set g[i][j] to 1 if element i of the Left set can
// be paired with element j of the Right set.
// Fill the table for all 0 <= i < L and 0 <= j < R.
// matchL[i] will contain i’s match in the Right set
// and matchR[j] will contain j’s match in the Left set.

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