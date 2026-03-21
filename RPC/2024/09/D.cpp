#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

int const maxn = 5e5;

void solver(){
    int n, m, ans = 0;
    cin>>n>>m;
    vector<int> a(maxn);
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = n+1; i < maxn; i++)
        a[i] = -1;
    multiset<int> save;
    for(int i = 1; i <= m+1 && i <= n; i++)
        save.insert(a[i]);
        
    multiset<int>::iterator it = save.end(); --it;
    ans = *it - a[1];
    for(int i = 2; i <= n; i++){
        save.erase(a[i-1]);
        save.insert(a[i+m]);
        it = save.end(); --it;
        ans = max(ans, *it - a[i]);
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}