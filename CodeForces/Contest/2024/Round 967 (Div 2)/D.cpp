#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

typedef pair<int, int> pii;

void solver(){
    int n;cin>>n;
    int len = 0;
    vector<bool> appear(n+1), used(n+1); used[0] = 1;
    vector<int> a(n+1), last(n+1);
    priority_queue<pii, vector<pii>, greater<pii>> range;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(!appear[a[i]]){
            len++,
            appear[a[i]] = 1;
        }
        last[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        if(last[i])
            range.push({last[i], i});
    }
    
    set<pii> odd; set<pii> even;
    vector<int> ans;
    int l = 1, r = 0, num = 0;
    for(int i = 1; i <= len; i++){
        while(!range.empty() && used[num]){
            int nextR = range.top().first;
            num = range.top().second;
            range.pop();
            for(int j = r + 1; j <= nextR; j++){
                if(used[a[j]])
                    continue;
                odd.insert({-a[j], j});
                even.insert({a[j], j});
            }
            r = nextR;
        }
        
        pii test;
        if(i % 2 == 1){
            test = *odd.begin();
            while(!odd.empty() && used[-test.first]){
                odd.erase(test);
                test = *odd.begin();
            }
            if(odd.empty()){
                l = r + 1;
                i--;
                continue;
            }
        }
        else{
            test = *even.begin();
            while(!even.empty() && used[test.first]){
                even.erase(test);
                test = *even.begin();
            }
            if(even.empty()){
                l = r + 1;
                i--;
                continue;
            }
        }
        test.first = abs(test.first);
        ans.pb(test.first);
        for(int j = l; j <= test.second; j++){
            odd.erase({-a[j], j});
            even.erase({a[j], j});
        }
        
        l = test.second + 1;
        used[test.first] = 1;
    }
    
    cout<<len<<endl;
    for(int i = 0; i < len - 1; i++)
        cout<<ans[i]<<' ';
    cout<<ans[len-1]<<endl;
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