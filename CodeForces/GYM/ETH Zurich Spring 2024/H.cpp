#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

typedef pair<int, int> pii;

void solver(){
    int n, m, save; cin>>n>>m;
    vector<pii> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i].second;
    for(int i = 0; i < n; i++)
        cin>>a[i].first;
    
    int ans = 0;   
    sort(a.begin(), a.end());
    priority_queue<pii> origin;
    for(int i = 0; i < n; i++)
        origin.push(a[i]);
    
    int lo = 1, hi = n, mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        priority_queue<pii> test = origin;
        vector<int> freq(m+1);
        int last = 2e9;
        while(!test.empty() && last >= 0){
            int tipo = test.top().second, hour = test.top().first; test.pop();
            if(freq[tipo] == mid)
                continue;
            if(hour >= last)
                last--;
            else
                last = hour;
            if(last < 0)
                continue;
            freq[tipo]++;
        }
        
        bool cond = true;
        for(int i = 1; i <= m; i++){
            if(freq[i] < mid){
                cond = false;
                break;
            }
        }
        
        if(cond) {ans = mid; lo = mid + 1;}
        else hi = mid - 1;
    }
    
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}