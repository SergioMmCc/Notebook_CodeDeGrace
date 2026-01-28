#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n, k, save, maxN = 0, x;
    long long ans = 0, maxElements = 0, nRep;
    cin>>n>>k;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        cin>>save;
        maxN = max(maxN, save);
        a.push_back(save);
    }
    for(int i = 0; i < n; i++) {
        cin>>save;
        b.push_back(save);
        maxElements += (a[i]/b[i]);
        if(a[i]%b[i] != 0)
            maxElements++;
    }
    
    if(maxElements > k) {
        int l = 0, r = maxN, m;
        x = -1;
        long long fx, maxAproach = 0;
        while(l <= r) {
            fx = 0;
            m = (r + l) >> 1;
            for(int i = 0; i < n; i++) {
                if(m >= a[i])
                    continue;
                fx += (a[i]-m)/b[i];
                if((a[i]-m) % b[i] != 0)
                    fx++;
            }
            if(fx == k) {
                x = m;
                break;
            }
            else if(fx > k)
                l = m+1;
            else {
                if(maxAproach <= fx) {
                    nRep = m;
                    maxAproach = fx;
                }
                r = m-1;
            }
        }
        if(x == -1) {
            x = nRep;
            ans += (k - maxAproach)*x;
        }
    }
    else
        x = 0;

    long long limit;
    for(int i = 0; i < n; i++) {
        if(x >= a[i])
            continue;
        limit = (a[i]-x) / b[i];
        if((a[i]-x) % b[i] != 0)
            limit++;
        ans += (long long)a[i]*limit - (long long)b[i]*(limit*(limit-1))/2;
    }
    
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}