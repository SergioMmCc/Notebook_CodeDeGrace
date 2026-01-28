#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solver(){
    int n, m;
    cin>>n>>m;
    int biggest = 0;
    for(int i = 0; i < n; i++){
        int l;cin>>l;
        set<int> a;
        for(int j = 0; j < l; j++){
            int save;cin>>save;
            a.insert(save);
        }
        
        int test = -1;
        bool min1 = false, min2 = false;
        while(!min2){
            test++;
            if(a.find(test) == a.end()){
                if(!min1) min1 = true;
                else min2 = true;
            }
        }
        
        biggest = max(biggest, test);
    }
    
    int ans;
    if(biggest < m)
        ans = m * (m+1) / 2 + biggest * (biggest + 1) / 2;
    else ans = (m + 1) * biggest;
    
    cout<<ans<<endl;
}

#undef int
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}