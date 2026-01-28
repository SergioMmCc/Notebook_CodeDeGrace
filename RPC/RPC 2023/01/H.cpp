#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<int>, int> node;
vector<node> tree(300000, make_pair(vector<int>(), 0));

int main () {
    int n, q, save, current, aux;
    scanf ("%d %d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf ("%d", &save);
        tree[save].first.push_back(i);
    }
    
    for (int i = n - 1; i >= 0; --i) {
        for(auto& child : tree[i].first) {
            if(tree[child].first.size() == 1)
                child = tree[child].first.front();
        }
    }
    
    while(q--) {
        current = 0;
        while(!tree[current].first.empty()) {
            aux = current;
            current = tree[current].first[tree[current].second];
            
            if(tree[aux].second == tree[aux].first.size()-1)
                tree[aux].second = 0;
            else
                tree[aux].second++;
        }
        
        printf ("%d\n", current);
    }
    
    return 0;
}