#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void solver() {
    vector<pii> drawn;
    int n, save, ans = 0, cl, cr, nl, nr;
    pii current, next;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin>>save;
        drawn.push_back({0, save});
    }
    for(int i = 0; i < n; i++) {
        cl = drawn[i].first; cr = drawn[i].second;
        if(cl == 0 && cr == 0)
            continue;
        if(cr - cl > 2 || i == n-1) {
            ans++,
            drawn[i] = {0, 0};
        }
        else {
            ans++;
            nl = drawn[i+1].first; nr = drawn[i+1].second;

            if(cr - cl == 1) {
                if(cl == 0)
                    cr++;
                else if(cr == n)
                    cl--;
                
                else {
                    if(nr == cr + 1)
                        cr++;
                    else if(nl == cl - 1)
                        cl--;
                    else
                        cr++;
                }
            }

            if(cr - cl == 2) {
                if(cl == nl)
                    nl += 2;
                else if(cl + 1 == nl)
                    nl += 1;
                
                if(cr == nr)
                    nr -= 2;
                else if(cr - 1 == nr)
                    nr -= 1;
            }

            drawn[i] = {0, 0};
            if(nl >= nr) {
                nl = nr = 0;
            }
            drawn[i+1] = {nl, nr};
        }
    }
    cout << ans << "\n";
}

int main () {
    int t; cin >> t;
    while(t--) {
        solver();
    }
    return 0;
}