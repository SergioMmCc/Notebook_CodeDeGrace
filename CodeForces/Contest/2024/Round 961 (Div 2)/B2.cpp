#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void solver() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    vector<pii> freq;
    int n, save;
    long long m, ans = 0, dif, left, add, saveMax, x, x1, cx, cx1, kx, kx1;
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>save;
        freq.push_back({save, 0});
    }
    for(int i = 0; i < n; i++) {
        cin>>save;
        freq[i].second = save;
    }
    sort(freq.begin(), freq.end());
    
    for(int i = 0; i < freq.size(); ++i) {
        x = freq[i].first; cx = freq[i].second;
        if(i < freq.size()-1 && freq[i].first == freq[i+1].first-1) {
            x1 = freq[i+1].first; cx1 = freq[i+1].second;
            kx = min(cx, m/x);
            left = m - x*kx;
            kx1 = min(cx1, left/x1);
            
            saveMax =  x*kx + x1*kx1;
            dif = m - saveMax;
            add = min(dif, min(kx, cx1 - kx1));
            saveMax += add;
        }
        
        else {
            kx = min(cx, m/x);
            saveMax = x*kx;
        }
        ans = max(ans, saveMax);
    }
    cout << ans << "\n";
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}