#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    int op = 0;
    vector<pii> ans;

    for(int i = 1; i <= n; i++){
        if(!a[i]){
            if(i == n){
                ans.pb({i - 1 - op, i - op});
                a[i] = 1;
            }
            else{
                ans.pb({i - op, i + 1 - op});
                a[i] = 1; a[i+1] = 1;
            }
            op++;
        }
    }

    ans.pb({1, n - op});
    op++;

    cout<<op<<endl;
    for(int i = 0; i < ans.sz; i++){
        cout<<ans[i].fi<<' '<<ans[i].se<<endl;
    }
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