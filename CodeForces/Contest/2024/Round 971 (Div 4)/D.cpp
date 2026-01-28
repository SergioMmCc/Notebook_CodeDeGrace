#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    long long ans = 0;
    vector<pii> points(n);
    for(int i = 0; i < n; i++){
        int x, y;cin>>x>>y;
        points[i] = {x, y};
    }
    sort(points.begin(), points.end());
    
    for(int i = 0; i < n; i++){
        if(points[i].second == 0){
            if(i < n-1){
                if(points[i].first == points[i+1].first)
                    ans += (long long)n - 2;
            }
        }
        int j = -1;
        if(i < n-1 && points[i+1].first == points[i].first + 1 &&
        points[i].second != points[i+1].second)
            j = i+1;
        
        else if(i < n-2 && points[i+2].first == points[i].first + 1 && points[i].second != points[i+2].second)
            j = i+2;
        else if(i < n-3 && points[i+3].first == points[i].first + 1 && points[i].second != points[i+3].second)
            j = i+3;
        
        if(j != -1){
            int k = -1;
            if(j < n-1 && points[j+1].first == points[j].first + 1 && points[j].second != points[j+1].second)
                k = j + 1;
            else if(j < n-2 && points[j+2].first == points[j].first + 1 && points[j].second != points[j+2].second)
                k = j + 2;
            else if(j < n-3 && points[j+3].first == points[j].first + 1 && points[j].second != points[j+3].second)
                k = j + 3;
            
            if(k != -1)
                ans++;
        }
    }
    
    cout<<ans<<endl;
}


int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solver();
    }

    return 0;
}