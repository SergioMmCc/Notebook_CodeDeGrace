#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

map<int, vector<int>> a;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;cin>>n;
    
    set<int> cuttingRanges;
    cuttingRanges.insert(0);cuttingRanges.insert(n+1);
    map<int, set<int>> ranges;
    ranges[n].insert(0);
    
    for(int i = 1; i <= n; i++){
        int save;cin>>save;
        a[save].push_back(i);
    }
    
    ll ans = -1;
    int start, end;
    for(const auto& pair : a){
        int key = pair.first;
        const vector<int>& value = pair.second;
        
        map<int, set<int>>::iterator maxRange = --ranges.end();
        ll test = (ll)key * maxRange->first;
        if(test > ans){
            ans = test;
            start = *maxRange->second.begin();
            end = start + maxRange->first;
            start++;
        }
        else if(test == ans){
            if(*maxRange->second.begin() < start - 1){
                start = *maxRange->second.begin();
                end = start + maxRange->first;
                start++;
            }
        }
        
        for(int i : value){
            cuttingRanges.insert(i);
            set<int>::iterator it;
            it = cuttingRanges.find(i);
            int currentN = *it, prevN = *prev(it), nextN = *next(it);
            if(currentN - prevN > 1)
                ranges[currentN - prevN - 1].insert(prevN);
            if(nextN - currentN > 1)
                ranges[nextN - currentN - 1].insert(currentN);
            if(ranges[nextN - prevN - 1].size() == 1)
                ranges.erase(nextN - prevN - 1);
            else
                ranges[nextN - prevN - 1].erase(prevN);
        }
    }
    cout<<start<<' '<<end<<' '<<ans<<endl;
    
    return 0;
}