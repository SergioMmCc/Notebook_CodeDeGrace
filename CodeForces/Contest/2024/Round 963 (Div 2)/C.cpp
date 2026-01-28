#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n, k;cin>>n>>k;
    vector<int> numbers(n+1);
    set<int> mods;
    int maxN = -1;
    for(int i = 1; i <= n; i++){
        int save;cin>>save;
        numbers[i] = save;
        maxN = max(maxN, save);
        if(save % (2*k) == 0)
            mods.insert(2*k);
        else
            mods.insert(save % (2*k));
    }
    
    bool cond = false;
    if(n == 1){
        cout<<numbers[1]<<endl;
        return;
    }
    
    for(set<int>::iterator it = mods.begin(); !cond && it != mods.end(); ++it){
        if(it == mods.begin()){
            set<int>::iterator it2 = mods.end();--it2;
            if(*it2 - *it < k)
                cond = true;
        }
        else{
            if(2*k - *it + *prev(it) < k)
                cond = true;
        }
    }
    if(!cond){
        cout<<"-1"<<endl;
        return;
    }
    int ans = maxN;
    for(int i = 1; i <= n; i++){
        if(numbers[i] == maxN)
            continue;
        int dif = (maxN - numbers[i]) / (2*k);
        int aux = numbers[i] + 2*k*dif;
        if(aux < maxN - k)
            ans = max(ans, aux + 2*k);
    }
    cout<<ans<<endl;
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